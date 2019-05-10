#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>

#define n 30

int main()
{
    circle* memory = malloc(sizeof *memory);

    circle f1, f2, f3;

    if (memory == NULL)
        printf("memory allocation error\n");

    input(&f1, &f2, &f3);
    area_calculation(&f1);
    area_calculation(&f2);
    area_calculation(&f3);
    perimeter_calculation(&f1);
    perimeter_calculation(&f2);
    perimeter_calculation(&f3);
    output(&f1, &f2, &f3);

    return 0;
}



