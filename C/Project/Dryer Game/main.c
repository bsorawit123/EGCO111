#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void game(int, int, int);
// void game_mode();
// void easy_mode();
// void medium_mode();
// void hard_mode();
void hint(int*, int, int);
char *random_clothing();
int random_number(int, int);
char *check(int, int, char*, int);

int main() {
  srand(time(NULL));
  game(3, 5, 5); // round, round_game, range_answer
  // game_mode();
  return 0;
}

void game(int round, int round_game, int range_answer) {
  printf("===== Dryer Game =====");
  int temp = round; // temp = store round value
  float score = 0;
  do {
    int guess_temp, guess_time, hints = 10;
    int check_time = 0, check_temp = 0;

    // random
    char *clothe_dry = random_clothing();
    int time_dry = random_number(1, 18) * 5; // random number between 5-90 ((1-18) * 5) (minutes)
    int temp_dry = random_number(20, 100); // random number between 20-100 (celcius)

    printf("\n-------------------------------\n");
    printf("How much temperature to dry a %s (celcius)? \n", clothe_dry);
    printf("How long to dry a %s (minutes)? \n", clothe_dry);

    round = temp; // reset round value
    do {
      
      if(round == 1) {
        printf("-------------------------------\n");
        if(check_temp == 1) {
          printf("Final guess Temperature: %d \n", guess_temp);
        } else {
          printf("Final guess Temperature: ");
          scanf("%d", &guess_temp);
        }
        if(check_time == 1) {
          printf("Final guess Time: %d \n", guess_time);
        } else {
          printf("Final guess Time: ");
          scanf("%d", &guess_time);
        }
      } else {
        printf("-------------------------------\n");
        if(check_temp == 1) {
          printf("Guess Temperature: %d \n", guess_temp);
        } else {
          printf("Guess Temperature: ");
          scanf("%d", &guess_temp);
        }
        if(check_time == 1) {
          printf("Guess Time: %d \n", guess_time);
        } else {
          printf("Guess Time: ");
          scanf("%d", &guess_time);
        }
      }

      char *ans_temp = check(guess_temp, temp_dry, "temp", range_answer);
      char *ans_time = check(guess_time, time_dry, "time", range_answer);

      
      if(strcmp(ans_temp, "correct") == 0 && strcmp(ans_time, "correct") == 0) {
        if(check_temp == 0) {
          score += 0.5;
          check_temp = 1;
        }
        if(check_time == 0) {
          score += 0.5;
          check_time = 1;
        }

        printf("Correct!\n");
        printf("Score %.1f", score);
      } else {
        if(check_temp == 0 && strcmp(ans_temp, "correct") == 0) {
          score += 0.5;
          check_temp = 1;
        } else if(check_time == 0 && strcmp(ans_time, "correct") == 0) {
          score += 0.5;
          check_time = 1;
        }
        
        printf("Score %.1f", score);
        if(round > 1) hint(&hints, time_dry, temp_dry);
        round--;
      }
      

      if(check_temp == 1 && check_time == 1) break;
    } while(round > 0);
    round_game--;
  } while(round_game > 0);
  printf("-------------------------------\n");
}

char *random_clothing() {
  char *clothings[21] = {"Sweater", "Dress", "Hoodies", "T-shirt", "Shorts", "Skirts", "Jeans", "Coat", "High heels", "Suit", "Cap", "Socks", "Shirt", "Scarf", "Swimsuit", "Gloves", "Jacket", "Long coat", "Tie", "Polo shirt", "Leather jackets"};
  int r = rand() % 21; // 0 - 20

  return clothings[r];
}

int random_number(int min, int max) {
  int r = (rand() % max - min + 1) + min; // random range min-max
  return r;
}

void hint(int *n, int time, int temp) {
  char choice;
  printf("\nDo you want hint (Y/N): ");
  scanf(" %c", &choice);

  if(tolower(choice) == 'y') {
    int t_choice, range_left, range_right;
    *n -= 1;

    do {
      printf("Time or Temperature \n");
      printf("  1.Temperature \n");
      printf("  2.Time \n");
      printf("Ans: ");
      scanf("%d", &t_choice);

      if(t_choice == 1) {
        range_left = random_number(10, 20);
        range_right = random_number(10, 20);
        if(temp-range_left < 0) {
          printf("Answer is in %d-%d \n", 0, temp+range_right);
        } else {
          printf("Answer is in %d-%d \n", temp-range_left, temp+range_right);
        }
      } else if(t_choice == 2) {
        range_left = random_number(1, 4) * 5;
        range_right = random_number(1, 4) * 5;
        if(time-range_left < 0) {
          printf("Answer is in %d-%d \n", 0, time+range_right);
        } else {
          printf("Answer is in %d-%d \n", time-range_left, time+range_right);
        }
      } else {
        printf("Please choose only 1 and 2 !!! \n");
      }
    } while(t_choice != 1 && t_choice != 2);

    printf("hints: %d \n", *n);
  }
}

char *check(int guess, int answer, char *type, int range) {
  if(strcmp(type, "temp") == 0 && abs(guess - answer) <= range) {
    return "correct";
  } else if(strcmp(type, "time") == 0 && guess == answer) {
    return "correct";
  }
  return "wrong";
}

// void game_mode() {
//   char mode;
//   printf("\nDifficult Mode (E(easy) / M(medium) / H(hard)): ");
//   scanf("%c", &mode);

//   switch(tolower(mode)) {
//     case 'e':
//       printf("E");
//       // easy_mode();
//       break;
//     case 'm':
//       printf("M");
//       // medium_mode();
//       break;
//     case 'h':
//       printf("H");
//       // hard_mode();
//       break;
//     default:
//       printf("Please choose only (E/M/H)");
//   }
// }

