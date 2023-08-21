#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	
    int num = 0 ,sub = 0;
    int num1 = 0;

    float fnum = 0.0, fsub = 0.0;
    float fnum1 = 0.0;
    
    scanf("%d %d %f %f", &num, &num1, &fnum , &fnum1);
    sub = num;

    num += num1;


    sub -= num1;
    
    fsub = fnum;


    fnum += fnum1;


    fsub -= fnum1;

    printf("%d %d\n", num, sub);
    printf("%.1f %.1f\n", fnum, fsub);

    return 0;
}