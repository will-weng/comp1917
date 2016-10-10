// William Weng, Lachlan Vernon and Lachlan Kerr
// williamw, lachyv and lachlanadriankerr
// 07/04/2016
// reads a document and prints staticstics about the letters

#include <stdio.h>
#include <stdlib.h>

#define ASCII_A 65

void letterCount();


int main(int argc, char*argv[]) {

   letterCount();

   return EXIT_SUCCESS;
}


// counts letters of a file and prints stats
void letterCount() {

   int letters[57] = { 0 };
   char input;
   input = 'a';

   while(input != EOF) {
      input = getchar();
      letters[input - ASCII_A]++;
   }

   double total;
   total = 0;
   int counter;
   counter = 0;

   while(counter < 57) {
      total = letters[counter] + total;
      counter++;
   }

   double percentage;

   int statOfLetter;
   statOfLetter = 'A';

   printf("The total amount of characters read was: %f\n", total);

   while(statOfLetter < 123) {
      if( statOfLetter <= 'Z' || statOfLetter >= 'a') {
         printf("the number of letter '%c' appears is %d", statOfLetter,
               letters[statOfLetter - ASCII_A]);

         percentage = (letters[statOfLetter - ASCII_A]/total)*100.0;
         printf(" and the frequency is %f\n", percentage);
      }
      statOfLetter++;
   }
}
