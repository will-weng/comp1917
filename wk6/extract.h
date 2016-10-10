// extract.h
// funtions and types used by extract.c
// richard buckland
// 13 April 2014
// do not alter or submit this file, 
// we'll use our own copy when marking it
     
typedef struct _triordinate {
   double x;
   double y;
   int z;
} triordinate;


triordinate extract (char *message);
     
double myAtoD (char *message);
     
long myAtoL (char *message);
 /*
triordinate extract (char *message) {
   
   triordinate tri;
   message+=46;
   sscanf(message, "%lf", &tri.x);
   message+=6;
   sscanf(message, "%lf", &tri.y);
   message+=8;
   sscanf(message, "%d", &tri.z);

   //http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp
   //int test;
   //test = (int) strtol(message, (char **)NULL, 10);
   //printf("%d\n",test);
   
   //double d;
   
   
   //printf("%lf\n", d);
   return tri;   
}

double myAtoD (char *message) {

}
*/
