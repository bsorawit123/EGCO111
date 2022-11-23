#include <stdio.h>

void getinfo(float *, float *);
float calBmi(float, float);

int main() {
  float w, h;
  getinfo(&w, &h);
  printf("BMI = %.2f", calBmi(w, h));

  return 0;
}

void getinfo(float *w, float *h) {
  printf("w(kg): ");
  scanf("%f", w);
  printf("h(cm): ");
  scanf("%f", h);
}

float calBmi(float w, float h) {
  float bmi;
  h /= 100; // cm => m
  bmi = w / (h * h);
  return bmi;
}