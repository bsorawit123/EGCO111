#include <stdio.h>

int main() {
  // // scanf()
  // int a;
  // float b;
  // char c;
  // char d[20];

  // printf("Input an integer: ");
  // scanf("%d", &a);
  // printf("Input a floating point: ");
  // scanf("%f", &b);
  // printf("Input a character: ");
  // scanf(" %c", &c);
  // printf("Input a string: ");
  // scanf("%s", d);
  // printf("a = %d, b=%.2f, c=%c, d=%s", a, b, c, d);

  int y = 4;
  int x = 7;
  // x = ++y+5*6;

  // x = 3+2*(y--);
  x = (++y)+1;
  printf("%d", x);


  return 0;
}