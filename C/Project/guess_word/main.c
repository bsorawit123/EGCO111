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
  system("@cls||clear");
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
    results[count_game][i].guess = tolower(guess[i]);
    results[count_game][i].answer = tolower(answer[i]);
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

void random_word(char *filename, int *lines, char answer[], char answer_text[], int *random) {
  FILE *fp = fopen(filename, "r");
  char words[*lines][1024], text[1024], *ans, *ans_txt;
  for(int i = 0; i < checkLines("words.txt"); i++) {
    fgets(words[i], 1024, fp);
  }
  ans = strtok(words[*random], "--");
  ans_txt = strtok(NULL, "--");
  strcpy(answer, ans);
  strcpy(answer_text, ans_txt);
  fclose(fp);
}

void check_word(int count_game) {
  for(int i = 0; i < 5; i++) {
    if(results[count_game][i].answer == results[count_game][i].guess) {
      results[count_game][i].title = toupper(results[count_game][i].guess);
      results[count_game][i].check = 1;
    } else {
      if(results[count_game][i].title == '-') {
        for(int j = 0; j < 5; j++) {
          if(results[count_game][i].answer == results[count_game][j].guess) {
            results[count_game][j].title = results[count_game][j].guess;
            results[count_game][j].hint = '^';
          }
        }
      }
    }
  } 
  for(int i = 0; i < 5; i++) {
    if(results[count_game][i].hint == '^') {
      for(int j = i+1; j < 5; j++) {
        if(results[count_game][i].title == results[count_game][j].title) {
          results[count_game][j].hint = ' ';
        }
      }
    }
    if(results[count_game][i].title == '-') {
      results[count_game][i].title = results[count_game][i].guess;
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
    if(answer_text[0] == '\n') {
      temp[i] = answer_text[i+1];
    }
    if(answer_text[strlen(answer_text)-1] == '\n') {
      temp[i] = answer_text[i];
    }
  }
  strcpy(answer_text, temp);
}

int check_mode() {
  int choose;
  printf("\n   SELECT CATEGORY\n\n");
  printf("\n   1. PLAY GAMES\n");
  printf("\n   2. HOW TO PLAY\n");
  printf("\n   3. ADD YOUR OWN WORD\n");
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
      if(strlen(player1) > 6) printf("\n<< NAME CAN\'T BE LONGER 6 LETTERS >>\n");
    } while(strlen(player1) > 6);
  } else if(*players == 2) {
    do {
      printf("\n  PLAYER 1: ");
      scanf("%s", player1);
      if(strlen(player1) > 6) printf("\n<< NAME CAN\'T BE LONGER 6 LETTERS >>\n");
    } while(strlen(player1) > 6);
    do {
      printf("\n  PLAYER 2: ");
      scanf("%s", player2);
      if(strlen(player2) > 6) printf("\n<< NAME CAN\'T BE LONGER 6 LETTERS >>\n");
      if(strcmp(player1, player2) == 0) printf("\n<< CAN\'T USE THE SAME NAME >>\n");
    } while(strlen(player2) > 6 || strcmp(player1, player2) == 0);
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

int num_in_str(char guess[]) {
  int num_in_guess = 0;
  for(int i = 0; i < strlen(guess); i++) {
    if(isdigit(guess[i]) == 1) num_in_guess++;
  }
  return num_in_guess;
}

int check_add_word(char *filename, char add_text[]) {
  int lines = checkLines("words.txt");
  FILE *fp = fopen(filename, "r");
  char words[lines][1024], check_word[10];
  for(int i = 0; i < lines; i++) {
    fgets(words[i], 1024, fp);
    for(int j = 0; j < 5; j++) {
      check_word[j] = words[i][j];
    }
    strcpy(words[i], check_word);
  }
  fclose(fp);

  for(int i = 0; i < lines; i++) {
    if(strcmp(words[i], add_text) == 0) return 0;
  }
  if(num_in_str(add_text) != 0) return 0;
  return 1;
}

void add_word(char *filename, int *lines) {
  char word_add[10], add_text[60], text[1024] = "\n";
  int check_add;
  do {
    fflush(stdin);
    printf("\nENTER YOUR WORD: ");
    scanf("%s", word_add);

    check_add = check_add_word("words.txt", word_add);
    if(strlen(word_add) != 5) printf("\n<< ONLY 5 LETTERS >>\n");
    if(check_add == 0) printf("\n<< THIS WORD ALREADY EXISTS >>\n");
  } while(strlen(word_add) != 5 || check_add == 0);

  do {
    fflush(stdin);
    printf("\nENTER DEFINITION: ");
    gets(add_text);
    if(strlen(add_text) > 50) printf("\n<< NO LONGER THAN 50 >>\n");
  } while(strlen(add_text) > 50);

  strcat(text, word_add);
  strcat(text, "--");
  strcat(text, add_text);

  FILE *fp = fopen("words.txt", "a");
  fputs(text ,fp);
  fclose(fp);
}

void game(int *players, int *n, int *lines) {
  int count_game = 0, check_guess;
  char guess[6];
  char answer[10], answer_text[1024];
  int random = random_num(0, (*lines)-1);;

  random_word("words.txt", lines, answer, answer_text, &random);
  check_str(answer_text);

  startGameName(n);
  start_word(n);

  do {
    do {
      do {
        fflush(stdin);
        if(*players ==  1) {
          printf("\n%s guess: ", player1.name);
        } else if(*players == 2) {
          if(count_game % 2 == 0) {
            printf("\n%s guess: ", player1.name);
          } else {
            printf("\n%s guess: ", player2.name);
          }
        }
        scanf("%s", guess);
        check_guess = num_in_str(guess);
        if(check_guess != 0) {
          printf("\n<<   NO NUMBER!   >>\n");
          printf("<< ONLY 5 LETTERS >>\n");
        }
      } while(check_guess != 0);
      if(strlen(guess) != 5) printf("\n << ONLY 5 LETTERS >>\n");
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

  if(check_win(5) == 0 && count_game == 6) win_lose(answer, count_game, "lose", players);

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
  printf("=====================\n");
  printf("|                   |\n");
  if(player1.score == 3) printf("|   %6s WIN!     |\n", player1.name);
  else if(player2.score == 3) printf("|   %6s WIN!     |\n", player2.name);
  printf("|                   |\n");
  printf("=====================\n");
  printf("|                   |\n");
  printf("| %6s's SCORE: %d |\n", player1.name, player1.score);
  printf("| %6s's SCORE: %d |\n", player2.name, player2.score);
  printf("|                   |\n");
  printf("=====================\n");
  printf("   (\\__/) ||\n");
  printf("   (^--^) ||\n");
  printf("   /   >> ||\n");
  printf("  /    )  ||\n");
}

void save_game(char high_player[], int *high_score) {
  char name[10];
  int score;

  FILE *fp = fopen("high-score.txt", "r");
  if(fp == NULL) {
    FILE *fp1 = fopen("high-score.txt", "w");
    fprintf(fp1, "%s %d", player1.name, player1.score);
    fclose(fp1);

    strcpy(high_player, player1.name);
    *high_score = player1.score;
  } else {
    fscanf(fp, "%s %d", name, &score);
    if(player1.score > score) {
      *high_score = player1.score;
      strcpy(high_player, player1.name);

      FILE *fp2 = fopen("high-score.txt", "w");
      fprintf(fp2, "\n%s %d", high_player, *high_score);
      fclose(fp2);
    } else {
      *high_score = score;
      strcpy(high_player, name);
    }
  }
  fclose(fp);
}

void play_more(char *play_again, int *players, int *lines, int *n) {
  do {
    printf("\nDO YOU WANT TO PLAY MORE ? (y/n): ");
    fflush(stdin);
    scanf(" %c", play_again);
    if(tolower(*play_again) != 'y' && tolower(*play_again) != 'n') printf("\n<< ONLY Y AND N >>\n");
  } while(tolower(*play_again) != 'y' && tolower(*play_again) != 'n');

  if(tolower(*play_again) == 'y') {
    *n += 1;
    game(players, n, lines);
    play_more(play_again, players, lines, n);
  }
}

int main() {
  srand(time(NULL));
  int n = 1, high_score;
  char high_player[10];
  int lines = checkLines("words.txt");
  int players = check_players(&n);
  char play_again, save;

  if(players == 1) {
    setNamePlayer(player1.name, player2.name, &players);
    game(&players, &n, &lines);
    play_more(&play_again, &players, &lines, &n);
    
    if(tolower(play_again) == 'n') {
      save_game(high_player, &high_score);
      clear();
      printf("=====================\n");
      printf("|                   |\n");
      printf("|   HIGH SCORE IS   |\n");
      printf("|      %s  %d       |\n", high_player, high_score);
      printf("|                   |\n");
      printf("=====================\n");
      printf("   (\\__/) ||\n");
      printf("   (^--^) ||\n");
      printf("   /   >> ||\n");
      printf("  /    )  ||\n");
    }

  } else if(players == 2) {
    setNamePlayer(player1.name, player2.name, &players);
    do {
      game(&players, &n, &lines);
      n++;
    } while(n < 6 && player1.score < 3 && player2.score < 3);
    who_win();
  }

  // char choice_word;
  // do {
  //   printf("\nADD YOUR OWN WORD (y/n): ");
  //   scanf(" %c", &choice_word);
  // } while(tolower(choice_word) != 'y' || tolower(choice_word) != 'n');
  // add_word("words.txt", &lines);

  return 0;
}