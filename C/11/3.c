#include <stdio.h>
#include <math.h>

#define PI 3.142857

int main() {
  struct shape {
    int type; // 1, 2, 3
    union {
      struct {
        int length, height;
      } r;
      struct {
        int base, altitude;
      } t;
      struct {
        int radius;
      } c;
    } u;

    float area, peri;
  } s[100];
  
  printf("Type: 1=rectangle 2=right-triangle 3=circle \n");
  char next;
  int i = 0;

  do {
    printf("%d.Type: ", i+1);
    scanf("%d", &s[i].type);

    if(s[i].type == 1) {
      printf("Length: ");
      scanf("%d", &s[i].u.r.length);
      printf("Height: ");
      scanf("%d", &s[i].u.r.height);

      s[i].area = s[i].u.r.length * s[i].u.r.height;
      s[i].peri = 2*(s[i].u.r.length + s[i].u.r.height);
      
      printf("%-10s = %d \n", "Area", (int) s[i].area);
      printf("%-10s = %d \n", "Perimeter", (int) s[i].peri);
    } else if(s[i].type == 2) {
      printf("Base: ");
      scanf("%d", &s[i].u.t.base);
      printf("Altitude: ");
      scanf("%d", &s[i].u.t.altitude);

      s[i].area = (s[i].u.t.base * s[i].u.t.altitude) / 2.0;
      s[i].peri = (s[i].u.t.base + s[i].u.t.altitude) + sqrt(pow(s[i].u.t.base, 2) + pow(s[i].u.t.altitude, 2));

      printf("%-10s = %.1f \n", "Area", s[i].area);
      printf("%-10s = %.4f \n", "Perimeter", s[i].peri);
    } else if(s[i].type == 3) {
      printf("Radius: ");
      scanf("%d", &s[i].u.c.radius);

      s[i].area = PI * pow(s[i].u.c.radius, 2);
      s[i].peri = 2 * PI * s[i].u.c.radius;

      printf("%-10s = %.1f \n", "Area", s[i].area);
      printf("%-10s = %.4f \n", "Perimeter", s[i].peri);
    }
    i++;
    printf("Next? ");
    scanf(" %c", &next);
  } while(next == 'y' || next == 'Y');

  for(int j = 0; j < i; j++) {
    if(s[j].type == 1) {
      printf("%d. Rectangle(%d,%d) --> %d/%d \n", j+1, s[j].u.r.length, s[j].u.r.height, (int) s[j].area, (int) s[j].peri);
    } else if(s[j].type == 2) {
      printf("%d. RightTriangle(%d,%d) --> %.1f/%.1f \n", j+1, s[j].u.t.base, s[j].u.t.altitude, s[j].area, s[j].peri);
    } else if(s[j].type == 3) {
      printf("%d. Circle(%d) --> %.1f/%.1f \n", j+1, s[j].u.c.radius, s[j].area, s[j].peri);
    }
  }

  return 0;
}