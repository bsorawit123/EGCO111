#include <stdio.h>
#include <stdlib.h>

int main() {
  int num;
  float *p, avg=0, temp;

  printf("Number of Student: ");
  scanf("%d", &num);

  p = (float *) malloc(num * sizeof(float));

  for(int i = 0; i < num; i++) {
    printf("Student %d = ", i+1);
    scanf("%f", (p+i));
    avg += *(p+i);
  }
  printf("Average Scroe of %d students is %.1f \n", num, avg/num);

  for(int i = 0; i < num; i++) {
    for(int j = i+1; j < num; j++) {
      if(*(p+i) > *(p+j)) {
        temp = *(p+i);
        *(p+i) = *(p+j);
        *(p+j) = temp;
      }
    }
  }

  for(int i = 0; i < num; i++) {
    printf("%.1f ", *(p+i));
  }

  free(p);

  return 0;
}