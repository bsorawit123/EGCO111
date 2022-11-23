#include <stdio.h>

int series(int);
int factorial(int);

int main() {
  int n;
  printf("Input: ");
  scanf("%d", &n);

  printf("The sum of the series is: %d", series(n));

  return 0;
}

int factorial(int n) {
  int sum = 1;
  for(int i = 2; i <= n; i++) {
    sum *= i;
  }
  return sum;
}

int series(int n) {
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += factorial(i) / i;
  }
  return sum;
}