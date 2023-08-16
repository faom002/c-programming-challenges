#include <stdio.h>
#include <stdlib.h>

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

    int *ptr; // indeterminate pointer

    // here im saying that if the given N from scanf * sizeof int which is 4 then point to this memory adress for 40 byte size.
    // it can  only store then 10 elements which because 40 / 4 (int bytesize)  
    int *arr = malloc(n * sizeof(int));
    // int arr[N];

    // int arr[3];  more or less equivalent to
    // int _0; int _1; int _2;

    // Assignment:
    // Make this code work even if N isn't given, i.e. if you have to read the
    // inputs one by one, without knowing how many there are in advance.
    // Tip: this probably involves using realloc in addition to malloc

    for (int i = 0; i < n; ++i)
    {
        // scanf("%d", arr + i);
        scanf("%d", &arr[i]);
    }

    // the arr is freed here
    free(arr);
}