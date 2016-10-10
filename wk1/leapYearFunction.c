//William Weng, williamw, z5113248
//11/3/2016
//a function that decides whether a year can leap
//test:1581, 2000, 1600, 2014, 2016, 12345, 42, 1900

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define GREG_CAL_START_YEAR 1582

int isLeapYear (int year);

int main(int argc, char*argv[]) {

   int year;

   int theyear;

   printf("Enter the Year which you desire:\n");

   scanf("%d", &year);

   assert(year >= GREG_CAL_START_YEAR);

   theyear = isLeapYear (year);

   if(theyear == 1) {
      printf("%d is a leap year!\n", year);
   } else {
      printf("%d is not a leap year!\n", year);
   }

   return EXIT_SUCCESS;
}


//decides if year is leap year or not
int isLeapYear (int year) {

   if(year % 400 == 0) {
      year = 1;
   } else if(year % 4 == 0) {
         if(year % 100 == 0) {
            year = 0;
         } else {
            year = 1;
         }
   }
   return year;
}
