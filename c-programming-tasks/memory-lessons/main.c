#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void* malloc(size_t s);
// void free(void* ptr);

// if you forget to free => memory leak
// if you free too many times => double-free

// static: known at comile time, e.g. int[10]
// dynamic: known at run-time, e.g. malloc(x * sizeof(int))

int main(void)
{
    // N 1 8 2 3 38 93 0 0 9 10

    int n;
    scanf("%d", &n);

    // malloc returns a void* to n * 4 bytes of memory

    // int *ptr; // indeterminate pointer

    // here im saying that if the given N from scanf * sizeof int which is 4 bytes then point to this memory adress for 40 byte size.
    // it can  only store then 10 elements which because 40 / 4 (int bytesize)  
    char *arr = malloc(n * sizeof(char));
    // int arr[N];

        strcpy(arr, "jason");

    // int arr[3];  more or less equivalent to
    // int _0; int _1; int _2;

    
        arr = (char *)realloc(arr, 5);
        strcat(arr, ".com");


        // scanf("%d", arr + i);
        printf("%s\n", arr);

    // the arr is freed here
    free(arr);

    arr = NULL; 
}


 // if (!arr)
    // {

    // perror("Memory allocation failed");
    // exit(EXIT_FAILURE); // it failed the allocation

    // }