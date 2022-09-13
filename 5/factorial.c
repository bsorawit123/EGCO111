#include <stdio.h>

int main() {
  int n, fact;
  printf("Input a number: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    fact *= i+1;
  }

  printf("%d! = %d", n, fact);

  return 0;
}