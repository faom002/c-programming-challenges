#include <stdio.h>
#include <string.h>
void copy(char dst[], char src[]){
  // Code for copying a string goes here


  		while(*src != '\0')
  		{
  			
  			 *dst = *src;

  				src++;
  				dst++;
  		}
  		*dst = '\0';
}


int main()
{
  char srcString[] = "We promptly judged antique ivory buckles for the next prize!";
  			char dstString[] = "hello";



  				
  				copy(dstString,srcString);	


  		printf("%s\n", dstString);

	return 0;
}