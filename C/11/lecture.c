#include <stdio.h>
#include <stdlib.h>

int main() {
  // struct templates {
  //   int number;
  //   float price; 
  // };

  // struct templates a;

  // printf("Size = %d \n", sizeof(a));

  // a.number = 15;
  // a.price = 7.9;

  // printf("%d, %.2f", a.number, a.price);

  typedef struct {
    double r;
    double c;
  } complex;

  complex a = {10.5, 5.5};
  complex *pa;
  pa = &a;

  printf("%lf %lf", pa->r, pa->c);

  return 0;
}