#include <stdio.h>

int main() {
  char name[10]; 
  char gender;
  int year;
  int age;

  printf("###################\n");
  printf("Name: ");
  scanf("%s", name);
  printf("Gender(M/F): ");
  scanf(" %c", &gender);
  printf("Birth year: ");
  scanf("%d", &year);
  
  age = 2022 - year;

  printf("###################\n");
  printf("%s is %d years.", name, age);
  printf("\n###################");
  
  return 0;
}