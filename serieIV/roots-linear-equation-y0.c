// Write a C program to solve the following equation:
// a*x+b = 0 where x is the unknown, and a and b are real

#include <stdio.h>

int main()
{
  int a, b;

  printf("ENTER a, b (FORM: a, b)\n");
  scanf("%d, %d", &a, &b);
  
  if (a == 0) {
    if (b == 0) {
      printf("Infinite solutions");
    } else {
      printf("No Solutions");
    }
  } else {
    printf("x = %d/%d = %f\n", -b, a, -b/(float)a);
  }
}
