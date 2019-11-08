/*********************************************
 * Id: Hunter Hawkins
 *
 * Purpose: Make a program to execute Gaussian Elimination of a matrix
 * Input: First: The number of rows 
 *        Second: Entries in matrix
 * Output: Simplified Matrix
 * compile: gcc -g -Wall -o GausElim GausElim.c
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


int main(int argc, char* argv[])
{
   int n = atoi(argv[1]);   //Number of rows/ collumns in array
   float arr[MAX_EQU][MAX_EQU+1];   //array size set to max of 20 rows, 21 columns
   int i, j;
 
   //Validity Check   
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

/*********************************************************
* This function is used to execute Gaussian Elimination
* It also prints the matrix before and after the operations
**********************************************************/
void GE(float A[][MAX_EQU+1], int numOfElem)
{
   printMatrix(A, numOfElem);
   int i, j ,k;
   float tempji;
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

/*******************************************************
* This function is used to print out the matrix 
********************************************************/
void printMatrix(float A[][MAX_EQU+1], int numOfElem){
   
   int i, j;

   for(i =0; i <  numOfElem; i++){
      for (j =0;j < numOfElem+1; j++){
         printf( "%.2f ", A[i][j]);
      }
      printf ("\n");
   }
   printf("\n");
}
