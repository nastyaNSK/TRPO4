#include "geometry.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 30

void input(circle* f1, circle* f2, circle* f3)
{
    char figure1[n], figure2[n], figure3[n];
    char CorrectData1[n] = "circle";
    char CorrectData2[n] = "Circle";
    char CorrectData3[n] = "CIRCLE";

    printf("Input three figures: ");
    scanf("%s %s %s", figure1, figure2, figure3);

    if ((strcmp(figure1, CorrectData1) != 0
         && strcmp(figure1, CorrectData2) != 0
         && strcmp(figure1, CorrectData3) != 0)
        || (strcmp(figure2, CorrectData1) != 0
            && strcmp(figure2, CorrectData2) != 0
            && strcmp(figure2, CorrectData3) != 0)
        || (strcmp(figure3, CorrectData1) != 0
            && strcmp(figure3, CorrectData2) != 0
            && strcmp(figure3, CorrectData3) != 0)) {
        printf("Unknown figure\n");
        _Exit(0);
    }

    printf("Input the coordinates of the first figure: ");
    scanf("%lf %lf %lf", &f1->x, &f1->y, &f1->radius);

    printf("Input the coordinates of the second figure: ");
    scanf("%lf %lf %lf", &f2->x, &f2->y, &f2->radius);

    printf("Input the coordinates of the third figure: ");
    scanf("%lf %lf %lf", &f3->x, &f3->y, &f3->radius);

    if (f1->radius == 0) {
        printf("radius cannot be zero(1)\n");
        printf("Input the coordinates of the first figure: ");
        scanf("%lf %lf %lf", &f1->x, &f1->y, &f1->radius);
    }

    if (f2->radius == 0) {
        printf("radius cannot be zero(2)\n");
        printf("Input the coordinates of the second figure: ");
        scanf("%lf %lf %lf", &f2->x, &f2->y, &f2->radius);
    }

    if (f3->radius == 0) {
        printf("radius cannot be zero(3)\n");
        printf("Input the coordinates of the third figure: ");
        scanf("%lf %lf %lf", &f3->x, &f3->y, &f3->radius);
    }

    if (f1->radius < 0) {
        printf("radius cannot be negative(1)\n");
        printf("Input the coordinates of the first figure: ");
        scanf("%lf %lf %lf", &f1->x, &f1->y, &f1->radius);
    }

    if (f2->radius < 0) {
        printf("radius cannot be negative(2)\n");
        printf("Input the coordinates of the second figure: ");
        scanf("%lf %lf %lf", &f2->x, &f2->y, &f2->radius);
    }

    if (f3->radius < 0) {
        printf("radius cannot be negative(3)\n");
        printf("Input the coordinates of the third figure: ");
        scanf("%lf %lf %lf", &f3->x, &f3->y, &f3->radius);
    }
}

double area_calculation(circle* f)
{
    return f->area = M_PI * (f->radius) * (f->radius);
}

double perimeter_calculation(circle* f)
{
    return f->perimeter = 2 * M_PI * (f->radius);
}

int intersection_definition(circle* f1, circle* f2)
{
    double d; /*расстояние между центрами окружностей*/
    double a; /*расстояние от радиуса первой фигуры до точки пересечения всех
                 линий*/

    if (f1->x == f2->x && f1->y == f2->y)
        return 0; /*Окружности не пересекаются*/

    d = sqrt(pow(abs(f1->x - f2->x), 2) + pow(abs(f1->y - f2->y), 2));
    if (d > f1->radius + f2->radius)
        return 0;

    a = (f1->radius * f1->radius - f2->radius * f2->radius + d * d) / (d * 2);

    if (a == f1->radius) /*окружности соприкасаются*/
        return 0;
    else
        return 1; /*окружности пересекаются*/
}

void output(circle* f1, circle* f2, circle* f3)
{
    FILE* data = fopen("data.txt", "w");

    fprintf(data, "1. circle(%.1lf %.1lf, %.1lf)\n", f1->x, f1->y, f1->radius);
    fprintf(data, "\t perimeter = %lf\n", f1->perimeter);
    fprintf(data, "\t area = %lf\n", f1->area);
    fprintf(data, "\t intersects:\n");

    if (intersection_definition(f1, f2) > 0)
        fprintf(data, "2. circle\n");

    if (intersection_definition(f1, f3) > 0)
        fprintf(data, "3. circle\n");

    if (intersection_definition(f1, f2) == 0
        && intersection_definition(f1, f3) == 0)
        fprintf(data, "none\n");

    fprintf(data,
            "\n2. circle(%.1lf %.1lf, %.1lf)\n",
            f2->x,
            f2->y,
            f2->radius);
    fprintf(data, "\t perimeter = %lf\n", f2->perimeter);
    fprintf(data, "\t area = %lf\n", f2->area);
    fprintf(data, "\t intersects:\n");

    if (intersection_definition(f2, f1) > 0)
        fprintf(data, "1. circle\n");

    if (intersection_definition(f2, f3) > 0)
        fprintf(data, "3. circle\n");

    if (intersection_definition(f2, f1) == 0
        && intersection_definition(f2, f3) == 0)
        fprintf(data, "none\n");

    fprintf(data,
            "\n3. circle(%.1lf %.1lf, %.1lf)\n",
            f3->x,
            f3->y,
            f3->radius);
    fprintf(data, "\t perimeter = %lf\n", f3->perimeter);
    fprintf(data, "\t area = %lf\n", f3->area);
    fprintf(data, "\t intersects:\n");

    if (intersection_definition(f3, f1) > 0)
        fprintf(data, "1. circle\n");

    if (intersection_definition(f3, f2) > 0)
        fprintf(data, "2. circle\n");

    if (intersection_definition(f3, f1) == 0
        && intersection_definition(f3, f2) == 0)
        fprintf(data, "none\n");

    fclose(data);
}
