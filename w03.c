/*********************************************
 * Id: hawk5052
 *
 * Purpose: To make an the function 2^n as ineffecient as possible
 * Input: An integer that represents n in the formula 2^n
 * Output: The answer to 2^n, where n is the input, as slow and memory intensive as possible
 * compile: gcc -g -Wall -o w03Ex w03.c
 * 
 * 
 **************************************************/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
//prototypes
int PowN(int, int);


//argc is the total number of arguments
////argv is the arguments themself in string form
int main(int argc, char* argv[])
{
   int userInput = atoi(argv[1]);
   int two =2;
   printf("%d\n", PowN(two, userInput));
   return(0);
}

//This function is used to calculate 2^n as ineffeciently as possible
//The input is the exponent
//The output is 2^n in an ineffecient manner
int PowN(int two,int n)
{
   if(n)
   {
      return (PowN(two, n-1) + PowN(two, n-1));
   }
   else
   {
      return 1;
   }
}

