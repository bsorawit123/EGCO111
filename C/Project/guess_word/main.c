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
  int check; // 0 = false, 1 = true
} results[6][5];

struct {
  char name[7];
  int score;
} player1, player2;

void clear() {
  system("clear"); // mac
  // system("cls"); // windows
}

void startGameName(int *n) {
  clear();
  printf("=====================\n");
  printf("\n   GUESS WORD GAME");
  printf("\n      GAME : %d\n", *n);
  printf("\n=====================\n");
}

void start_word(int *n) {
  clear();
  startGameName(n);
  // set before game start
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 5; j++) {
      results[i][j].title = '-';
      results[i][j].hint = ' ';
      results[i][j].check = 0;
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

void print_word(char *guess, int *n) {
  clear();
  startGameName(n);
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
      results[count_game][i].check = 1;
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
    if(results[count_game][i].check == 1) check++;
  }
  if(check == 5) return 1;
  return 0;
}

void win_lose(char answer[], int count_game, char type[], int *players) {
  if(strcmp(type, "win") == 0) {
    printf("\n      CORRECT!\n");
  } else {
    printf("\n       WRONG!\n");
  } 

  if(*players == 1) {
    printf(" %6s's SCORE: %d\n", player1.name, player1.score);
  } else if(*players == 2) {
    printf(" %6s's SCORE: %d\n", player1.name, player1.score);
    printf(" %6s's SCORE: %d\n", player2.name, player2.score);
  }

  printf("\n=====================\n");
  printf("\n    ANSWER : %s\n", answer);
  printf("\n=====================\n");
}

void check_str(char answer_text[]) {
  char temp[strlen(answer_text)-1];
  for(int i = 0 ; i < strlen(answer_text)-1; i++) {
    // if(answer_text[0] == '\n') {
    //   temp[i] = answer_text[i+1];
    // }
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
    fflush(stdin);
    scanf("%d", &choose);
    if(choose != 1 && choose != 2) printf("\n<< Enter only 1 and 2 >>\n");
  } while(choose != 1 && choose != 2);

  return choose;
}

int check_players(int *n) {
  int choose;
  int check = 0;
  clear();
  startGameName(n);
  printf("\n   >> 1 PLAYER  <<\n");
  printf("\n   >> 2 PLAYERS <<\n");
  printf("\n=====================\n");

  do {
    printf("\n      CHOOSE: ");
    fflush(stdin);
    check = scanf("%d", &choose);
    while(check != 1) {
      printf("\n  << ONLY 1 AND 2 >>\n");
      fflush(stdin);
      printf("\n      CHOOSE: ");
      check = scanf("%d", &choose);
    }
    if(choose != 1 && choose != 2) printf("\n  << ONLY 1 AND 2 >>\n");
  } while(choose != 1 && choose != 2);
  return choose;
}

void setNamePlayer(char player1[], char player2[], int *players) {
  printf("\n=====================\n");
  printf("\n ENTER NAME (MAX: 6)\n");
  fflush(stdin);
  if(*players == 1) {
    do {
      printf("\n  PLAYER: ");
      scanf("%s", player1);
      if(strlen(player1) > 6) printf("\n<< Name can't longer than 6 letters >>\n");
    } while(strlen(player1) > 6);
  } else if(*players == 2) {
    do {
      printf("\n  PLAYER 1: ");
      scanf("%s", player1);
      if(strlen(player1) > 6) printf("\n<< Name can't longer than 6 letters >>\n");
    } while(strlen(player1) > 6);
    do {
      printf("\n  PLAYER 2: ");
      scanf("%s", player2);
      if(strlen(player2) > 6) printf("\n<< Name can't longer than 6 letters >>\n");
    } while(strlen(player2) > 6);
  }
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

void print_defi(char answer[], char answer_txt[], int *players) {
  char next;
  printf("\n%s : %s\n\n", answer, answer_txt);
  if(*players == 2) {
    printf("TYPE \'Y\' TO CONTINUE : ");
    fflush(stdin);
    scanf(" %c", &next);
  }
}

void game(int *players, int *n) {
  srand(time(NULL));
  int lines = checkLines("words.txt");
  int count_game = 0;
  char guess[6];
  char answer[10], answer_text[1024];
  random_word("words.txt", lines, answer, answer_text);
  check_str(answer_text);

  startGameName(n);
  start_word(n);

  do {
    do {
      if(*players ==  1) {
        printf("\n%s guess: ", player1.name);
      } else if(*players == 2) {
        if(count_game % 2 == 0) {
          printf("\n%s guess: ", player1.name);
        } else {
          printf("\n%s guess: ", player2.name);
        }
      }
      fflush(stdin);
      scanf("%s", guess);
      if(strlen(guess) != 5) printf("\n << only 5 letters >>\n");
    } while(strlen(guess) != 5);

    setResults(answer, guess, count_game);
    check_word(count_game);
    print_word(guess, n);
    
    if(check_win(count_game) == 1) {
      if(*players == 1) {
        player1.score += 1;
      } else if(*players == 2) {
        if(count_game % 2 == 0) { // P1 WIN
          player1.score += 1;
        } else if(count_game % 2 == 1) { // P2 WINT
          player2.score += 1;
        }
      }
      win_lose(answer, count_game, "win", players);
      break;
    }

    count_game++;
  } while(count_game < 6);

  if(check_win(5) == 0 && count_game == 6) {
    win_lose(answer, count_game, "lose", players);
  }

  char check_defi;
  do {
    printf("\nDEFINATION ? (y/n): ");
    fflush(stdin);
    scanf(" %c", &check_defi);
    if(tolower(check_defi) != 'y' && tolower(check_defi) != 'n') {
      printf("\n<< Please type y or n >>\n");
    }
  } while(tolower(check_defi) != 'y' && tolower(check_defi) != 'n');

  if(tolower(check_defi) == 'y') {
    print_defi(answer, answer_text, players);
  }
}

void who_win() {
  clear();
  printf("\n=====================\n");
  if(player1.score == 3) printf("\n    %6s WIN!\n", player1.name);
  else if(player2.score == 3) printf("\n    %6s WIN!\n", player2.name);
  printf("\n=====================\n");
  printf("\n %6s's SCORE: %d\n", player1.name, player1.score);
  printf("\n %6s's SCORE: %d\n", player2.name, player2.score);
  printf("\n=====================\n");
}

int main() {
  int n = 1;
  int players = check_players(&n);
  char play_again;
  
  if(players == 1) {
    setNamePlayer(player1.name, player2.name, &players);
    do {
      game(&players, &n);
      printf("DO YOU WANT TO PLAY MORE ? (y/n): ");
      fflush(stdin);
      scanf(" %c", &play_again);
      if(tolower(play_again) == 'y') n++;
    } while(tolower(play_again) != 'n');
  } else if(players == 2) {
    setNamePlayer(player1.name, player2.name, &players);
    do {
      game(&players, &n);
      n++;
    } while(n < 6 && player1.score < 3 && player2.score < 3);
    who_win();
  }

  return 0;
}