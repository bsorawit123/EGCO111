#include <stdio.h>

int main() {
  char fc;
  printf("Input a character: ");
  scanf("%c", &fc);

  if(fc == 's' || fc == 'S') {
    printf("My name is Sorawit.\n");
  }
  printf("Bye.");

  return 0;
}