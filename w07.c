/************************************
 * Id: hawk5052
 *  
 * Purpose: Solve the restricted Towers of Hanoi Problem
 * Input: The number of disks
 * Output: Solved towers of Hanoi
 * compile: gcc -g -Wall -o w06Ex w06.c
 * 
 * 
 ***************************************************/

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

//prototypes
void counterclockwise(int, char, char, char);
void clockwise(int, char, char, char);

//argc is the number of command line arguments
//argv is the individual commands themselves 
int main (int argc, char * argv[]){

   int numOfDisk = atoi(argv[1]);

   counterclockwise(numOfDisk, 'A', 'C', 'B');

   printf("\n");
   return 0;

}

//This function uses recursion to solve the solve the tower of Hanoi problem
//Uses a base case of the number of disks being equal to one
void counterclockwise(int numOfDisk, char fromRod, char toRod, char extraRod){

   if (numOfDisk ==1){
      printf("\nMove %c to %c", fromRod, extraRod);
      printf("\nMove %c to %c", extraRod, toRod);
      
      return; 
   }
   else{
      counterclockwise (numOfDisk-1, fromRod, toRod, extraRod);
      printf("\nMove %c to %c ", fromRod, extraRod);
      //counterclockwise (numOfDisk-1, toRod, fromRod, extraRod);
      clockwise(numOfDisk-1, toRod, fromRod, extraRod);
      printf ("\nMove %c to %c ",extraRod, toRod);
      counterclockwise (numOfDisk-1, fromRod, toRod, extraRod);
   }

}


//Move the disk from c to a
void clockwise(int numOfDisk, char fromRod, char toRod, char extraRod){

   if (numOfDisk ==1){
      printf("\nMove %c to %c", fromRod, toRod);
      return;
   }
   counterclockwise (numOfDisk-1, fromRod, extraRod, toRod);
   printf("\nMove %c to %c ", fromRod, toRod);
   counterclockwise(numOfDisk-1, extraRod, toRod, fromRod);
}

