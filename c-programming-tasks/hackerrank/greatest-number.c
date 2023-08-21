#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four(int a, int b, int c, int d) {
    int max = a; // Assume a is the maximum initially

    if (b > max) {
        max = b; // Update max if b is greater
    }
    if (c > max) {
        max = c; // Update max if c is greater
    }
    if (d > max) {
        max = d; // Update max if d is greater
    }

    return max; // Return the maximum value among a, b, c, and d
}


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}