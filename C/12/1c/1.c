#include <stdio.h>

int main() {
  FILE *fp;
  if((fp=fopen("Table.txt", "w")) == NULL) {
    printf("Fail! \n");
    return 1;
  }

  for(int i = 2; i <= 12; i++) {
    for(int j = 1; j <= 12; j++) {
      fprintf(fp, "%d*%d = %d \n", i, j, i*j);
    }
    fprintf(fp, "----------\n");
  }
  fclose(fp);
}