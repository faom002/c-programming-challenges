//challenge #1

// double d; 
// extern float f;


// void fun(void){

// }


// int main(void)
// {

// 	int x;

// 	static float f1; 

// 	register int y;

// 	return 0;
// }


// challenge #2

// #include <stdio.h>
// int sum(int num){

// 	static int num1;
	
// 	num1 += num;
	
// 	return num1; 


// }


// int main(int argc, char const *argv[])
// {
// 	printf("%d\n", sum(25));
// 	printf("%d\n", sum(15));
// 	printf("%d\n", sum(30));


// 	return 0;
// }


// challenge #3
#include <stdio.h>

extern int i;

extern void display(void){
	printf("%d", i+1);
}
