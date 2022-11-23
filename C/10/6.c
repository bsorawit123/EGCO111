#include <stdio.h>

int sum(int);

int main() {
  int n, count = 1;
  do { 
    printf("%d.Interger: ", count++);
    scanf("%d", &n);
    if(n != 0) printf("Result: %d \n", sum(n));
  } while(n != 0);
  printf("-------");
  return 0;
}

int sum(int n) {
  int result = 0;
  if(n > 0) {
    result += n + sum(n-1);
  }
  return result;
}