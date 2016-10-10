// extract.c
// funtions and types used to extract x,y,z values from a
// string containing a url of the form
// "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp"
// initially by richard buckland
// 13 April 2014
// your name here:
     
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"

int main (int argc, char *argv[]) {
        
   char * message = "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp";
     
   triordinate dat = extract (message);    
   printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
     
   assert (dat.x == 3.14);
   assert (dat.y == -0.141);
   assert (dat.z == 5);
     
   return EXIT_SUCCESS;
}


triordinate extract (char *message) {
   
   triordinate tri;
   message+=46;
   tri.x = myAtoD(message);
   message+=6;
   tri.y = myAtoD(message);
   message+=8;
   tri.z = myAtoL(message);

   //http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp
   //int test;
   //test = (int) strtol(message, (char **)NULL, 10);
   //printf("%d\n",test);
   
   //double d;
   
   
   //printf("%lf\n", d);
   return tri;   
}

double myAtoD (char *message) {
   double d;
   sscanf(message, "%lf", &d);
   return d;
}
     
long myAtoL (char *message) {
   long l;
   sscanf(message, "%ld", &l);
   return l;
}
