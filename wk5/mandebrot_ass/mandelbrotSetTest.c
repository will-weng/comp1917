#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mandelbrot.h"

int main(int argc, char *argv[]) {

   double real = -0.9;
   double imaginary = -0.9;

   printf("type 2 cooridnates:\n");

//   scanf("%lf %lf", &real, &imaginary);

   printf("took %d steps to escape\n",escapeSteps(real, imaginary));

   return EXIT_SUCCESS;
}
