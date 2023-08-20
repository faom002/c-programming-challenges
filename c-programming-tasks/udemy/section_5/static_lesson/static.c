
#include <stdio.h>
static int fun (){ // this will retain the prevous count
	 int count = 0; 

	count++;

	return count;
}



int main(int argc, char const *argv[])
{

	int test = fun() + fun();
	printf("%d\n", test); // 1 here 
	printf("%d\n", fun()); // 2 here 

	return 0;
}