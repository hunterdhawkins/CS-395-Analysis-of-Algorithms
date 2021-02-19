/******************************************
 * Id: Hawk5052
 * purpose: sort array
 * input: unsorted array
 * output:sorted array
 * Compile: gcc -o w08 w08.c
 *****************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//prototypes
void quicksort(int[], int,int);
void printSubArray(int[], int, int);
void swap (int *, int *);
int partition(int[], int, int);


//argc is num of args
//argv is args themselves
int main (int argc, char * argv[]){

   int arr[argc-1];
   int i;
   int numofElem = argc-1;
   for (i=0; i < numofElem; i++){
      arr[i] = atoi(argv[i+1]);
   }

   quicksort(arr,0, numofElem-1);
   printSubArray(arr,0, numofElem);

   return 0;
}

//quicksort function to actually implement the sort
void quicksort(int arr[], int first, int last){

   if(first < last){
      printSubArray(arr, first, last);
      int pVal = partition(arr, first, last);
      quicksort(arr, first, pVal-1);
      quicksort(arr, pVal+1, last);
      //printSubArray(arr, first, last);

   }
}
//partition the array based upon the pVal
//left will be smaller, right will be bigger
int partition(int arr[], int first, int last){

   int pVal= arr[first];
   int i = first;
   int j = last+1;

   do{
      do{
         i=i+1;
      } while(arr[i] < pVal);
      do{
         j=j-1;
      } while(arr[j] > pVal);

      swap(&arr[i], &arr[j]);
   }while(i < j);

   swap(&arr[i], &arr[j]);
   swap(&arr[first], &arr[j]);

   return j;

}

//print out array element by element
void printSubArray(int arr[], int first, int last){
   int i;
   for(i = first; i <= last; i++){
      if(arr[i]!=0){
         printf("%d ", arr[i]);
      }
   }
   printf("\n");

}
//swap two elements in the array
void swap(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}

