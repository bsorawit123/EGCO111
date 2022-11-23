#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp, *fp1;
  char str[100], *p;

  fp = fopen("data.txt", "w");
  fprintf(fp, "Do you have a problem?");

  fclose(fp);

  fp = fopen("data.txt", "r");
  fp1 = fopen("out.txt", "w");
  char i;
  while(1) {
    i = fgetc(fp);
    if(i == EOF) break;
    
    if(i == ' ') fputc('*', fp1);
    else fputc(i, fp1);
  }
  fclose(fp);
  fclose(fp1);
  return 0;
}