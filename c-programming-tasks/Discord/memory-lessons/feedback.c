#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dynamic_array {
    char *data;
    size_t size;
    size_t capacity;
};

void dynamic_array_init(struct dynamic_array* array) {
    *array = (struct dynamic_array) {0}; // compound literal
    // or alternatively
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
    // arrow: a->b equivalent to (*a).b
}

void dynamic_array_free(struct dynamic_array* array) {
    free(array->data);
}

/* version 1: no form of error handling
void dynamic_array_append(struct dynamic_array* array, char element) {
    // checking to see if size is the same as cappacity
    if (array->size == array->capacity) {

        array->capacity = array->capacity == 0 ? 1 : array->capacity * 2;
            
        array->data = realloc(array->data, array->capacity * sizeof(char));
    }
        
    array[array->size++] = element;
}
*/

// problem: in the code above, if realloc fails, then we would leave the
// array in a state where the capacity is wrong, and the data is NULL
// Ideally, if reallocation fails, then the array should just stay unchanged

// C99 added _Bool as a keyword, and a convenience alias bool if you include <stdbool.h>
// C23 made bool a keyword as well

bool dynamic_array_append(struct dynamic_array* array, char element) {
    // checking to see if size is the same as cappacity
    if (array->size == array->capacity) {
        // don't change the capacity right away; just calculate how much we need
        int new_capacity = array->capacity == 0 ? 1 : array->capacity * 2;
        // realloc but don't change the data of the array yet
        char* new_data = realloc(array->data, new_capacity * sizeof(char))
        if (new_data == NULL) { // realloc has failed
            // printing and continuing would just silence the error,
            // and give the caller no way to handle it;
            // it would also mix program logic and user output, and these should
            // be separate in some way
            return false; // return false to indicate failure
        }

        array->capacity = new_capacity;
        array->data = new_data;
    }
    array[array->size++] = element;
    return true; // return true to indicate success
}


int main(void) {

    struct dynamic_array arr;
    dynamic_array_init(&arr);

    // dynamic_array_init would also work with an array on the heap
    // struct dynamic_array* heap_array = malloc(sizeof(struct dynamic_array));
    // dynamic_array_init(heap_array);

    // the input N length that we dont know about and can type as much as we want
    char input;

    // Assignment: instead of reading the data from a text file
    // - use fopen to open a file and assume that it's a binary file
    //   - tip: this involves the 'b' flag and 'r' flag for binary/read
    // - instead of reading the data to put into the array through scanf,
    //   use fread to read the bytes
    // - also change the solution that it works with int/float instead of char
    //   because char being just one byte large is making the task simpler than it needs to be
    // - tip: memcpy might also be of help

    // the while loop that loops as longs as input is not (1) so you can contiue typing
    while (scanf("%c", &input) && input != '1') {
        
        printf("%d\n", size);    
        printf("%d\n", capacity);   

        dynamic_array_append(&arr, input);
    }

    for (int i = 0; i < size; i++) {
        printf("%c", arr.data[i]);
    }
    printf("\n");

    dynamic_array_free(&arr);
    return 0;
}
