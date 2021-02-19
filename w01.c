/*********************************************
 * Id: hawk5052
 *
 * Purpose: Reproduce the algorithm to find the distance between the two closest elements in an array of numbers
 * Input: Array of A[0...n-1] of integers given as command lines argument
 * Output: Minimum distance between two of its elements
 * compile: gcc -g -Wall -o Assign1 Assign1.c
 * 
 * 
 **************************************************/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//prototypes
int minDist(int A[], int);


//argc is the total number of arguments
////argv is the arguments themself in string form
int main(int argc, char* argv[])
{
   int arr[argc-1];     //size of array
   int numOfArgs = argc-1;      //needed to execute for loops in minDistance
   int i;       //need to decalare before for loop
   //load in an array from the command line
   for(i = 0; i < (argc - 1); i++) {
      arr[i]= atoi(argv[i + 1]);
      //printf( "%d\n", arr[i]);   //im used for testing purposes
   }

   printf ("The minimum distance between two elements of the array is \n");
   printf("%d\n", minDist(arr,numOfArgs));


   return(0);
}

//This function is used to calculate the minimum distance between two elements in an array
//The input includes the number of command line arguments and the arguments themselves as 
//numbers instead of strings.
//The output is the minimum distance between two of those elements. 
int minDist(int A[],int numOfArgs)
{
   int distmin=INT_MAX;
   int i, j;

   for (i =0; i < numOfArgs; i++){
      for (j=0; j < numOfArgs; j++){
         if ( i!=j && abs(A[i]-A[j]) < distmin) {
            distmin = abs(A[i]-A[j]);
         }
      }
   }
   return distmin;
}


