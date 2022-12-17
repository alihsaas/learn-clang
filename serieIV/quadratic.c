#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double x1, x2;
    double discriminant;

// Read in the coefficients of the equation
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);
    printf("Enter the value of c: ");
    scanf("%lf", &c);

// Calculate the discriminant
    discriminant = b * b - 4 * a * c;

// Check if there are real solutions
    if (discriminant < 0) {
        printf("There are no real solutions.\n");
    } else if (discriminant == 0) {
        // There is one real solution
        x1 = -b / (2 * a);
        printf("There is one real solution: x = %lf\n", x1);
    } else {
        // There are two real solutions
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("There are two real solutions: x1 = %lf, x2 = %lf\n", x1, x2);
    }

    return 0;

}
