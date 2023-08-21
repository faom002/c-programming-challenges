#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    char ch;
    
    char s[200];
    
    scanf("%[^\n]%*c",&ch);
    
    printf("%c\n", ch);
    
    scanf("%[^\n]%*c", &s);

    printf("%s\n", s);
    
    
    
    return 0;
}