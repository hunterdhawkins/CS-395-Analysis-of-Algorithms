/************************************
 * Id: hawk5052
 *  
 * Purpose: Solve the Towers of Hanoi Problem
 * Input: The number of disks
 * Output: Solved towers of Hanoi
 * compile: gcc -g -Wall -o w05Ex w05.c
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
void towOfHanoi(int, char, char, char);


//argc is the number of command line arguments
//argv is the individual commands themselves 
int main (int argc, char * argv[]){

   int numOfDisk = atoi(argv[1]);

   towOfHanoi(numOfDisk, 'A', 'B', 'C');

   printf("\n");
   return 0;

}

//This function uses recursion to solve the solve the tower of Hanoi problem
//Uses a base case of the number of disks being equal to one
void towOfHanoi(int numOfDisk, char fromRod, char toRod, char extraRod){

   if (numOfDisk ==1){
      printf("\nMove %c to %c", fromRod, toRod);
      return; 
   }
   towOfHanoi (numOfDisk-1, fromRod, extraRod, toRod);
   printf("\nMove %c to %c ", fromRod, toRod);
   towOfHanoi (numOfDisk-1, extraRod, toRod, fromRod);
}
