#include <stdio.h>

int main() {
  struct date {
    int day;
    int month;
    int year;
  } date1, date2;

  char next;

  do {
    printf("Date1 : ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);
    printf("Date2 : ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    if(date1.day == date2.day && date1.month == date2.month && date1.year == date2.year) {
      printf("-- Dates are equal. \n");
    } else {
      printf("-- Dates are not equal. \n");
    }

    printf("Next(y/n)? ");
    scanf(" %c", &next);
  } while(next == 'y' || next == 'Y');
  
  return 0;
}