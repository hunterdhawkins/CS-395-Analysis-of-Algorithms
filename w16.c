/******************************************
 * Id: Hawk5052
 *
 * Purpose: Brute Force string matching algorithm
 * Input: Strings inputed from command line
 * Output: Matches of string
 * Compile: gcc -o w16 w16.c
 *
 *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
int bruteForce(char *, char *);


//argc is the number of arguments, argv is arguments themselves
int main(int argc, char * argv[]){
   //make sure input is correct 
   if(argc <= 2){
      printf("Invalid number of arguments try again\n");

   }


   //Return the matching position of the string
   bruteForce(argv[1], argv[2]);
 


   return 0;
}

//check for matches the brute force way
int bruteForce(char *P, char *T){

   int i,j;
   int m = strlen(P);
   int n = strlen(T);
 
   int matches[m];
   int matchLocat=0;

   for(i =0; i < n-m; i++){
      for(j =0; j < m; j++){
         if(T[i+j] != P[j]){
            break;
         }
      }
      if(j ==m){
         //printf("Match found at location %d\n", i);
         matches[matchLocat++] = i;
      }

   }
   printf("Matches found at locations:");
   for(j=0; j < matchLocat; j++){
      printf(" %d", matches[j]);
   }
   printf("\n");

   return -1;
   
}

