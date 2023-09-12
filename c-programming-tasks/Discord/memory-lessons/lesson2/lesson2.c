    // Assignment: instead of reading the data from a text file
    // - use fopen to open a file and assume that it's a binary file
    //   - tip: this involves the 'b' flag and 'r' flag for binary/read
    // - instead of reading the data to put into the array through scanf,
    //   use fread to read the bytes
    // - also change the solution that it works with int/float instead of char
    //   because char being just one byte large is making the task simpler than it needs to be
    // - tip: memcpy might also be of help


    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>
   

    bool write_a_binary_file(FILE *file){


     file = fopen("newProgram.bin", "wb");
        
      if (file == NULL) {
        perror("Error opening binary file");
        return false;
      }
        
          int data[] = {1,2,3,4,5};
          
          /* 
           the first argument is the data we want to write to the binary file
           The second argument, sizeof(int), specifies the size of each individual element in the data array that you want to             write to the binary file. It indicates how many bytes should be written for each element. In this case, it assumes             that each element in the data array is of type int and is 4 bytes in size, which is common on many systems.
           */

          size_t element_written = fwrite(data,sizeof(int), sizeof(data)/sizeof(int), file );


          if (element_written != sizeof(data)/ sizeof(int)) {
          return false;
          }

      
          fclose(file);
          
          printf("written successfully to a binary file\n");

      return true;

    }



    int main(void){
      
      FILE *file = NULL;
      


      write_a_binary_file(file); 



      return 0;

    }
  
