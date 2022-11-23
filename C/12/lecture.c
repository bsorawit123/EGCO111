#include <stdio.h>

int main() {
  FILE *p;
  char name[100];
  int age;
  if((p=fopen("MyLovelyFile.txt", "r")) == NULL) {
    printf("Fail! \n");
    return 1;
  }
  while(!feof(p)) {
    fscanf(p, "%s %d", name, &age);
    printf("Name = %-10s   Age = %d \n", name, age);
  }
  fclose(p);
  // FILE *fp;
  // if((fp=fopen("test.txt", "w")) == NULL) {
  //   printf("Fail to open the file.");
  //   return 1;
  // }

  // int age;
  // char *name;

  // fprintf(fp, "Hello File \n");
  // fprintf(fp, "Age = %d \n", 18);
  // float a = 7.5;
  // fprintf(fp, "a = %.1f \n", a);

  // fclose(fp);

  return 0;
}