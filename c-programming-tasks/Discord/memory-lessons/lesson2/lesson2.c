// Assignment: instead of reading the data from a text file
    // - use fopen to open a file and assume that it's a binary file
    //   - tip: this involves the 'b' flag and 'r' flag for binary/read
    // - instead of reading the data to put into the array through scanf,
    //   use fread to read the bytes
    // - also change the solution that it works with int/float instead of char
    //   because char being just one byte large is making the task simpler than it needs to be
    // - tip: memcpy might also be of help
    

    // assigment  completed for this month

    
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// writing to the binary file
bool write_binary_file() {

  // creating the file to write to using (wb)
    FILE *file = fopen("newProgram.bin", "wb");

    // checking for if the file exist 
    if (file == NULL) {
        perror("Error opening binary file for writing");
        return false;
    }


    // creating the array we want to write to file 
    int data[] = {1, 2, 3, 4, 5};

    // getting the length of the data
    size_t num_elements = sizeof(data) / sizeof(data[0]);

    // Write the binary data to the file
    size_t elements_written = fwrite(data, sizeof(data[0]), num_elements, file);

    // close the file
    fclose(file);


    // if the elements that is written is not the same as the length of num length then return false
    if (elements_written != num_elements) {
        printf("Error writing data to the binary file\n");
        return false;
    }



    // else return true because we have written the data as binary
    printf("Data written successfully to a binary file\n");


    return true;
}


bool read_binary_file() {
    
    FILE *file = fopen("newProgram.bin", "rb");

    if (file == NULL) {
        perror("Error opening binary file for reading");
        return false;
    }

    
    int data[5];
    
    size_t num_elements = sizeof(data) / sizeof(data[0]);

    // Read the binary data from the file
    size_t elements_read = fread(data, sizeof(data[0]), num_elements, file);

    fclose(file);

    if (elements_read != num_elements) {
        printf("Error reading data from the binary file\n");
        return false;
    }

    printf("Data read from binary file: ");
    
    for (size_t i = 0; i < num_elements; i++) {
        printf("%d ", data[i]);
    }
    
    printf("\n");

    return true;
}

int main(void) {

  // bool functions return values so we can use them in if statements

    if (write_binary_file()) {
    
        if (read_binary_file()) {
    
            printf("Binary file operations completed successfully.\n");
    
        } else {
    
            printf("Error reading from binary file.\n");
        }
  
    } else {
  
        printf("Error writing to binary file.\n");
  

    }

    return 0;
}
