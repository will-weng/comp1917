// Willaim Weng, williamw, z5113248
// 28/3/2016
// print the danish flag using loops


#include <stdio.h>
#include <stdlib.h>

#define PARTS 2
#define LINES 2

void showDanish(void);


int main(int argc, char*argv[]) {

   showDanish();

   return EXIT_SUCCESS;
}


// prints the danish flag
void showDanish(void) {

   int row, line;
   row = 0;
   line = 0;

   while(row < PARTS) {
      while(line < LINES) {
         printf("** *********\n");
         line++;
      }
      if(row == 0) {
         printf("\n");
      }
      row++;
      line = 0;
   }
}
