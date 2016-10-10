// William Weng & Tommy Lee, williamw & tommyl
// 24/3/2016
// swaps the numbers in 2 variables


#include <stdio.h>
#include <stdlib.h>


void swap (int* first, int* second);


int main(int argc, char*argv[]) {

   int first, second;

   first = 1;
   second = 2;

   swap(&first, &second);

   printf("first is now %d, second now %d\n", first, second);

   return EXIT_SUCCESS;
}


// swaps 2 numbers
void swap(int* first, int* second) {

   int temp;

   temp = *second;
   *second = *first;
   *first = temp;
}
