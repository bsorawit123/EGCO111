#include <stdio.h>

int main() {
  // int *pa, a;

  // a = 2;
  // pa = &a;

  // printf("a  = %d, pa  = %p \n", a, pa);
  // printf("&a = %p, &pa = %p \n", &a, &pa);
  // printf("a  = %d, *pa = %d \n", a, *pa);
  // printf("*&pa  = %p, &*pa = %p \n", *&pa, &*pa);

  int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int *pa, *pb, i, temp;

  pa = a; //pa = &a[0]

  for(i = 0; i < 10; i++) {
    printf("%d ", *pa); // printf("%d ", *(pa++));
    pa++;
  }
  printf("\n");

  pa = &a[0];
  pb = &a[9];

  for(i = 0; i < (10/2); i++) {
    temp = *pa;
    *pa = *pb;
    *pb = temp;
    pa++;
    pb--;
  }

  pa = a;
  for(i = 0; i < 10; i++) {
    printf("%d ", *(pa++));
  }
  printf("\n");

  return 0;
}