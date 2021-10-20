#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void quadraticEquation(double a, double b, double c);

int main(int argc, char const **argv) {

    if (argc < 4) {
        printf("Incorrect input data.\n");
        return 0;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    printf("A = %lf\n", a);
    printf("B = %lf\n", b);
    printf("C = %lf\n", c);

    quadraticEquation(a, b, c);

    return 0;
}

void quadraticEquation(double a, double b, double c) {

    double d, x1, x2;
    d = (b * b) - 4 * a * c;

    printf("D = %lf\n", d);

    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
    }
    if (d < 0) {
        printf("veshestvennyx korney net");
    }
    if (d == 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        printf("x1 = x2 = %f\n", x1);
    }
}
