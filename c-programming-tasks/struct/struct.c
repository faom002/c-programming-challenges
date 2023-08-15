#include <stdio.h>

struct Table{
	int length;
	int width;
	int height;
	char* color;
};


int main(void) {
  struct Person {
    char firstName[25];
    // Write your code below
    char lastName[40];
    int age;
  };
  
  // Write your code below
  struct Person person1 ={"Ada", "Lovelace", 28};
  struct Person person2 ={"Marie", "Curie", 44};

  int length =20;
  int width = 20;
  int height =20;
  char color[20] = "Brown"; 


  struct Table table1 = {length, width, height,color};



		  printf("%s\n", table1.color);
  		
}  