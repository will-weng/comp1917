// William Weng & Tommy Lee, tommyl & williamw
// 24/3/16
// program that decyphers rot13


#include <stdio.h>
#include <stdlib.h>


char encode(char letter);


int main(int argc, char* argv[]) {
   
   int counter = 1;
   char letter;
   
   while(counter > 0) {
      scanf("%c", &letter);
   
      printf("%c",encode(letter));
   }
   return EXIT_SUCCESS;
}

char encode(char letter) {
   
   char encodedLetter = 0;
      
   if (letter >= 'a' && letter <= 'm') {
      encodedLetter = letter + 13;
   } else if(letter >= 'n' && letter <= 'z') {
      encodedLetter = letter - 13;
   } else if(letter >= 'A' && letter <= 'M') {
      encodedLetter = letter + 13;
   } else if(letter >= 'N' && letter <= 'Z') {
      encodedLetter = letter - 13;
   } else {
      encodedLetter = letter;
   }
   return encodedLetter;
}
