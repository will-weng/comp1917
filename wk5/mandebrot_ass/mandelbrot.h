/*
 *
 *  mandelbrot.h
 *  mandelbrot server
 *
 *  Created by Richard Buckland on 13/04/13.
 *  Licensed under Creative Commons BY 3.0.
 *
 */

/*
#include <math.h>

#define ESCAPED 1
#define STAYED 0
#define RANGE 2

typedef struct _complex {
   double real;
   double imaginary;
} complex;
*/
int escapeSteps(double x, double y);

/*
int modulus(complex complexNum);


//function that counts how many iteration to escape
int escapeSteps(double x, double y) {

   complex point = {x, y};
   complex pointTemp = {x, y};
   complex constant = {x, y};

   int steps = 1;

   while(modulus(point) == STAYED && steps <= 255) {

      pointTemp.real = point.real;
      pointTemp.imaginary = point.imaginary;

      point.real = pointTemp.real*pointTemp.real - pointTemp.imaginary*pointTemp.imaginary +
                        constant.real;
      point.imaginary = pointTemp.imaginary*pointTemp.real*2 + constant.imaginary;

      steps++;
   }

   return steps;
}

// function that calculates the modulus of a point
int modulus(complex complexNum) {

   double real = complexNum.real;
   double imaginary = complexNum.imaginary;
   double modulus;

   modulus = sqrt(real*real + imaginary*imaginary);

	printf("%f\n", modulus);

   int test;
   test = 0;

   if(modulus <= RANGE) {
      test = STAYED;
   } else {
      test = ESCAPED;
   }
   return test;
}
*/
