#include <stdio.h>

int main() {
  int sum = 0;
  int i = 1;

  while(i <= 1000) {
    if(i % 2 != 0) {
      sum += i;
    }
    i++;
  } 

  
  printf("sum = %d", sum);

  return 0;
}