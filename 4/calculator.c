#include <stdio.h>

int main() {
  int a, b;
  char exp;
  printf("Expression: ");
  scanf("%d%c%d", &a, &exp, &b);

  switch (exp) {
    case '+':
      printf("%d%c%d = %d", a, exp, b, a+b);
      break;
    case '-':
      printf("%d%c%d = %d", a, exp, b, a-b);
      break;
    case '*':
      printf("%d%c%d = %d", a, exp, b, a*b);
      break;
    case '/':
      if(b == 0) {
        printf("%d%c%d no answer", a, exp, b);
        break;
      }
      printf("%d%c%d = %.2f", a, exp, b, (float)a/b);
      break;
    case '%':
      if(b == 0) {
        printf("%d%c%d no answer", a, exp, b);
        break;
      }
      printf("%d%c%d = %d", a, exp, b, a%b);
      break;
    default:
      printf("%d%c%d can\'t be calculated!", a, exp, b);
  }

  return 0;
}