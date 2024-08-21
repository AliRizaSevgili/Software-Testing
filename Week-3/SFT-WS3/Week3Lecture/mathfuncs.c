#include <stdio.h>
#include "mathfuncs.h"


double square(double n)
{
    return n * n;
}

double cube(double n)
{
    return n * n * n;
}

int main()
{
    printf("Square: %lf\n", square(2));
    printf("Cube: %.2lf", cube(2));
    return 0;
}