#include <stdio.h>
#include <string.h>

int check_lines() {
  FILE *fp = fopen("history.txt", "r");
  int lines = 0;
  char text[1024];
  while(!feof(fp)) {
    fgets(text, 1024, fp);
    lines++;
  }
  fclose(fp);
  return lines;
}

int main() {
  FILE *fp = fopen("history.txt", "r");
  if(fp == NULL) {
    FILE *fp1 = fopen("history.txt", "w");
    fprintf(fp1, "%s %d", "Boom", 6);
    fprintf(fp1, "\n%s %d", "Jetyy", 8);
    fprintf(fp1, "\n%s %d", "Love", 10);
    fprintf(fp1, "\n%s %d", "Ultra", 12);
    fprintf(fp1, "\n%s %d", "Boom", 3);
    fprintf(fp1, "\n%s %d", "Tiger", 1);
    fclose(fp1);
  } else {
    int lines = check_lines();
    char names[lines][10];
    int scores[lines];

    FILE *fp2 = fopen("history.txt", "r");
    int counter = 0;
    while(!feof(fp2)) {
      fscanf(fp2, "%s %d", names[counter], &scores[counter]);
      counter++;
    }
    fclose(fp2);

    int pos, temp;
    for(int i = 0; i < lines; i++) {
      for(int j = i+1; j < lines; j++) {
        if(strcmp(names[i], names[j]) == 0) {
          if(scores[i] < scores[j]) {
            temp = scores[i];
            scores[i] = scores[j];
            scores[j] = scores[i];
          }
          pos = j;
        }
      }
    }

    for(int i = pos; i < lines-1; i++) {
      scores[i] = scores[i+1];
      strcpy(names[i], names[i+1]);
    }

    FILE *fp3 = fopen("history.txt", "w");
    for(int i = 0; i < lines-1; i++) {
      if(i == 0) fprintf(fp3, "%s %d", names[i], scores[i]);
      else fprintf(fp3, "\n%s %d", names[i], scores[i]);
    }
  }

  


  return 0;
}