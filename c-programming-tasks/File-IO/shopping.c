#include <stdio.h>
#include <string.h>


void menus(){
	
	printf("hello and welcome to shoppingmall\n");
	printf("press the numbers shown\n");
	printf("(1) mozarella cheese, (2) hot sauce, (3) pepper\n");
	printf("Availible left in stock\n");

}

int menuList(FILE *shopFile){
	
	struct Items {
		double price[3];
		int piecesLeft[3];
	};

	shopFile = fopen("shoppingMenu.txt", "w+");

	char buffer[200];
	int offset = 0, numberOfPiecesLeft = 0;
    char *token; 

		
		struct Items item1 = {{23.3,40.0,10.0}, {10,20,40} };

			int lenOfPiecesLeft = sizeof(item1.piecesLeft)/sizeof(int);
			int lenOfPrice = sizeof(item1.price)/sizeof(double);

			for (int i = 0; i < lenOfPiecesLeft && lenOfPrice; ++i)
			{
					
													
					offset +=	sprintf(buffer + offset, "price: %.2lf$ piecesLeft: %d\t\n ", item1.price[i] , item1.piecesLeft[i]);

			}
		

	if (shopFile == NULL)
	{
		printf("Error opening file");
		return 1;
	}

	fwrite(buffer, strlen(buffer) , 1, shopFile);

 	fseek(shopFile, 0, SEEK_SET);

    /* Read and display data */
    fread(buffer, strlen(buffer), 1, shopFile);

    menus();

    		printf("%s\n", buffer);

    token =  strtok(buffer, " ");
        while (token != NULL) {
        if (sscanf(token, "%d", &numberOfPiecesLeft) == 1 && strchr(token, '.') == NULL) {

            printf("Extracted integer: %d\n", numberOfPiecesLeft);
        }
        token = strtok(NULL, " ");
    }

	fclose(shopFile);

	return 0;
}



int main(void)
{
	FILE *fp = NULL;

	menuList(fp);

	return 0;
}


// we need to figure out how to update values to text 