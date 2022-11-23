#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct result {
  char title;
  char hint;
  char check;
} results[5];

int checkLines(char*);

int main() {
  char answer[10] = "while";
  char guess[5];
  int count_games = 6;

  int file_lines = checkLines("words.txt");
  char *words[file_lines];
  char *words_txt[file_lines];
  char text[1024];
  char *word, *word_txt;

  FILE *fp = fopen("words.txt", "r");

  for(int i = 0; i < file_lines; i++) {
    fgets(text, 1024, fp);
    char split[] = "--";

    words[i] = strtok(text, split);
    words_txt[i] = strtok(NULL, split);
  }

  printf("==================\n");
  printf("\n    ");
  for(int i = 0; i < 5; i++) {
    results[i].title = '-';
    results[i].hint = ' ';
    results[i].check = 'F';
    printf("%c ", results[i].title);
  }
  printf("\n");
  for(int i = 0; i < 5; i++) {
    printf("%c ", results[i].hint);
  }
  printf("\n");
  printf("==================\n");

  while(count_games > 0) {
    printf("\nGuess word: ");
    scanf("%s", guess);

    printf("\n");
    for(int i = 0; i < 5; i++) {
      if(guess[i] == answer[i]) {
        results[i].title = toupper(guess[i]);
        results[i].check = 'T';
      }
    }
    printf("\n");

    for(int i = 0; i < 5; i++) {
      if(results[i].title == '-') {
        for(int j = 0; j < 5; j++) {
          if(guess[i] == answer[j] && results[i].check != 'T') {
            results[i].title = guess[i];
            results[i].check = 'T';
            results[i].hint = '^';
            break;
          }
        }
      }
    }

    for(int i = 0; i < 5; i++) {
      printf("%c ", results[i].title);
    }
    printf("\n");
    for(int i = 0; i < 5; i++) {
      printf("%c ", results[i].hint);
    }


    int check_true = 0;
    for(int i = 0; i < 5; i++) {
      if(results[i].check == 'T') check_true++;
    }

    if(check_true == 5) count_games = 0;

    count_games--;
  }



  return 0;
}

int checkLines(char *filename) {
  FILE *fp = fopen(filename, "r");
  int line = 0, ch;

  if(fp == NULL) return 0;

  line++; // first line
  while((ch = fgetc(fp)) != EOF) {
    if(ch == '\n') line++;
  }

  return line;
}