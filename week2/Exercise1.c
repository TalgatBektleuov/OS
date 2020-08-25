#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {   
    int integer=INT_MAX;
    float f=FLT_MAX;
    double d=DBL_MAX;
    
    printf("Size of int is %ld", sizeof(int));
    printf("\n");
    printf("Its maximum value is %d", integer);
    printf("\n");
    printf("Size of float is %ld", sizeof(float));
    printf("\n");
    printf("Its maximum value is %.6f", f);
    printf("\n");
    printf("Size of double is %ld", sizeof(int));
    printf("\n");
    printf("Its maximum value is %f", d);
       


    return 0;
}

