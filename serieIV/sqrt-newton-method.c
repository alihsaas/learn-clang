#include <stdio.h>
#include <math.h>

double square_root(double a)
{
    double x0 = 1.0;
    double x1 = 0.5 * (a / x0 + x0);
    while (fabs(x1 - x0) > 1e-5) {
        x0 = x1;
        x1 = 0.5 * (a / x0 + x0);
    }
    return x1;
}

int main()
{
    double a;
    printf("Enter a positive number: ");
    scanf("%lf", &a);
    double sqrt_a = square_root(a);
    printf("The square root of %lf is %lf\n", a, sqrt_a);
    return 0;
}
