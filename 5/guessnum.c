#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, counter;
  int min = 0;
  int max = 99;

  // Random Number
  srand(time(NULL));
  num = rand() % 100;

  counter = 0;
  while (guess != num) {
    printf("Guess [%d-%d]: ", min, max);
    scanf("%d", &guess);

    if(min <= guess && guess <= max) {
      if(guess > num) {
        printf("---Less than %d---\n", guess);
        max = guess - 1;
      } else if(guess < num) {
        printf("---More than %d---\n", guess);
        min = guess + 1;
      } else if(guess == num) {
        printf("<<<Correct>>>\n");
        printf("It\'s correct in %d times. ^_^", counter);
      }
    } else {
      printf("No! Please choose a number in [%d-%d]\n", min, max);
    }
    counter++;
  }

  return 0;
}