//William Weng and Tommy Lee, williamw and tommyl
//17/03/2016
//
//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {

   int x;
   int y;
   long total;

   x = 40;
   y = 2;

   total = add (x, y);

   printf("the sum of %d and %d is %ld\n", x, y, total);

   char c ='a';

   unsigned long ul       =-1;
   unsigned int ui        =-1;
   unsigned long long ull =-1;
   unsigned short us      =-1;

   signed long sl       = -2147483648;
   signed int si        = -2147483647;
   signed long long sll = 2147483647;
   signed short ss      = 7;

   long l       = -2147483647;
   int i        = 9;
   long long ll = 10;
   short s      = 11;
 
   float f = 3.1;
   double d = 3.14;


//to print when overflowing and underflowing
   printf("unsigned long is %lu\n", ul);
   printf("unsigned int is %u\n", ui);
   printf("unsigned long long is %llu\n", ull);
   printf("unsigned short is %hu\n", us);

   printf("signed long is %li\n", sl);
   printf("signed int is %d\n", si);
   printf("signed long long is %lli\n", sll);
   printf("signed short is %hi\n", ss);

   printf("long is %li\n", l);
   printf("int is %i\n", i);
   printf("long long is %lli\n", ll);
   printf("short is %hi\n", ss);

   printf("float is %f\n", f);
   printf("double is %f\n", d);




/*
//to print the byte size of all memory
   printf("size of unsigned long is %d\n", sizeof(ul));
   printf("size of unsigned int is %d\n", sizeof(ui));
   printf("size of unsigned long long is %d\n", sizeof(ull));
   printf("size of unsigned short is %d\n", sizeof(us));

   printf("size of signeds long is %d\n", sizeof(sl));
   printf("size of signed int is %d\n", sizeof(si));
   printf("size of signed long long is %d\n", sizeof(sll));
   printf("size of signed short %d\n", sizeof(ss));

   printf("size of long is %d\n", sizeof(l));
   printf("size of int is %d\n", sizeof(i));
   printf("size of long long is %d\n", sizeof(ll)); 
   printf("size of short is %d\n", sizeof(s));

   printf("size of float is %d\n", sizeof(f));
   printf("size of double is %d\n", sizeof(d));

//to print the location of all memory type
   printf("the location of unsigned long is %p\n", &ul);
   printf("the location of unsigned int is %p\n", &ui);
   printf("the location of unsigned long long is %p\n", &ull);
   printf("the location of unsigned short is %p\n", &us);
   
   printf("the location of signed long is %p\n", &sl);
   printf("the location of signed int is %p\n", &si);
   printf("the location of signed long long is %p\n", &sll);
   printf("the location of signed short is %p\n", &ss);
   
   printf("the location of long is %p\n", &l);
   printf("the location of int is %p\n", &i);
   printf("the location of long long is %p\n", &ll);
   printf("the location of short is %p\n", &s);
   
   printf("the location of float is %p\n", &f);
   printf("the location of double is %p\n", &d);
*/
   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program
 
   double grandTotal;
   grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;
 
   printf ("all these things added together make %f\n", grandTotal);

   return EXIT_SUCCESS;
}

long add (int x, int y) {
   long answer;
   answer = x + y;
 
   return answer;
}

