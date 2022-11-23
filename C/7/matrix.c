#include <stdio.h>
#define ROW 3
#define COL 4

int main() {
  int matrix[ROW][COL], i, j;

  for(i = 0; i < ROW; i++) {
    for(j = 0; j < COL; j++) {
      printf("Matrix[%d][%d] : ", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
  }

  return 0;
}