#include <stdio.h>

int main() {
  int num;
  do {
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num % 2 == 0) {
      printf("Output: Even\n");
      printf("-----------------\n");
    } else if(num % 2 != 0) {
      printf("Output: Odd\n");
      printf("-----------------\n");
    } else {
      printf("Bye...");
    }
  } while(num >= 0);
}