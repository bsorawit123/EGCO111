#include <stdio.h>

void add(int, int);
void subtract(int, int);
void multiply(int, int);
void divide(int, int);
void modulus(int, int);

int main() {
  int n1, n2, choice;
  printf("Enter your two numbers: ");
  scanf("%d %d", &n1, &n2);

  printf("  MENU \n");
  printf("    1. Add \n");
  printf("    2. Subtract \n");
  printf("    3. Multiply \n");
  printf("    4. Divide \n");
  printf("    5. Modulus \n");
  printf("    0. Quit \n");

  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add(n1, n2);
        break;      
      case 2:
        subtract(n1, n2);
        break;      
      case 3:
        multiply(n1, n2);
        break;      
      case 4:
        divide(n1, n2);
        break;      
      case 5:
        modulus(n1, n2);
        break;
    }
  } while(choice != 0);
  printf("End...");

  return 0;
}

void add(int a, int b) {
  printf("Result: %d \n", a + b);
}

void subtract(int a,  int b) {
  printf("Result: %d \n", a - b);
}

void multiply(int a, int b) {
  printf("Result: %d \n", a * b);
}

void divide(int a, int b) {
  if(b == 0) {
    printf("Error...\n");
  } else {
    printf("Result: %.2f \n", (float) a / b);
  }
}

void modulus(int a, int b) {
  if(b == 0) {
    printf("Error...\n");
  } else {
    printf("Result: %d \n", a % b);
  }
}