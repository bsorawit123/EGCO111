#include <stdio.h>

int main() {
  FILE *fp;
  int num, sum = 0;
  if((fp=fopen("result.txt", "w")) == NULL) {
    printf("Fail! \n");
    return 1;
  }

  scanf("%d", &num);
  do {
    fprintf(fp, "%d ", num);
    sum += num;
    scanf("%d", &num);
  } while(!feof(stdin));

  fprintf(fp, "\nsum=%d", sum);
  fclose(fp);
  
  fp = fopen("result.txt", "r");
  char cc;
  fscanf(fp, "%c", &cc);
  do {
    printf("%c", cc);
    fscanf(fp, "%c", &cc);
  } while(!feof(fp));

  fclose(fp);

  return 0;
}