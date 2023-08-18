#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// printing instruction for user
void menus(){
	
	printf("hello and welcome to shoppingmall\n");
	printf("press the numbers shown\n");
	printf("(1) mozarella cheese, (2) hot sauce, (3) pepper\n");
	printf("Availible left in stock\n");

}

int menuList(FILE *shopFile){
	// struct food items
	struct Items {
		double price[3];
		int piecesLeft[3];
	};



	// opening file aswell as making it ready for read and write
	shopFile = fopen("shoppingMenu.txt", "w+");

	// a char buffer for keeping our items in
	char buffer[500];

	// offset variable to keep track of elements inside buffer array 
	// numberOfPiecesLeft for extracting the pieces left from text shopping
	int offset = 0,  input = 0, i = 0, j = 0;

	int numberOfPiecesLeftExtracted[3], mozarella = 0,hotSauce = 0, pepper = 0;


	// a token for not inlcuding the price values
    char *token; 

		// declaring and instanciating a item1 from struct item 
		struct Items item1 = {{23.3,40.0,10.0}, {10,20,40} };

			// making length variable of piecesleft 
			int lenOfPiecesLeft = sizeof(item1.piecesLeft)/sizeof(int);


			// making length variable of price 
			int lenOfPrice = sizeof(item1.price)/sizeof(double);


			


			// looping through the length of price and length of piecesleft
			for (int i = 0; i < lenOfPiecesLeft && lenOfPrice; ++i)
			{
						// write data of lenght price and piecesleft and convert it to char to buffer 
				offset +=	sprintf(buffer + offset, "price: %.2lf$ piecesLeft: %d\n ", item1.price[i] , item1.piecesLeft[i]);

			}
		

	// checking if file exist
	if (shopFile == NULL)
	{
		printf("Error opening file");
		return 1;
	}

	// writing to file
	fwrite(buffer, strlen(buffer), 1, shopFile);

	//start form the beginning of file 
 	fseek(shopFile, 0, SEEK_SET);

    /* Read and display data */
    fread(buffer, strlen(buffer), 1, shopFile);

    // calling on menus function 
    menus();

    		// printing the availible menu from shopping txt
    		printf("%s\n", buffer);

    	// breaking the strings into token by space
    	token =  strtok(buffer, " ");

    	// loop as longs as it is not null
        while (token != NULL) {

        	
        	
        // reading the formated token only integers and searches for first occurrences such as (.) and not extract that
        if (sscanf(token, "%d", &numberOfPiecesLeftExtracted[i]) == 1 && strchr(token, '.') == NULL) {

	
        					if (numberOfPiecesLeftExtracted[i] == 10)
        					{
        						
        						mozarella = numberOfPiecesLeftExtracted[i];
		        						
        					}else if (numberOfPiecesLeftExtracted[i] == 20){
        						
        						hotSauce = numberOfPiecesLeftExtracted[i];

        					}else if (numberOfPiecesLeftExtracted[i] == 40) {
        						
        						pepper = numberOfPiecesLeftExtracted[i];

        					}


        	}



        // else token is null
        token = strtok(NULL, " ");

    }

    offset = 0;


    				while (scanf("%d", &input)) {
    					if (input == 1)
    					{

    						mozarella--;
    						printf("we still have %d mozarella: \n", mozarella);
    					
    					
    					}else if (input == 2)
    					{

    						hotSauce--;
    						
    						printf("we still have %d hotSauce:\n", hotSauce);
    						
    						

    					}else if (input == 3){

    						pepper--;
    						
    						printf("we still have %d pepper:\n", pepper);
    						
    					}

    					if (pepper <= 0 || hotSauce <= 0 || mozarella <= 0 )
    						{
								offset += sprintf(buffer + offset, "price: %.2lf$ piecesLeft: %d\n ", item1.price[j] , hotSauce);
								offset += sprintf(buffer + offset, "price: %.2lf$ piecesLeft: %d\n ", item1.price[j] , mozarella);
								offset += sprintf(buffer + offset, "price: %.2lf$ piecesLeft: %d\n ", item1.price[j] , pepper);
									printf("you have bought all of the items");
    							break;
    						}
    					
    				}

    						// writing to file
							fwrite(buffer, strlen(buffer) , 1, shopFile);

							//start form the beginning of file 
 							fseek(shopFile, 0, SEEK_CUR);

						    /* Read and display data */
						    fread(buffer, strlen(buffer), 1, shopFile);
    				
						
						    printf("%s", buffer);


    // close shooping file
	fclose(shopFile);

	return 0;
}



int main(void)
{
	// assign file pointer
	FILE *fp = NULL;

	// call on menu list and pass file pointer
	menuList(fp);

	return 0;
}


// tomorrow i need to try and figure out how I can make the buffer array dynamic