#include <stdio.h>

int main() {
  int a, b, c;
  printf("Input a: ");
  scanf("%d", &a);
  printf("Input b: ");
  scanf("%d", &b);
  printf("Input c: ");
  scanf("%d", &c);

  if(a <= b && a <= c) printf("Min is %d", a);
  else if(b <= a && b <= c) printf("Min is %d", b);
  else if(c <= b && c <= a) printf("Min is %d", c);
}

