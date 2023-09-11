    // Assignment: instead of reading the data from a text file
    // - use fopen to open a file and assume that it's a binary file
    //   - tip: this involves the 'b' flag and 'r' flag for binary/read
    // - instead of reading the data to put into the array through scanf,
    //   use fread to read the bytes
    // - also change the solution that it works with int/float instead of char
    //   because char being just one byte large is making the task simpler than it needs to be
    // - tip: memcpy might also be of help


    #include <stdio.h>
    #include <stdbool.h>

    bool reading_a_binary_file(FILE *file){
        

     file = fopen("newProgram.bin", "rb");
        
      if (file == NULL) {
        printf("")
      }
        
    }



    int main(void){
      
      return 0;

    }
  


