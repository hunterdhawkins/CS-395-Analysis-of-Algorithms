#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void russianPes(int, int);

//argc is the number of arguments, argv is arguments themselves
int main(int argc, char * argv[]){
   int num1, num2;

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

void russianPes(int num1, int num2){
   
   int res =0;
   printf("%6d ",num1);
   printf("%6d\n", num2); 
   //printf("%d\n", num2);
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
