#include <stdio.h>
#include <stdlib.h>
void usage(char * input){
	printf("Usage: %s <message> <# of times to repeat>\n", input);
	exit(1);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		usage(argv[0]);
	}

	for (int i = 1; i < argc; i++) {

			printf("printing: %s\n", argv[i]);		
	}
	return 0;
}