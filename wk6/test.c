#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int main(int argc, char *argv[]) {
   char * message = "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp";
   //char * message = "123a123";
   
   message+=46;

   //http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp
   //int test;
   //test = (int) strtol(message, (char **)NULL, 10);
   //printf("%d\n",test);
   
   double d;
   
   sscanf(message, "%lf", &d);
   printf("%lf", d);
   return EXIT_SUCCESS;
   
}

