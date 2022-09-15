#include <stdio.h>

int main() {
  char name[20];
  int nson, acre, yd2, ft2, area, tArea, fArea, tPerson;
  printf("===============================\n");
  printf("Name: ");
  scanf("%s", name);
  printf("Number of Sons: ");
  scanf("%d", &nson);
  printf("Area(acre-yd2-ft2): ");
  scanf("%d-%d-%d", &acre, &yd2, &ft2);
  
  tArea = (acre*4840*9) + (yd2*9) + ft2;
  fArea = (tArea / nson) + (tArea % nson);

  tPerson = tArea / nson;

  
  printf("The First Son: %d-%d-%d\n", (fArea / 9) / 4840, (fArea / 9) % 4840, (fArea % 9) % 4840);
  printf("Other Son(s) : %d-%d-%d", (tPerson / 9) / 4840, (tPerson / 9) % 4840, (tPerson % 9) % 4840);
  printf("\n===============================");

  return 0;
}