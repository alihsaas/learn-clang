#include <stdio.h>
#include <math.h>

int main() {
  int lower_bound, upper_bound;

  printf("enter lower and upper bound: ");
  scanf("%d, %d", &lower_bound, &upper_bound);

  for (int num = lower_bound; num < upper_bound; num++) {
    int is_prime = 0;
    for (int i = 2; i < sqrt(num); i++) {
      if (num % i == 0) {
        is_prime = 1;
        break;
      }
    }
    if (is_prime == 0) {
      printf("%d is prime\n", num);
    }
  }

  return 0;
}
