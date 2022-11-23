#include <stdio.h>

int rabbits(int);

int main() {
  int m;
  do {
    printf("Months = ");
    scanf("%d", &m);
    if(m >= 0) printf("Number Pairs of Rabbits = %d \n", rabbits(m));
    else printf("No answer! \n");
  } while(m != 0);
  printf("Bye");

  return 0;
}

int rabbits(int n) {
  int result = 0;
  if(n == 0 || n == 1) {
    result += 1;
  } else {
    result += rabbits(n-1) + rabbits(n-2);
  }
  return result;
}