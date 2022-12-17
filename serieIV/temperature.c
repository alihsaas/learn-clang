// Write a C program to convert a temperature from Celsius to Fahrenheit 
// where water freezes at 32 and boils at 212.

#include <stdio.h>

int main()
{
  float celsius;

  scanf("%f", &celsius);

  printf("%f\n", (celsius * 9/5) + 32);
}
