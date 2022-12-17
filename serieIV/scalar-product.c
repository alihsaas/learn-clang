// Write a C program to calculate the scalar product of 2 vectors

#include <stdio.h>

int main()
{
  int xA, yA, zA;
  int xB, yB, zB;

  printf("ENTER VECTOR A: x, y, z\n");
  scanf("%d,%d,%d", &xA, &yA, &zA);
  printf("ENTER VECTOR B: x, y, z\n");
  scanf("%d,%d,%d", &xB, &yB, &zB);

  int product = xA*xB + yA*yB + zA*zB;

  printf("SCALAR PRODUCT IS: vA.vB = %d*%d + %d*%d + %d*%d = %d\n", xA, xB, yA, yB, zA, zB, product);

  return 0;
}
