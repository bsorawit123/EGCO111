#include <stdio.h>
#include <stdlib.h>

int *getInput(char, int*);
void sortData(int, int, int*, int*);

int main() {
  int a_size, b_size;
  
  int *a = getInput('A', &a_size);
  int *b = getInput('B', &b_size);

  sortData(a_size, b_size, a, b);
  return 0;
}

int *getInput(char c, int *size) {
  int *p;
  printf("Input %c: Size = ", c);
  scanf("%d", size);

  p = (int *) malloc(*size * sizeof(float));
  for(int i = 0; i < *size; i++) {
    printf("%c%d: ", c, i+1);
    scanf("%d", (p+i));
  }
  return p;
}

void sortData(int a_size, int b_size, int *a, int *b) {
  printf("Before Sorting...");
  printf("\n  A: ");
  for(int i = 0; i < a_size; i++) {
    printf("%d ", *(a + i));
  }
  printf("\n  B: ");
  for(int i = 0; i < b_size; i++) {
    printf("%d ", *(b + i));
  }

  printf("\nAfter Sorting...");
  int temp;
  for(int i = 0; i < a_size; i++) {
    for(int j = 0; j < a_size; j++) {
      if(*(a+i) < *(a+j)) {
        temp = *(a+i);
        *(a+i) = *(a+j);
        *(a+j) = temp;
      }
    }
  }

  for(int i = 0; i < b_size; i++) {
    for(int j = 0; j < b_size; j++) {
      if(*(b+i) < *(b+j)) {
        temp = *(b+i);
        *(b+i) = *(b+j);
        *(b+j) = temp;
      }
    }
  }

  printf("\n  A: ");
  for(int i = 0; i < a_size; i++) {
    printf("%d ", *(a + i));
  }
  printf("\n  B: ");
  for(int i = 0; i < b_size; i++) {
    printf("%d ", *(b + i));
  }
}
