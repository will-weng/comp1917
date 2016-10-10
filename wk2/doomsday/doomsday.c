/*  William Weng, William, z5113248
 *  21/3/2016
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by William Weng
 *  Freely licensed under Creative Commons CC-BY-3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

void testCode(void);
int dayOfWeek(int doomsday, int leapYear, int month, int day);
int daysTillNextThur(int dayOfWeek);


int main(int argc, char*argv[]) {

   testCode();

   int doomsday = MONDAY, leapYear = 1, day, month;

   printf("Enter a desired date: dd/mm\n");

   scanf("%d/%d", &day, &month);

   dayOfWeek(doomsday, leapYear, month, day);

   int num;
   num = dayOfWeek(doomsday, leapYear, month, day);

   printf("there is %d days till next Thursday.\n",
          daysTillNextThur(num));

   return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek(int doomsday, int leapYear, int month, int day) {

   int dayOfWeek;

   int firstDayOfMonth = doomsday;

   if(month == 1 && leapYear == TRUE) {
      firstDayOfMonth = doomsday + 4;
   } else if(month == 1 && leapYear == FALSE) {
      firstDayOfMonth = doomsday + 5;
   } else if(month == 2 && leapYear == FALSE) {
      firstDayOfMonth = doomsday + 1;
   } else if(month == 3) {
      firstDayOfMonth = doomsday + 1;
   } else if(month == 4) {
      firstDayOfMonth = doomsday + 4;
   } else if(month == 5) {
      firstDayOfMonth = doomsday + 6;
   } else if(month == 6) {
      firstDayOfMonth = doomsday + 2;
   } else if(month == 7) {
      firstDayOfMonth = doomsday + 4;
   } else if(month == 9) {
      firstDayOfMonth = doomsday + 3;
   } else if(month == 10) {
      firstDayOfMonth = doomsday + 5;
   } else if(month == 11) {
      firstDayOfMonth = doomsday + 1;
   } else if(month == 12) {
      firstDayOfMonth = doomsday + 3;
   }
   dayOfWeek = ((day + firstDayOfMonth % DAYS_PER_WEEK
                + 6) % DAYS_PER_WEEK) % 7;
   return dayOfWeek;
}


// given the day of the week, it calculate how many days
// till next thursday

int daysTillNextThur(int dayOfWeek) {

   int daysTillNextThur;

   daysTillNextThur = DAYS_PER_WEEK - dayOfWeek;

   return daysTillNextThur;
}


//tests if doomsday works properly

void testCode(void) {

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

   assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);

   assert (dayOfWeek (SUNDAY, FALSE, 7, 24) == SATURDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 4, 22) == MONDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 2, 10) == SUNDAY);

   printf ("all tests passed - You are awesome!\n");

}
