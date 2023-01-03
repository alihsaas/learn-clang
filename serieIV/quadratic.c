// Calculate the roots of a quadratic equation.

#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    float x1, x2;
    int discriminant;

    // Read in the coefficients of the equation
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter the value of c: ");
    scanf("%d", &c);

    if (a != 0) {
        // Calculate the discriminant
        discriminant = b * b - 4 * a * c;

        // Check if there are real solutions
        if (discriminant < 0) {
            printf("There are no real solutions.\n");
        }
        else if (discriminant == 0) {
            // There is one real solution
            x1 = -b / (float)(2 * a);
            printf("There is one real solution: x = %lf\n", x1);
        }
        else {
            // There are two real solutions
            x1 = (-b + sqrt(discriminant)) / (float)(2 * a);
            x2 = (-b - sqrt(discriminant)) / (float)(2 * a);
            printf("There are two real solutions: x1 = %lf, x2 = %lf\n", x1, x2);
        }
    }
    else {
        if (b == 0) {
            if (c == 0) {
                printf("Infinite solutions");
            }
            else {
                printf("No Solutions");
            }
        }
        else {
            printf("x = %d/%d = %f\n", -c, b, -c / (float)b);
        }
    }

    return 0;
}
