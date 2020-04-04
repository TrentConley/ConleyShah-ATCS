// clang bfinterpreterc -o bfinterpreter
// ./bfinterpreter file.bf.txt
// above is how to run. uses compiler to generate you name-specified output, then runs it.
// Author: Trent Conley and Rohan Shah
// Date: April 3, 2020
// Class: ATCS, Block G and Block B

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define MAXSIZE 10000
#define NUM_BYTES 50

//declaring all valid characters as constants
const char lc = '<';
const char rc = '>';
const char a = '+';
const char s = '-';
const char lp = '(';
const char rp = ')';
const char ast = '*';

//increases the value of the array where the pointer A is pointing by 1
void plus(char arr[], int* pos_a)
{
    //checking for memory wrapping
    if ((int)arr[*pos_a] == 255)
    {
        arr[*pos_a] = (char)0;
    }
    else
    {
      arr[*pos_a] = arr[*pos_a] + 1;
    }

}

//decreases the value of the array where the pointer A is pointing by 1
void minus(char arr[], int* pos_a)
{
    //checking for memory wrapping
    if ((int)arr[*pos_a] == 0)
    {
        arr[*pos_a] = (char)255;
    }
    else
    {
      arr[*pos_a] = arr[*pos_a] - 1;
    }
   // ok so i realize that this will end up with just -1 if you just enter '-' as your runes
   // this is ok however because (char) = 255 because of the wrapping.
}

//moves the array pointer one to the left
void mov_L(char arr[], int* pos_a)
{
    //checking if already on the furthest left position
    if (*pos_a == 0)
    {
        printf("You can't do that. You can't move to the left of the left most person. \n \n");
        exit(0);
    }
    //no else here because i want the program to break.

    *pos_a = *pos_a - 1;
    //above is to kill the program if bad.
}

//moves the array pointer one to the right
void mov_R(char arr[], int* pos_a)
{
//    printf("%d\n", *pos_a);
    //checking if going out of array index to the right
    if (*pos_a == NUM_BYTES-1)
    {
        printf("You can't do that. You can't move to the right of the right most person. \n \n");
        exit(0);
    }
    //no else here because i want the program to break.
    *pos_a = *pos_a + 1;
    //above is to kill the program if bad.
}

//finds the matching closed parenthese having been given the pointer to the open parenthese
void findclose(char tablet[], int* pos_t)
{
    int c = 1;
    //takes running tally of open and closed to find match
    while (c > 0)
    {
        *pos_t = *pos_t + 1;
        if (tablet[*pos_t] == ')')
        {
            c = c - 1;
        }
        else if (tablet[*pos_t] == '(')
        {
            c = c + 1;
        }
    }
}

//finds the matching opeen parenthese having been given the pointer to the closed parenthese
void findopen(char tablet[], int* pos_t)
{

    int c = 1;
    //takes running tally of open and closed to find match
    while (c > 0)
    {

        *pos_t = *pos_t - 1;
        if (tablet[*pos_t] == '(')
        {
            c = c - 1;
        }
        else if (tablet[*pos_t] == ')')
        {
            c = c + 1;
        }
    }
}

//deals with the token of an open parenthese and calls findclose() to execute
void open_p(char arr[], char tablet[], int* pos_a, int* pos_t)
{
    if (arr[*pos_a] == 0)
    {
        findclose(tablet, pos_t);
        //auto- edits in the heap :)
    }
    else
    {
        *pos_t = *pos_t + 1;
    }
}

//deals with the tokene of a closed parenthese and calls findopen() to execute
void close_p(char arr[], char tablet[], int* pos_a, int* pos_t)
{
    if (arr[*pos_a] == 0)
    {
        *pos_t = *pos_t + 1;
        //auto- edits in the heap :)
    }
    else
    {
        findopen(tablet, pos_t);
    }
}

//converts int value to ascii
void yell(char arr[], int* pos_a)
{
    char c = (char) arr[*pos_a];
    printf("%c", c);
}

//control flow for execution of a valid file
void flow(char tablet[], char arrs[], int* pos_t, int* pos_a)
{
//    printf("halp");
    char mychar = tablet[*pos_t];
    if (mychar == '+')
    {
        plus(arrs, pos_a);
        *pos_t = *pos_t + 1;

    }
    else if (mychar == '-')
    {
        minus(arrs, pos_a);
        *pos_t = *pos_t + 1;
    }
    else if (mychar == '(')
    {
        open_p(arrs, tablet, pos_a, pos_t);
    }
    else if (mychar == ')')
    {
        close_p(arrs, tablet, pos_a, pos_t);
    }
    else if (mychar == '<')
    {
        mov_L(arrs, pos_a);
        *pos_t = *pos_t + 1;
    }
    else if (mychar == '>')
    {
        mov_R(arrs, pos_a);
        *pos_t = *pos_t + 1;
    }
    else if (mychar == '*')
    {
        yell(arrs, pos_a);
        *pos_t = *pos_t + 1;
    }
}

//sets all values of an array to zero --> eliminates all confusing random numbers
void init0(char a[], int size)
{
    for (int i = 0; i < size; i ++)
    {
        a[i] = 0;
    }
}

//prints out every element in the given array (this method was used for testing purposes)
void print(char a[], int size)
{
    for (int i = 0; i < size; i ++)
    {
        printf("%d\n", a[i]);
    }
}

//This method checks if the given array of chars contains matching parentheses. 
bool balanced_parentheses(char* r) {
  int counter = 0;

  for(int i = 0; i < strlen(r); i = i + 1)
  {
    //if negative, a closed parentheses must be in front of a open parentheses
    if(counter < 0)
    {
      return false;
    } else {
      if(r[i] == '(')
      {
        counter = counter + 1;
      }
      if(r[i] == ')')
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
  char t[MAXSIZE]; //creating a massive array
  //opens and reads the file
  FILE* fp = fopen("file.bf.txt", "r");
  if (fp == NULL)
  {
    printf("Couldn't open file!\n");
    exit(1);
  }
  int i = 0;
  //running through entire file character by character
  while(feof(fp) == false) 
  {
    //taking one char at a time from the file
    char c = fgetc(fp);
    //checking if c is a valid character
    if((c == lc) || (c == rc) || (c == a) || (c == s) || (c == lp) || (c == rp) || (c == ast)) 
    {
      t[i] = c;
      i++;
    }
  }
  //printf("%d", i);
  fclose(fp);

  char tablet[i];

  for(int h = 0; h < i; h++)
  {
    tablet[h] = t[h];
    //printf("%c", tablet[h]);
  }

  //checking to see if the array has no contents
  if(i == 0)
  {
    puts("No valid contents inside the file.");
    exit(0);
  }

  if (balanced_parentheses(tablet) == false) 
  {
    puts("Invalid file. Parentheses do not match.");
    exit(0);
  }
    //declaring shit
    int pos_tablet = 0;
    int *pos_tablet_ptr = malloc(sizeof(int)); // pointer to the tablet or array
    *pos_tablet_ptr = 0;

    int pos_arrs = 0;

    int *pos_arr_ptr = malloc(sizeof(int));
    *pos_arr_ptr = 0; // pointer to all of the people
    //printf(*pos_arr_ptr);

    char arrs[NUM_BYTES];
    init0(arrs, sizeof(arrs));
    while ((int) *pos_tablet_ptr < sizeof(tablet))
    {
      flow(tablet, arrs, pos_tablet_ptr, pos_arr_ptr);
    }

//    print(arrs, sizeof(arrs));

  free(pos_arr_ptr);
  free(pos_tablet_ptr);
  exit(0);
}