#include <stdio.h>

int main(){
  int setA[10] = {0};
  int setB[25] = {0};
  
  printf("enter A\n");
  for (int i = 0; i <= 9; i++) {
    scanf("%d", &setA[i]);
  }

  printf("enter B\n");
  for (int i = 0; i <= 24; i++) {
    scanf("%d", &setB[i]);
  }

  int is_not_subset = 0;
  for (int x = 0; x <= 9; x++) {
    int is_in_set = 0;
    for (int y = 0; y <= 24; y++) {
      if (setA[x] == setB[y]) {
        is_in_set = 1;
        break;
      }
    }
    if (is_in_set == 0) {
      is_not_subset = 1;
      break;
    }
  }

  printf("A is %ssubset of B", is_not_subset == 1 ? "not" : "");
}
