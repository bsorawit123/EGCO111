#include<string.h>
#include<stdio.h>

int main() {
  int n, i, j;
  char st[10][20];
  char temp[50];
  char str[20];

  printf("Number of String: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    do {
      printf("String%d : ", i+1);
      fflush(stdin);
      scanf("%s", st[i]);
    } while(strlen(st[i]) != 5);
  }

  for(i = 0; i < n; i++) {
    for(j = i+1; j < n; j++) {
      if(strcmp(st[i],st[j])<0) {
        strcpy(temp,st[i]);
        strcpy(st[i],st[j]);
        strcpy(st[j],temp);
      }
    }
    strcat(str,st[i]);
  }

  printf("Concatenate = %s \n", str);
  printf("Selection = ");
  for(i = 0; i < strlen(str); i++) {
    if (i%3 == 0) printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}