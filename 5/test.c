#include <stdio.h>

int fact() {
  int n, fact;
  printf("Input a number: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    fact *= i+1;
  }

  printf("%d! = %d", n, fact);

  return 0;
}

int main() {
  int n, fact;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("Interger  Factorial\n");

  for(int i = n; i > 0; i--) {
    fact = 1;
    for(int j = 1; j <= i; j++) {
      fact *= j;
    }
    printf("%4d!        %d\n", i, fact);
  }

  return 0;
}