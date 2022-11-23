#include<stdio.h>
#include<string.h>

int main() {
  char str[50];
  int i, v;

  printf("Input the string : ");
  fflush(stdin);
  gets(str);
  
  printf("Reversed strig   :\n");
  for(i=strlen(str)-1; i>=0; i--) {
    printf("%c ", str[i]);
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
      v++;
    }
  }

  printf("\nNumber of charactor  : %d \n", strlen(str));
  printf("Number of vowels    : %d \n", v);
  
  return 0;
}