#include <stdlib.h>
#include <stdio.h>
double pow(double x, double y){
    double res = 1;
    for (int i = 0; i < y; i++){
        res *= x;
    }
    return res;
}

double facktorial(double x){
    double sum = 1;
    for (int i = 1; i <= x; i++){
        sum *= i;
    }
    return sum;
}

double sinus(double x,double eps){
    double addendum = __DBL_MAX__;
    double sum = 0;
    int degree = 1;
    int i = 0;
    while (addendum >= eps){
        addendum = pow(x, degree) * pow(-1,i);
        printf("%lf\n", addendum);
        degree += 2;
        sum += addendum;
    }
    return sum;
}

double cosine(double x, double eps){
    double addendum = __DBL_MAX__;
    double sum = 0;
    int degree = 0;
    while (addendum >= eps){
        addendum = pow(x, degree);
        degree += 2;
        sum += addendum;
    }
    return sum;
}

