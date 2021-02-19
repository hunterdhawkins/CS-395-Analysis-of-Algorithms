#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

//prototypes
int coinCollectingRobot(int, int, int[4][3]);
int max(int, int);
void printArr(int, int, int[4][3]);

//argc is the number of arguments, argv is arguments themselves
int main(int argc, char * argv[]){
   
   int i, j;
   int row = atoi(argv[1]);
   int column = atoi(argv[2]);
   int A[row][column];
   
   printf( "X after atoi %d", atoi('x'));
   for( i=2; i < row+2; i++){
      for(j=2; j < column+2; j++){
         A[row][column]= atoi(argv[i][j]);
      }
   }


   printf("Initial game board\n");
   printArr(row, column, A);
   printf("\n\n\n");
   printf("\nHighest number of coins %d\n",coinCollectingRobot(row,column,A));
   return 0;
}

//returns the max of two elements
int max(int a, int b){
   return a>b?a:b;
}
//coin collecting robot logic, start in upper left
//make it to bottom right with largest amount of coins
int coinCollectingRobot(int row, int column, int a[4][3]){
   int i=1;
   int j=1;
   int c[row][column];

   c[0][0]= a[0][0];   //start in upper left corner which should be (0,0) may need to be (1,1)
   while(i<row && a[i][1] !=0){   //will probably have to be 0 instead of negative 1
      c[i][0]=c[i-1][0]+a[i][0];   //zeros may need to be turned into ones
      i++;   
   }
   for(; i<row;i++){
      c[i][0]= (-column);
   }
   while(j < column && a[1][j] !=0){
      c[0][j]=c[0][j-1]+a[0][j];
      j++;
   }
   for(; j<column; j++){
      c[0][j]=(-column);   //may just need to times the column by -1
   } 

   for(i=1; i < row; i++){
      for(j=1; j< column; j++){
         if(a[i][j]!=0){   //may need to be !=0 compared to -1.
            c[i][j] = max(c[i-1][j], c[i][j-1])+a[i][j];
         }
         else{
            c[i][j] = -column;
         }
      }
   }
   
   printf("Paths and Values Board\n");
   printArr(row, column, c);
   return c[row-1][column-1];
}

//print out the board
void printArr(int row, int column, int a[4][3]){

   int i;
   int j;

   for(i=0; i< row; i++){
      for(j=0; j< column; j++){
         printf("%d\t", a[i][j]);  
      }
      printf("\n");
   }


}

