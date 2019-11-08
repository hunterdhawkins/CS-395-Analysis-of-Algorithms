/*********************************************
 * Id: Hunter Hawkins
 *
 * Purpose: Reproduce the algorithm to find the distance 
 * between the two closest elements in an array of numbers
 * Input: Array of A[0...n-1] of integers given as command lines argument
 * Output: Minimum distance between two of its elements
 * compile: gcc -g -Wall -o Assign1 Assign1.c
 * Notes: Made by Hunter Hawkins in CS-395 Analysis
 * of Algorothms at University of Idaho
 * 
 **************************************************/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//prototypes
int minDist(int A[], int);



int main(int argc, char* argv[])
{
   int arr[argc-1];     //size of array
   int numOfArgs = argc-1;      //number of elements in the array
   int i;
   for(i = 0; i < (argc - 1); i++) {
      arr[i]= atoi(argv[i + 1]);   //Read array in from command line
   }

   printf ("The minimum distance between two elements of the array is \n");
   printf("%d\n", minDist(arr,numOfArgs));


   return(0);
}

/*********************************************
* Find and return the minimum distance between
* two elements in an array
**********************************************/
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


