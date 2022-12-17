#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Declare variables
    double a, b, c, d, e, f;
    double x, y;

    // Get input from the user
    printf("Enter the values for a, b, c, d, e, and f: ");
    scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);

    // Calculate x and y using the formula
    x = (e*d - b*f) / (a*d - b*c);
    y = (a*f - e*c) / (a*d - b*c);

    // Print the results
    printf("x = %lf\n", x);
    printf("y = %lf\n", y);

    return 0;
}

