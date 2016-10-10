//Tommy Lee and William Weng, tommyl and williamw
//10/3/2016
//to decide whether a year is able to leap
//100, 2000, 1000 2016, 1738, 1582, 1583


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define GREG_CAL_START_YEAR 1582

int main(int argc, char*arg[]) {

   int Year;

   printf("Please enter a year:\n");

   scanf("%d", &Year);

   assert(Year >= GREG_CAL_START_YEAR);

   if(Year % 400 == 0) {
      printf("%d is a leap year!\n", Year);
   } else {
      if(Year % 4 == 0) {
         if(Year % 100 == 0) {
            printf("%d is not a leap year!\n", Year);
         } else {
            printf("%d is a leap year!\n", Year);
           }
      } else {
         printf("%d is not a leap year!\n", Year);
        }
     }
   return EXIT_SUCCESS;
}
