#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char name[50];
  char *p;
  printf("Name: ");
  fflush(stdin);
  gets(name);
  
  p = name;
  printf("Output1: ");
  for(int i = 0; i < strlen(name); i++) {
    if(*p == ' ') {
      p++;
      *p = toupper(*p);
    } else if(i == 0) {
      *p = toupper(*p);
    } else {
      *p = tolower(*p);
    }
    printf("%c", *(p++));
  }
  printf("\n");

  printf("Output2: ");
  int last = strlen(name) - 1;
  p = &name[last];
  for(int i = 0; i < strlen(name); i++) {
    char al = toupper(*(p--));
    printf("%c", al);
  }

  return 0;
}