// gcc main.c -o bf && ./bf
// above is how to run. uses compiler to generate you name-specified output, then runs it.
// Author: Trent Conley and Rohan Shah
// Date: April 3, 2020
// Class: ATCS, Block G and Block B



// DONE read in the file
// DONE check file path if valid on operating system
// DONE parse file and throw away invalid characters
// DONE check if array is valid --> counter (cannot go negative and has to end at zero)
 // if valid: execute code
 // else: return specific error type

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NUM_BYTES 50000

//checks to see if the file is valid (matching parentheses error)
bool checkMatchingParens(char arr[]) {
	counter = 0
	for(int i = 0; i < sizeof(arr); i = i + 1){
		if(counter < 0) {
			return false;
		} else {
			if(arr[i] == '(') {
				counter = counter + 1;
			}
			if(arr[i] == ')') {
				counter = counter - 1;
			}
		}
	}
	if(counter < 1) {
		return false;
	}
	return true;
}

int main ()
{
   File *fp;
   char c;
   // int n = 0;
   char tokens[NUM_BYTES];
   char file_contents[10000];
   int i = 0;
   fp = fopen("file.txt","r");
   if(fp == NULL)
   {
      printf("Error in opening file");
      return(-1);
   } do
   {
      c = fgetc(fp);
      if(feof(fp))
      {
         break;
      }
      //checks if c is valid character or not
      //append c into an array if valid character. if invalid, do nothing
      if((c == '<') || (c == '>') || (c == '+') || (c == '-') || (c == '(') || (c == ')') || (c == '*'))
      {
      	file_contents[i] = c
      	i = i + 1
      }
   }
   while(1);
   fclose(fp);

   //
   bool check;
   check = checkMatchingParens(file_contents);
   if(check == false){
   	 printf("File is invalid. Matching Parentheses Error!");
   	 return(0);
   }
   return(0);
}