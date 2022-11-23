#include <stdio.h>

int main() {
  struct test {
    char title;
    char hint;
  } ayo[6][5];

  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 5; j++) {
      ayo[i][j].title = '-';
      ayo[i][j].hint = '^';
    }
  }

  for(int i = 0; i < 6; i++) {
    printf("\n");
    for(int j = 0; j < 5; j++) {
      printf("%c ", ayo[i][j].title);
    }
    printf("\n");
    for(int j = 0; j < 5; j++) {
      printf("%c ", ayo[i][j].hint);
    }
    printf("\n");
  }
  
  return 0;
}