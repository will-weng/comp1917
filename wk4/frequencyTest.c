
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char*argv[]) {

   double count = 0;

   double total = 0;

   char input = 0;

   while(input != EOF) {
      input = getchar();
      if(input >64 && input<91){
      total++;
      } else if(input > 96 && input < 123) {
      total++;
      }
      if(input ==  75 || input == 107) {
         count++;
      }

   }

   printf("%f\n",(count/total)*100.0);

   return EXIT_SUCCESS;
}
