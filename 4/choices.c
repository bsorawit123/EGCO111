#include <stdio.h>

int main() {
  printf("What is the color of banana?\n");
  printf("1.Red\n");
  printf("2.Pink\n");
  printf("3.Blue\n");
  printf("4.Yellow\n");
  printf("5.White\n");

  int choice;
  printf("Ans: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Wrong!");
      break;
    case 2:
      printf("Wrong!");
      break;
    case 3:
      printf("Wrong!");
      break;
    case 4:
      printf("Right!");
      break;
    case 5:
      printf("Wrong!");
      break;
    default:
      printf("Error");
  }

  return 0;
}