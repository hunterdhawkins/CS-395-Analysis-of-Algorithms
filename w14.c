/******************************************
 * Id: Hawk5052
 *
 * Purpose: Impliment the Boyer Moore string matching algorithm
 * Input: Strings inputed from command line
 * Output: Matches of string
 * Compile: gcc -o w14 w14.c
 *
 *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
int shiftTable(char *, int * );
void printShiftTable(int[]);
int boyerMoore(char *, char *);

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32



//argc is the number of arguments, argv is arguments themselves
int main(int argc, char * argv[]){
   //make sure input is correct 
   if(argc <= 2){
      printf("Invalid number of arguments try again\n");

   }


   //Return the matching position of the string
   boyerMoore(argv[1], argv[2]);

   //This is a fun, but diffcult algorithm!
 


   return 0;
}

//This function is used to print out the shift table
//This was given by Dr. BC
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

//Create shifttable 
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

//Generate the good suffix table 
void goodSuffixTable(char *pat, int *bpos, int *shift, int m){
   
   int i=m;
   int j = m+1;

   int k;
   bpos[i]=j;

   while(i>0){

      while(j<=m && pat[i-1] != pat[j-1]){
         if(shift[j] ==0){
            shift[j] = j-i;
         }
         j = bpos[j];
      
      }
    i = i-1;
    j = j-1;

    bpos[i] =j;
    }

   //Insert code here
   for(k=0; k < m; k++){

      printf("%d %s*s %d\n", k, m, &pat[m-k], bpos[k]);
   }

}

//check for matches between the needle and the haystack
//needle is the needle and T is the lookup table
int boyerMoore(char *needle, char *T){

   int s =0;
   int j;
   int i;
   int m = strlen(needle);
   int n = strlen(T);

   int locatMatch =0;

   int Table[MAX_ALPHABET];

   int matches[m];

   int bpos[m+1], shift[m+1];

   for( i =0; i < m+1; i++){
      shift[i]=0;   //initialize all values to zero

   }

   goodSuffixTable(needle, bpos, shift, m);

   shiftTable(needle, Table);   //Generate the shifttable 

   printShiftTable(Table);  //print out the shift table to fit Dr. BC's output


   printf("%s\n", T);
   //while (needle length-1 < length of haystack-1)
   while(s <= n-m){
      j = m-1;
      while(j >= 0 && needle[j] == T[s+j]){
         j--;
      }
      //if k equals needle length
      if(j<0){
         printf("%*s%s---found\n", s, "", needle);   //found location
         matches[locatMatch++] = s;   //store the match
      }
      else{
         printf("%*s%s\n", s, "", needle);  //no match
      }
      s += Table[(int)T[i]];   //increment through table
   }
   //print out the location of the matches
   printf("Matches found at locations:");
   for(j =0; j < locatMatch; j++){
      printf(" %d", matches[j]);
   }
   printf("\n");

   return -1;
   
}

