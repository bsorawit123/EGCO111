#include <string.h>
#include <stdio.h>
#include <windows.h>

int main() {
  char st[10]="hangman", ans[10]="";
  int i, count=0, flag;
  char ch;
  for(i = 0; i < strlen(st); i++) {
    ans[i] = ' ';
  }
  ans[i]=' \0';

  do {
    system("cls");
    printf("-----\n");
    printf("|     |\n");
    switch(count) {
      case 0: printf("|     \n");
              printf("|     \n");
              printf("|     \n");
              printf("|     \n");
              break;
      case 1: printf("|     o\n");
              printf("|     \n");
              printf("|     \n");
              printf("|     \n");
              break;
      case 2: printf("|     o\n");
              printf("|     |\n");
              printf("|    \n");
              printf("|    \n");
              break;
      case 3: printf("|     o\n");
              printf("|    /| \n");
              printf("|    \n");
              printf("|    \n");
              break;
      case 4: printf("|     o\n");
              printf("|    /|\\\n");
              printf("|    \n");
              printf("|    \n");
              break;
      case 5: printf("|     o\n");
              printf("|    /|\\\n");
              printf("|     |\n");
              printf("|    \n");
              break;
      case 6: printf("|     o\n");
              printf("|    /|\\\n");
              printf("|     |\n");
              printf("|    /\n");
              break;
      case 7: printf("|     o\n");
              printf("|    /|\\\n");
              printf("|     |\n");
              printf("|    / \\\n");
              break;
    } 
    printf("|     \n");

    for(i=0; i<strlen(ans); i++) {
      if(ans[i]==' ') printf("_ ");
      else printf("%c", ans[i]);
    }
    printf("\n");

    if(count==7) {
      printf("\n===== You Die ===== \n");
      printf("Answer is \"%s\" \n",st);
      break;
    }
    
    if(strcmp(ans, st)==0) {
      printf("***** You Win !!! ***** \n");
      break;
    }

    ch = getch();
    flag=0;

    for(i = 0; i < strlen(st); i++) {
      if(ch == st[i]) {
        flag = 1;
        ans[i] = ch;
      }
    }
    if(flag==0) count++;

  } while(1);

  return 0;
}