#include <stddef.h>
#include <stdio.h>

// #include <stdbool.h>

int main()
{


	// bool b = 0;

	// int i; 

	double A[5] = {
	[2]= 9.0,
	[1] = 2.9,
	[0] =3.E+25,
	[3]= .00007,
	};


	for (size_t i = 0; i < 5; ++i)
	{
		if (i != 0)
		{
		printf("element %zu is %g, \tits square is %g\n", i, A[i],A[i]*A[i]);
			
		}
	}

	return 0;
}