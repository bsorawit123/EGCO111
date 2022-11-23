#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[100], *p;
  printf("Input: ");
  gets(str);
  int a = 0, e = 0, i = 0, o = 0, u = 0;

  p = str;
  for(int j = 0; j < strlen(str); j++) {
    switch (tolower(*(p++))) {
      case 'a':
        a++;
        break;
      case 'e':
        e++;
        break;
      case 'i':
        i++;
        break;
      case 'o':
        o++;
        break;
      case 'u':
        u++;
        break;
    }
  }

  printf("a => %d \n", a);
  printf("e => %d \n", e);
  printf("i => %d \n", i);
  printf("o => %d \n", o);
  printf("u => %d \n", u);
  return 0;
}