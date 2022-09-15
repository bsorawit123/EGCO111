#include <stdio.h>

int main() {
  int num;

  while(num != 0) {
    printf("Input: ");
    scanf("%d", &num);
    for(int i = 1; i <= num; i++) {
      if(i%5 == 1) printf("-->");
      printf("Happy ");
      if(i%5 == 0) printf("\n");
    }
    printf("\n");
  }

  return 0;
}