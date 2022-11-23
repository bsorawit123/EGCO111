#include <stdio.h>

int main() {
  FILE *fp1, *fp2, *fp;
  char file1[100], file2[100];

  printf("Input the 1st filename: ");
  scanf("%s", file1);
  printf("Input the 2nd filename: ");
  scanf("%s", file2);

  fp = fopen("mergefiles.txt", "w");
  fp1 = fopen(file1, "r");
  fp2 = fopen(file2, "r");

  char c1, c2;
  while(!feof(fp1)) {
    c1 = fgetc(fp1);
    if(c1 == EOF) break;
    fputc(c1, fp);
  }
  fputc('\n', fp);
  while(!feof(fp2)) {
    c2 = fgetc(fp2);
    if(c2 == EOF) break;
    fputc(c2, fp);
  }

  return 0;
}