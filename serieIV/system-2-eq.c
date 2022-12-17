/* Solve the system of the 2 equations: 
ax + by = e
cx + dy = f
*/

#include <stdio.h>

int main() {
    // Declare variables
    int a, b, c, d, e, f;
    float x, y;

    // Get input from the user
    printf("Enter the values for a, b and e:\n");
    scanf("%d,%d,%d", &a, &b, &e);

    printf("Enter the values for c, d and f:\n");
    scanf("%d,%d,%d", &c, &d, &f);

    // Calculate x and y using the formula
    x = (e*d - b*f) / (float)(a*d - b*c);
    y = (a*f - e*c) / (float)(a*d - b*c);

    // Print the results
    printf("x = %f\n", x);
    printf("y = %f\n", y);

    return 0;
}

