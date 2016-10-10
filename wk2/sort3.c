//William Weng, Williamw, z5113248
//3/21/2016
//sorts 3 numbers in ascending order

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char*argv[]) {

   int first, second, third;

   scanf("%d %d %d", &first, &second, &third);

   if(first <= second && first <= third) {
      if(second <= third) {
         printf("%d\n%d\n%d", first, second, third);
      } else {
         printf("%d\n%d\n%d\n", first, third, second);
      }
   }
   if(second <= first && second <= third) {
      if(first <= third) {
         printf("%d\n%d\n%d\n", second, first, third);
      } else {
         printf("%d\n%d\n%d\n", second, third, first);
      }
   }
   if(third <= first && third <= second) {
      if(first <= second) {
         printf("%d\n%d\n%d\n", third, first, second);
      } else {
         printf("%d\n%d\n%d\n", third, second, first);
      }
   }

   return EXIT_SUCCESS;
}
