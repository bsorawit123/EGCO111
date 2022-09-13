#include <stdio.h>

int main() {
  float weight, height;
  printf("Enter weight(kg): ");
  scanf("%f", &weight);
  printf("Enter height(cm): ");
  scanf("%f", &height);
  float mHeight = height / 100;
  float bmi = weight / (mHeight*mHeight);

  if(bmi < 18.5) {
    printf("Underweight");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("Normal weight");
  } else if (bmi >= 25 && bmi <= 29.9) {
    printf("Overweight");
  } else {
    printf("Obesity");
  }

  return 0;
}