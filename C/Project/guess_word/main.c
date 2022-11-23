#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct {
  char title;
  char guess;
  char answer;
  char hint;
  int check; // 0 = true, 1 = false
} results[6][5];

void clear() {
  system("clear"); // mac
  // system("cls"); // windows
}

void startGameName() {
  clear();
  printf("=====================\n");
  printf("\n   GUESS WORD GAME\n");
  printf("\n=====================\n");
}

void start_word() {
  clear();
  startGameName();
  // set before game start
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 5; j++) {
      results[i][j].title = '-';
      results[i][j].hint = ' ';
      results[i][j].check = 1;
    }
  }
  // print dash
  for(int i = 0; i < 6; i++) {
    printf("\n%6s", " ");
    for(int j = 0; j < 5; j++) {
      printf("%c ", results[i][j].title);
    }
    printf("\n%6s", " ");
    for(int j = 0; j < 5; j++) {
      printf("%c ", results[i][j].hint);
    }
  }
  printf("\n=====================\n");
}

void print_word(char *guess) {
  clear();
  startGameName();
  for(int i = 0; i < 6; i++) {
    printf("\n%6s", " ");
    for(int j = 0; j < 5; j++) {
      printf("%c ", results[i][j].title);
    }
    printf("\n%6s", " ");
    for(int j = 0; j < 5; j++) {
      printf("%c ", results[i][j].hint);
    }
  }
  printf("\n=====================\n");
}

void setResults(char answer[10], char guess[10], int count_game) {
  // set guess and answer after game start
  for(int i = 0; i < 5; i++) {
    results[count_game][i].guess = guess[i];
    results[count_game][i].answer = answer[i];
  }
}

int checkLines(char *filename) {
  FILE *fp = fopen(filename, "r");
  int line = 0, ch;
  if(fp == NULL) return 0;
  line++;
  while((ch = fgetc(fp)) != EOF) {
    if(ch == '\n') line++;
  }
  fclose(fp);
  return line;
}

int random_num(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

void random_word(char *filename, int lines, char answer[], char answer_text[]) {
  FILE *fp = fopen(filename, "r");
  char words[lines][1024], text[1024], *ans, *ans_txt;
  int random = random_num(0, lines-1);
  for(int i = 0; i < checkLines("words.txt"); i++) {
    fgets(words[i], 1024, fp);
  }
  fclose(fp);
  ans = strtok(words[random], "--");
  ans_txt = strtok(NULL, "--");
  strcpy(answer, ans);
  strcpy(answer_text, ans_txt);
}

void check_word(int count_game) {
  for(int i = 0; i < 5; i++) {
    if(results[count_game][i].answer == tolower(results[count_game][i].guess)) {
      results[count_game][i].title = toupper(results[count_game][i].guess);
      results[count_game][i].check = 0;
    } else {
      for(int j = 0; j < 5; j++) {
        results[count_game][i].title = tolower(results[count_game][i].guess);
        if(tolower(results[count_game][i].guess) == results[count_game][j].answer) {
          results[count_game][i].hint = '^';
        }
      }
    }
  }
}

int check_win(int count_game) {
  int check = 0;
  for(int i = 0; i < 5; i++) {
    if(results[count_game][i].check == 0) check++;
  }
  if(check == 5) return 0;
  return 1;
}

void win(char answer[], int count_game, int score) {
  // printf("======================\n");
  printf("\n       CORRECT\n");
  printf("       SCORE: %d\n", score);
  printf("\n=====================\n");
  printf("\n    Answer: %s\n", toupper(answer));
  printf("\n=====================");
}

void lose(char answer[], int score) {
  // clear();
  // printf("======================\n");
  printf("\n        WRONG\n");
  printf("       SCORE: %d\n", score);
  printf("\n=====================\n");
  printf("\n    Answer: %s\n", toupper(answer));
  printf("\n=====================");
}

void check_str(char answer_text[]) {
  char temp[strlen(answer_text)-1];
  for(int i = 0 ; i < strlen(answer_text)-1; i++) {
    if(answer_text[0] == '\n') {
      temp[i] = answer_text[i+1];
    }
    if(answer_text[strlen(answer_text)-1] == '\n') {
      temp[i] = answer_text[i];
    }
  }
  strcpy(answer_text, temp);
}

int check_category() {
  int choose;
  printf("\n   SELECT CATEGORY\n\n");
  printf("\n   1. %-12s\n", "CODING WORD");
  printf("\n   2. %-12s\n", "FREE WORD");
  printf("\n=====================\n");

  do {
    printf("\n      CHOOSE: ");
    scanf("%d", &choose);
    if(choose != 1 && choose != 2) printf("<< Enter only 1 and 2 >>\n");
  } while(choose != 1 && choose != 2);

  return choose;
}

int check_players() {
  int choose;
  clear();
  startGameName();
  printf("\n   >> 1 PLAYER  <<\n");
  printf("\n   >> 2 PLAYERS <<\n");
  printf("\n=====================\n");

  do {
    printf("\n      CHOOSE: ");
    scanf("%d", &choose);
    if(choose != 1 && choose != 2) printf("<< Enter only 1 and 2 >>\n");
  } while(choose != 1 && choose != 2);
  return choose;
}

void setNamePlayer(char player1[], char player2[]) {
  printf("\n  SET PLAYER NAME MAXIMUM 10 LETTERS\n");
  do {
    printf("\n  PLAYER 1: ");
    scanf("%s", player1);
    if(strlen(player1) > 6) printf("<< Name can't longer than 6 letters >>\n");
  } while(strlen(player1) > 6);
  do {
    printf("\n  PLAYER 2: ");
    scanf("%s", player2);
    if(strlen(player2) > 6) printf("<< Name can't longer than 6 letters >>\n");
  } while(strlen(player2) > 6);

  // Capitalize
  player1[0] = toupper(player1[0]);
  for(int i = 1; i < strlen(player1); i++) {
    player1[i] = tolower(player1[i]);
  }
  player2[0] = toupper(player2[0]);
  for(int i = 1; i < strlen(player2); i++) {
    player2[i] = tolower(player2[i]);
  }
}

void game(score) {
  srand(time(NULL));
  int lines = checkLines("words.txt");
  int count_game = 0;
  int players = check_players();
  char player1[7], player2[7];
  char guess[6];
  char answer[10], answer_text[1024];
  random_word("words.txt", lines, answer, answer_text);
  check_str(answer_text);

  startGameName();

  if(players == 2) setNamePlayer(player1, player2);

  if(players == 1 || players == 2) start_word();

  do {
    do {
      if(players ==  1) {
        printf("\n  Guess word: ");
      } else if(players == 2) {

        if(count_game % 2 == 0) {
          printf("%s guess: ", player1);
        } else {
          printf("%s guess: ", player2);
        }
      }
      scanf("%s", guess);
      if(strlen(guess) != 5) printf(" << only 5 letters >>\n");
    } while(strlen(guess) != 5);

    setResults(answer, guess, count_game);
    check_word(count_game);
    print_word(guess);
    
    if(check_win(count_game) == 0) {
      score++;
      win(answer, count_game, score);
      break;
    }

    count_game++;
  } while(count_game < 6);

  char check_defi[5];
  do {
    printf("DEFINATION? (y/n): ");
    scanf("%s", check_defi);
    if(tolower(check_defi) != "yes" && tolower(check_defi) != "y" && tolower(check_defi) != "no" && tolower(check_defi) != "n") {
      printf("<< Please type y or n >>\n");
    }
  } while(tolower(check_defi) != "yes" && tolower(check_defi) != "y" && tolower(check_defi) != "no" && tolower(check_defi) != "n");

  if(check_win(5) == 1 && count_game == 6) {
    lose(answer, score);
  }
}

int main() {
  int score = 0;
  game(score);

  // clear();
  // startGameName();

  return 0;
}