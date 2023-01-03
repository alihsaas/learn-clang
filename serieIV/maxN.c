// Write a C program to find the max between N numbers given by the user.

#include <stdio.h>

int main()
{
  int number_of_inputs;

  printf("ENTER NUMBER OF NUMBERS TO COMPARE\n");
  scanf("%d", &number_of_inputs);

  float maximum;
  scanf("%f", &maximum);
  for (int i = 0; i < number_of_inputs; i++) {
    float input;
    scanf("%f", &input);
    if (input > maximum) maximum = input;
  }
  printf("Max is %f\n", maximum);

  return 0;
}
