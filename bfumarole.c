#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define TSIZE 50000
#define MAXSIZE 10000

const char lc = '<';
const char rc = '>';
const char a = '+';
const char s = '-';
const char lp = '(';
const char rp = ')';
const char ast = '*';

//This method checks if the given array of chars contains matching parentheses. 
bool balanced_parentheses(char* ritual) {
  int counter = 0;
  for(int i = 0; i < strlen(ritual); i = i + 1)
  {
    //if negative, a closed parentheses must be in front of a open parentheses
    if(counter < 0)
    {
      return false;
    } else {
      if(ritual[i] == '(')
      {
        counter = counter + 1;
      }
      if(ritual[i] == ')')
      {
        counter = counter - 1;
      }
    }
  }
  if(counter == 0)
  {
    return true;
  }
  return false;
}

int main(int argc, char** argv) 
{
  char file_contents[MAXSIZE]; //creating the array with all the valid chars in it
  unsigned char tribe[TSIZE] = {0}; //unassigned array for the tribe ... wrapping taken care of

  //opens and reads the filee
  FILE* fp = fopen("file.bf.txt", "r");
  if (fp == NULL)
  {
    printf("Couldn't open file!\n");
    return(1);
  }
  int i = 0;
  while(feof(fp) == false) 
  {
    //taking one char at a time from the file
    char c = fgetc(fp);
    //checking if c is a valid character
    if((c == lc) || (c == rc) || (c == a) || (c == s) || (c == lp) || (c == rp) || (c == ast)) 
    {
      file_contents[i] = c;
      i++;
    }
  }
  fclose(fp);

  if (balanced_parentheses(file_contents) == false) 
  {
    puts("Invalid file. Parentheses do not match.");
    return(0);
  }
//execute code here
  return(0);
}