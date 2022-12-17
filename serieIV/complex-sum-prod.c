// Write a C program to calculate the sum and the product of 2 complex numbers.

#include <stdio.h>

int main()
{
  int realA, imagA;
  int realB, imagB;

  printf("Enter complex number A (FORM a, b)\n");
  scanf("%d,%d", &realA, &imagA);
  printf("Enter complex number B (FORM a, b)\n");
  scanf("%d,%di", &realB, &imagB);

  printf("SUM Is: %d + %di\n", realA + realB, imagA + imagB);
  printf("PRODUCT Is: %d + %di\n", realA * realB, imagA * imagB);

  return 0;
}
