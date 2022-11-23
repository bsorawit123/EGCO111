#include<stdio.h>
#include<string.h>

int main() {
  char fruits[8][30] = {"orange", "banana", "mango", "apple", "cherry", "melon", "grape", "durain"};
  int i, j;
  char temp[30];
  for(i = 0; i < 8; i++) {
    printf("%s %d \n", fruits[i], strlen(fruits[i]));
  }

  for(i = 0; i < 8; i++) {
    for(j = i+1; j < 8; j++) {
      if(strcmp(fruits[i], fruits[j]) > 0) {
        strcpy(temp, fruits[i]);
        strcpy(fruits[i], fruits[j]);
        strcpy(fruits[j], temp);
      }
    }
    printf("%s ", fruits[i]);
  }
    printf("\n");
    
    return 0;
}