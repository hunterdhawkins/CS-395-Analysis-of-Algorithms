/*********************************************
 * Id: hawk5052
 *
 * Purpose: Gaussian Eliminationm
 * Input: First: number of rows Second: numbers to fill those rows
 * Output: Simplified Matrix
 * compile: gcc -g -Wall -o w04Ex w04.c
 * 
 * 
 **************************************************/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>


#define MAX_EQU 20
//prototypes
void GE(float[][MAX_EQU+1], int);
void printMatrix(float [][MAX_EQU+1], int);

// argc is the total number of arguments
// argv is the arguments themself in string form
// first command line argument is number of rows in matrix
// second argument is numbers in matrix themselves 
// matrix should be a square so if theres 2 rows there should be 2 columns
int main(int argc, char* argv[])
{
   int n = at =0; i < n; i++){
      for(j=0; j < n+1; j++){
         arr[i][j] = atoi(argv[j+2+(i*(n+1))]) * 1.0f;   //read in arguments into a 2D array
      }
   }
(i(argv[1]);   // used to store number of rows/ collumns in array
   float arr[MAX_EQU][MAX_EQU+1];      //array size set to max of 20 rows, 21 columns
   int i, j;
   //int totalCount = atoi(argv[1])*2;   
   if (argc < n*(n+1)+2){
      printf ("Error, try again \n");   //invalid input
      return 1;
   }
   for(i =0; i < n; i++){
      for(j=0; j < n+1; j++){
         arr[i][j] = atoi(argv[j+2+(i*(n+1))]) * 1.0f;   //read in arguments into a 2D array
      }
   }
   
   GE(arr, n);
   return(0);
}

//This function is used to execute Gaussian Elimination
//The input is a 2D array and the number of command line arguments-1
//The output is a printed out, reduced matrix
//can multiply an int by 1.0 to get float data type
//

void GE(float A[][MAX_EQU+1], int numOfElem)
{
   printMatrix(A, numOfElem);
   int i, j ,k;
   float tempji;

   //Agorithm given by Dr.Bc
   for(i =0; i <=  numOfElem-1; i++){
      for (j =i+1; j<= numOfElem; j++){
         tempji=A[j][i];
         for (k =i; k <= numOfElem; k++){
            A[j][k]= A[j][k]-((A[i][k] * tempji) / A[i][i]);
         }  
      }
      printMatrix(A, numOfElem);
   }
}

// temp
void printMatrix(float A[][MAX_EQU+1], int numOfElem){
   //Print out the updated matrix
   
   int i, j;

   for(i =0; i <  numOfElem; i++){
      for (j =0;j < numOfElem+1; j++){
         printf( "%.2f ", A[i][j]);
      }
      printf ("\n");
   }
   printf("\n");
}
