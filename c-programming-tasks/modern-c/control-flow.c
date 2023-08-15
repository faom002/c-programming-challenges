#include <stdio.h>
int main()
{

	char arg;

	scanf("%c", &arg);

	switch (arg) {
	case 'x': puts("this_is_xenia");
		break;
	case 'h': puts("yes th");
		break;
	default: puts("hello there");
		break;
	}



	return 0;
}