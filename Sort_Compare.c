/******************************************
* Id: Hunter Hawkins
* purpose: Compare Effeciency of Sorting Algorithms
* input: None from command line (generated in main)
* output:  Run times of different algorithms
* Compile: gcc -o Sort_Compare Sort_Compare.c
* Notes: This program was developed in Computer
* Science-395 Analysis of ALgorithms at The
* University of Idaho in order to compare the
* the runtimes of algorthms. It was created using
* C99. 
*****************************************/

//Libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

//prototypes
void randArr(int[], int);
void quicksort(int[], int,int);
void printSubArray(int[], int, int);
void swap (int *, int *);
int partition(int[], int, int);
void selectionsort(int[], int);
void printArray(int[], int);
void insertionsort(int[], int);
void output(float, float, float, float, float, float, float, float, float);

#define ARRSIZE1 1000
#define ARRSIZE2 10000
#define ARRSIZE3 100000


int main (int argc, char * argv[]){

   int i, j, k; 
   int loopCtl=1;
   float Quick1, Select1, Insert1, Quick2, Select2, Insert2, Quick3, Select3, Insert3;

   struct timeval start;
   struct timeval stop;

   srand(time(NULL));
   int arr1[ARRSIZE1];
   int arr2[ARRSIZE2];
   int arr3[ARRSIZE3];
  
   // Start Array 1

   //quicksort 
   gettimeofday(&start, NULL);   //start time
   for(i =0; i < loopCtl; i++){
      randArr(arr1, ARRSIZE1);   //generate random array
      quicksort(arr1, 0, ARRSIZE1);
   }
   gettimeofday(&stop, NULL);   //end time
   printf("Quicksort W/ Array 1 ");
   Quick1 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);

   //section sort
   gettimeofday(&start, NULL);
   for(j =0; j < loopCtl; j++){
      randArr(arr1, ARRSIZE1);
      selectionsort(arr1, ARRSIZE1);
   }
   gettimeofday(&stop, NULL);
   Select1 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);
   
   //insertion sort
   gettimeofday(&start, NULL);
   for (k =0; k < loopCtl; k++){
      randArr(arr1, ARRSIZE1);
      insertionsort(arr1, ARRSIZE1);
   }
   gettimeofday(&stop, NULL);
   Insert1 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);
 

   //Start Array 2

   //quicksort with array 2
   gettimeofday(&start, NULL);
   for (i =0; i < loopCtl; i++){
      randArr(arr2, ARRSIZE2);
      quicksort(arr2, 0, ARRSIZE2);
   }
   gettimeofday(&stop, NULL);
   Quick2 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);

   //selectionsort with array 2
   gettimeofday(&start, NULL);
   for (j =0; j < loopCtl; j++){
      randArr(arr2, ARRSIZE2);
      selectionsort(arr2, ARRSIZE2);
   }
   gettimeofday(&stop, NULL);
   Select2 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);
  

   //insertion sort with array 2
   gettimeofday(&start, NULL);
   for (k =0; k < loopCtl; k++){
      randArr(arr2, ARRSIZE2);
      insertionsort(arr2, ARRSIZE2);
   }
   gettimeofday(&stop, NULL);
   Insert2 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);

   //Start Array 3


   //quicksort with array 3
   gettimeofday(&start, NULL);
   for (i =0; i < loopCtl; i++){
      randArr(arr3, ARRSIZE3);
      quicksort(arr3, 0, ARRSIZE3);
   }
   gettimeofday(&stop, NULL);
   Quick3 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);
  
   
   //slection sort with array 3
   gettimeofday(&start,NULL);
   for (j =0; j < loopCtl; j++){
      randArr(arr3, ARRSIZE3);
      selectionsort(arr3, ARRSIZE3);
   }
   gettimeofday(&stop,NULL);
   Select3 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);

 
   //insertion sort with array 3
   gettimeofday(&start, NULL);
   for (k=0; k < loopCtl; k++){
      randArr(arr3, ARRSIZE3);
      insertionsort(arr3, ARRSIZE3);
   }
   gettimeofday(&stop, NULL);
   Insert3 = ((stop.tv_sec - start.tv_sec)*1000.0f+(stop.tv_usec-start.tv_usec)/1000.0f);

   output(Quick1, Select1, Insert1, Quick2, Select2, Insert2, Quick3, Select3, Insert3);

   return 0;
}

/*****************************************
* This function is used to randomize arrays
******************************************/
void randArr(int arr[], int numOfElem){
   int i;

   for(i =0; i < numOfElem; i++){
      arr[i] = rand() % 10000;

   }

}

/******************************************
* This function is used to format the final output
* ****************************************/
void output(float Quick1, float Select1, float Insert1, float Quick2, float Select2, float Insert2, float Quick3, float Select3, float Insert3){
   printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
   printf("This program is to compare run times of quicksort, selection sort, and insertion sort\n");
   printf("All times are in milliseconds\n");
   printf("The first array is 1000 random elements with values between 0 and 10000\n");
   printf("The second array is 10,000 random elements with values between 0 and 10000\n");
   printf("The third arrat is 100,000 random elements with values between 0 and 10000\n");
   printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
 
   printf("Array Size               Quicksort                 Selectionsort               Insertionsort");
   printf("\n%d ", ARRSIZE1);
   printf("                     %.3f " , Quick1);
   printf("                     %.3f ", Select1);
   printf("                     %.3f\n", Insert1);
   printf("%d ", ARRSIZE2);
   printf("                    %.3f " , Quick2);
   printf("                    %.3f ", Select2);
   printf("                    %.3f\n", Insert2);
   printf("%d ", ARRSIZE3);
   printf("                   %.3f " , Quick3);
   printf("                   %.3f ", Select3);
   printf("                   %.3f\n", Insert3);

}


/*************************************************
* Quicksort Function
* Worst: O(n^2) This is when array is nearly sorted
* Generally considered the "fastest"
************************************************/
void quicksort(int arr[], int first, int last){
   
   if(first < last){
      int pVal = partition(arr, first, last);
      quicksort(arr, first, pVal-1);
      quicksort(arr, pVal+1, last);
   }
}
/***************************************************
* Hoare partitioning used to partition the array
* partition the array based upon the pivot value (pVal)
* To the left will be smaller and the right will be larger
**************************************************/
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

/*****************************
* This function is used to print the
* subarrays of each sort
********************************/
void printSubArray(int arr[], int first, int last){
   int i;
   for(i = first; i <= last; i++){
      if(arr[i]!=0){
         printf("%d ", arr[i]);
      }
   }
   printf("\n");

}
/*****************************
* This function is used to swap
* two elements in an array
*******************************/
void swap(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}


/*****************************************************
* This function is used for selection sort
* Worst Case: O(n^2) 
*************************************************/
void selectionsort(int arr[], int numOfElem){

   int i, j, min;
   for (i =0; i < numOfElem-1; i++){
      min =i;
      for(j = i+1; j < numOfElem; j++){
         if(arr[j] < arr[min]){
            min =j;
         }
      }
      swap(&arr[i], &arr[min]);   //use swap function previously produced
   }
}


/*****************************************
* This function is used for insertion sort
* Worst Case: O(n^2)
***********************************/
void insertionsort(int arr[], int numOfElem){
   int i, j, v;
   for(i = 1; i < numOfElem; i++){
      v = arr[i];
      j = i-1;

      while (j >=0 && arr[j] > v){
         arr[j+1] = arr[j];
         j--;
      }
      arr[j+1] = v;
   }
}
