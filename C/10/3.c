#include <stdio.h>
#include <math.h>
char check(int n) {
  if(n % 2 == 0) return '#';
  return '*';
}
int stairs(int n, char s) {
  int counter = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) printf("%c", s);
    printf("\n");
    counter += i;
  }
  return counter;
}
int factorial(int n) {
  int sum = 1;
  for(int i = 2; i <= n; i++) sum *= i;
  printf("Factorial(%d) = %d \n", n, sum);
  return sum;
}
float divide(int a, int b) {
  return (float)a / b;
} 
void main() {
  int n1, n2, c1, c2;
  printf("Integer1: ");
  scanf("%d", &n1);
  printf("Integer2: ");
  scanf("%d", &n2);
  c1 = stairs(n1, check(n1));
  c2 = stairs(n2, check(n2));
  printf("%d ---> We have %d %c \n", n1, c1, check(n1));
  printf("%d ---> We have %d %c \n", n2, c2, check(n2));
  factorial(n1);
  factorial(n2);
  printf("A/B = %.2f \n", divide(n1, n2));
  printf("Ceil(A/B) = %.2f \n", ceil(divide(n1, n2)));
  printf("Floor(A/B) = %.2f \n", floor(divide(n1, n2)));
}