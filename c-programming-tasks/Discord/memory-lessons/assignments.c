// Assignment:  
    // Make this code work even if N isn't given, i.e. if you have to read the
    // inputs one by one, without knowing how many there are in advance.
    // Tip: this probably involves using realloc in addition to malloc


#include <stdio.h>
#include <stdlib.h>

int main() {
    // arr pointer initilized to null first
    char *arr = NULL;
    // int size to keep track of number of elements that have been read for the array
    int size = 0;

    // capacity the maximum number that the array can hold (size)
    int capacity = 0;

    // the input N length that we dont know about and can type as much as we want
    char input;

    // the while loop that loops as longs as input is not (1) so you can contiue typing
    while (scanf("%c", &input) && input != '1') {
        
        printf("%d\n", size);    
            printf("%d\n", capacity);   

        // checking to see if size is the same as cappacity
        if (size == capacity) {

            capacity = capacity == 0 ? 1 : capacity * 2;
             
            arr = realloc(arr, capacity * sizeof(char));
        }
            
        arr[size++] = input;
    }

    for (int i = 0; i < size; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
