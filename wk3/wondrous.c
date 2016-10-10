// William Weng, williamw, z5113248
// 28/3/2016
// a wondrous function that prints out Wondrous numbers


#include <stdio.h>
#include <stdlib.h>

int printWondrous(int start);


int main(int argc, char*argv[]) {

   int start;

   scanf("%d", &start);

   printWondrous(start);

   return EXIT_SUCCESS;
}


// Wondrous function
int printWondrous(int start) {

   int counter;
   counter = 1;

   while(start != 1) {
      if(start % 2 == 0) {
         start = start / 2;
      } else {
         start = start * 3 + 1;
      }
   printf("%d\n", start);
   counter++;
   }
   return counter;
}
