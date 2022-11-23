#include <stdio.h>

int plus(int *num) {
  *num += 1;
  return 0;
}

int main() {
  int a = 10;
  printf("A: %d \n", a);
  plus(&a);
  printf("A: %d \n", a);

  return 0;
}