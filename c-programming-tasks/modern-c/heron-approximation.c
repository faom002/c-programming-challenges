#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    // _Bool check = 1;
    // double const eps = 1E-9; // Desired precision
    char a[] = "34.0";
    // double x = 0.5;
    char* ptr;
    double ret;

    ret = strtod(a, &ptr);   

        printf("%.2lf", ret);

    /*

            the while method
        with a bool value = true

    */

    // while (check) { // Iterates until close
    //     double prod = a*x;

    //     if (fabs(1.0 - prod) < eps)
    //     {
    //         break;
    //     }

    //     x *= (2.0 - prod);


    // }




    /*

    the for loop method
        with ;; = true

    */

    // for (;;) { // Iterates until close

    
    //     double prod = ret*x;

    //     if (fabs(1.0 - prod) < eps)
    //     {
    //         break;
    //     }

    //     x *= (2.0 - prod);


    // }


    // printf("Square root of %.2f: %.9f\n", a, x);


    /*

    the do while method

    ! note this will iterate through ones even if the condition is met

    */
    // do {
    // x *= (2.0 - a*x);
    // }while (fabs(1.0 - a*x) >=eps);


    return 0;
}
