#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {   
    int integer=INT_MAX;
    float f=FLT_MAX;
    double d=DBL_MAX;
    
    printf("Size of int is %lu", sizeof(int));
    printf("\n");
    printf("Its maximum value is %d", integer);
    printf("\n");
    printf("Size of float is %lu", sizeof(float));
    printf("\n");
    printf("Its maximum value is %.2f", f);
    printf("\n");
    printf("Size of double is %lu", sizeof(int));
    printf("\n");
    printf("Its maximum value is %lf", d);
       


    return 0;
}

