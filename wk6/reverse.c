// William Weng, Williamw, z5113248
// 04/05/2016
// to reverse a string

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *reverse(char *message);

int main(int argc, char *argv[]) {

   char *message = "Hello";

   reverse(message);
   
   return EXIT_SUCCESS;
}


char *reverse(char *message) {
   
   char *reversed[malloc(sizeof(char)*1000)] = {0};
   int counter = 0;
   int reverseCounter = strlen(message);
   
   while(reversed[counter] != strlen(*message)) {
      
      reversed[counter] = message[reverseCounter];
      counter++;
      reverseCounter--;
   }
   
   reversed[counter++] = NULL;
   
   return *reversed;
}
