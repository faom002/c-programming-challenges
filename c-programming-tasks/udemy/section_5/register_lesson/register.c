// it can store a variable in register
#include <stdio.h>

	//register int x = 10; it cannot be used in global scope

int main(int argc, char const *argv[])
{
	// register int x; // register vairable 


	// int *a = &x; // this will not work because the x is already registered
	
	 int x; // vairable without registewring the address

	 // this will work
	 register int *a = &x;


	 // register static int *a = &x; this will not work becuase static and register dont work together

	for (x = 0; x <=15; ++x)
	{
		printf("%d\n", *a);
	}
	return 0;
}