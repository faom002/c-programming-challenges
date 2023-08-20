#include <stddef.h>
#include <stdio.h>


int main()
{
	
	size_t size = 0;

	printf("Enter the number of elements you want to store:\n");
	scanf("%zd", &size);
	
		float values[size];


		int len = sizeof(values)/sizeof(float);



		for (int i = 0; i < len; ++i)
		{
			scanf("%f\n", &values[i]);
		}


		 printf("Values stored in the array:\n");
    for (int i = 0; i < len; ++i)
    {
        printf("%f\n", values[i]);
    }


	return 0;
}
