/******************************************
 * ID: Hunter Hawkins
 *
 *
 *
 * Compile: gcc -o w08 w08.c
 * ****************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void shellsort(int[], int);




int main (int argc, char * argv[]){

   int arr[argc-1];
   int i;
   int numofElem = argc-1;
   for (i=0; i < (argc-1); i++){
      arr[i] = atoi(argv[i+1]);

   }
  printf( "Sorted values\n");

  shellsort(arr, numofElem);

  return 0;
}

void shellsort(int arr[], int numOfElem){

   int i, j, k;

   for( i = numOfElem/2; numOfElem >0; i /= 2){
   
      for (j = i; j < numOfElem; j +=1){

         int temp = arr[j];

         for(k = j; k >= i && arr[k-i] > temp; j -= i){
            arr[k] = arr[k-i];
         }
         arr[k] = temp;
      }
   
   }
}

