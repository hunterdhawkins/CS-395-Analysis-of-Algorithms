/******************************************
 * Id: Hunter Hawkins
 *
 * Purpose: Impliment the Horspool string matching algorithm
 * Input: Strings inputed from the command line
 * Output: Location of matches
 * Compile: gcc -o Horspool Horspool.c
 * Notes: Created in CS 395 at University of Idaho
 *****************************************/

//Libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
int shiftTable(char *, int * );
void printShiftTable(int[]);
int horspoolMatch(char *, char *);

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32


int main(int argc, char * argv[]){

   //Validity check 
   if(argc <= 2){
      printf("Invalid number of arguments try again\n");

   }


   //Return the matching position of the string
   horspoolMatch(argv[1], argv[2]);

   return 0;
}

/***********************************************
* This function is used to print out the shift table.
* This was given by Dr. BC due to her auto marker being
* specific
***************************************************/
void printShiftTable(int Table[]){

   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start +=TABLE_ROW_LENGTH){
      for(i = start; i < start+ TABLE_ROW_LENGTH; i++){
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++){
         printf("%d\t", Table[i]);
      }
      printf("\n\n");

   }

}

/*****************************************
* This is the function to generate the shiftable,
* it is used to determine the length of the shift
*****************************************/
int shiftTable(char *p, int *Table){
   int i,j, m;
   m= strlen(p);
   for(i=0; i < MAX_ALPHABET; i++){
      Table[i]=m;
   }
   //for loop to find the right most location in the pattern of the character
   for(j =0; j <= m-2; j++){
      Table[(int)p[j]] = m-1-j;
   }

   return *Table;

}

/************************************************
* This function checks for matches between the 
* needle and the haystack. It will print out the matches
* while in the scope of the function
**********************************************/
int horspoolMatch(char *needle, char *T){

   int i,j, m, n, k;
   n = strlen(T);   // length of haystack
   m = strlen(needle);   //length of needle

   int Table[MAX_ALPHABET];   //table of shift values
   int locatMatch=0;   //variable used to find match location  

   int matches[m];  //dummy array used to store values of matches

   shiftTable(needle, Table);   //Generate the shifttable 

   printShiftTable(Table);  //print out the shift table to fit Dr. BC's output


   i = m-1;   //needle length-1

   printf("%s\n", T);
   //while (needle length-1 < length of haystack-1)
   while(i <= n-1){
      k=0;
      while((k<=m-1) &&(needle[m-1-k] == T[i-k])){
         k++;
      }
      //if k equals needle length
      if(k==m){
         printf("%*s%s---found\n", i-m+1, "", needle);   //found location
         matches[locatMatch++] = (i-m+1);   //store the match
      }
      else{
         printf("%*s%s\n", i-m+1, "", needle);  //no match
      }
      i += Table[(int)T[i]];   //increment through table
   }
   //print out the location of the matches
   printf("Matches found at locations:");
   for(j =0; j < locatMatch; j++){
      printf(" %d", matches[j]);
   }
   printf("\n");

   return -1;
   
}

