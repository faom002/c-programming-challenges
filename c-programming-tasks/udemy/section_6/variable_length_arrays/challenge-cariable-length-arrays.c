#include <stddef.h>
#include <stdio.h>


int main()
{
	
	size_t size = 0;

	printf("Enter the number of elements you want to store:\n");
	scanf("%zd", &size);
	
		int values[size];


		int len = sizeof(values)/sizeof(int);



		for (int i = 0; i < len; ++i)
		{
			
			scanf("%d\n", &values[i]);

		}


		int sum = 0;



		 printf("Values stored in the array:\n");
		 
		    for (int i = 0; i < len; ++i)
		    {
		    	sum += values[i];

		        printf("%d\n", values[i]);
		    }

		    printf("the total sum of elements int the array is %d  :", sum);


	return 0;
}
