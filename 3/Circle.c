#include <stdio.h>

int main() {
  int width, length, radius, wcircle, lcircle, result;
  printf("Width: ");
  scanf("%d", &width);
  printf("Length: ");
  scanf("%d", &length);
  printf("Radius: ");
  scanf("%d", &radius);

  wcircle = width / (radius*2);
  lcircle = length / (radius*2);
  result = wcircle * lcircle;

  printf("Number of circles: %d", result);

}