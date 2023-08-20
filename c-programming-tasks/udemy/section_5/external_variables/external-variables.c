
#include <stdio.h>

int i = 5;

extern void foo(void);

int main(void)
{

	printf("before: %i\n", i);
	foo();
	printf("after: %i\n", i);
	return 0;
}