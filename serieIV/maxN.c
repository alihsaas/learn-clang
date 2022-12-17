// Write a C program to find the max between N numbers given by the user.

#include <stdio.h>

int main()
{
  int number_of_inputs;

  printf("ENTER NUMBER OF NUMBERS TO COMPARE\n");
  scanf("%d", &number_of_inputs);

  int maximum = 0;
  for (int i = 0; i < number_of_inputs; i++) {
    int input;
    scanf("%d", &input);
    if (input > maximum) maximum = input;
  }
  printf("Max is %d\n", maximum);

  return 0;
}
