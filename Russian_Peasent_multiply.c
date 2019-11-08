/******************************************
 * Id: Hawk5052
 *
 * Purpose: Mulitply two numbers using Russian Peasent
 * multiplication
 * Input: Two numbers from the command line
 * Output: Solution of numbers multiplied together
 * Compile: gcc -o RussianPeasent RussianPeasent.c
 *
 *****************************************/

//Libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//prototypes
void russianPes(int, int);

int main(int argc, char * argv[]){
   int num1, num2;
   
   //Validity check
   if (argc !=3){
      printf("Invandalid input, try again\n");
   }

   else{
      num1 = atoi(argv[1]);
      num2 = atoi(argv[2]);

      russianPes(num1, num2);
   }
   
   return 0;
}

/********************************
* This function is used to multiply two
* numbers together using Russian peasent
* multiplication
**********************************/
void russianPes(int num1, int num2){
   
   int res =0;
   printf("%6d ",num1);
   printf("%6d\n", num2); 
   while(num1 >=1){
      if(num1 &1){
         res = res + num2;
      }
      num1 = num1 >> 1;
      if(num1 !=0){
         printf("%6d ", num1);
         num2 = num2 << 1;
         printf("%6d", num2);
         if((num1 % 2) !=0){
            printf(" %6d\n", num2);
         }
         else{
            printf("\n");
         }
      }
   }
   printf("%20s\n","------");
   printf("%20d\n", res);
}
