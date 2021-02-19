/******************************************
 * Id: hawk5052
 * Purpose: Insertion sort
 * Input: unsorted array
 * Output: sorted array
 *
 *
 * Compile: gcc -o w10 w10.c
 *****************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
void insertionsort(int[], int);
void printArray(int[], int, int);


int main (int argc, char * argv[]){

   int arr[argc-1];
   int i;
   int numofElem = argc-1;
   for (i=0; i < (argc-1); i++){
      arr[i] = atoi(argv[i+1]);

   }

   insertionsort(arr, numofElem);

   return 0;
}
//Insertion sort code logic
//Input is an unsorted array
//output is a sorted array
void insertionsort(int arr[], int numOfElem){

   int i, j, v;

   for(i = 1; i < numOfElem; i++){
      v = arr[i];
      j = i-1;
      printArray(arr, numOfElem,i );
      
      while (j >= 0 && arr[j] > v){
         arr[j+1] = arr[j];
         j--;

      }
      arr[j+1] = v;
   }
   printArray(arr, numOfElem, i); 
}

//Function to print out array element by element
void printArray(int arr[], int numOfElem, int j){
   int i;
   for(i =0; i < numOfElem; i++){
      printf("%d ", arr[i]);
      if ( j-1 == i ){
         printf("| ");
      }
   }
   printf("\n");
  
}
