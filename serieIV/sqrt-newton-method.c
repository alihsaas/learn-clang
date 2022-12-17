// Evaluate the value of square root of positive real number using Newton's Method.

#include <stdio.h>
#include <math.h>

int main()
{
    float a;
    printf("Enter a positive number: ");
    scanf("%f", &a);

    float x0 = 1.0;
    float x1 = 0.5 * (a / x0 + x0);
    while (fabs(x1 - x0) > 1e-5) {
        x0 = x1;
        x1 = 0.5 * (a / x0 + x0);
    }

    printf("The square root of %f is %f\n", a, x1);

    return 0;
}
