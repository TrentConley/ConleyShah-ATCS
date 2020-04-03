// gcc execute.c -o bf && ./bf
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

#define NUM_BYTES 5
#define MAX_SIZE 255

void plus(char arr[], int* pos_t)
{
    if (arr[*pos_t] == (char) MAX_SIZE)
    {
        arr[*pos_t] = 0;
    }
    else
    {
      arr[*pos_t] = arr[*pos_t] + 1;
    }

}

void minus(char arr[], int* pos_t)
{
    if (arr[*pos_t] == 0)
    {
        arr[*pos_t] = (char) MAX_SIZE;
        printf("hit\n");
    }
    else
    {
      arr[*pos_t] = arr[*pos_t] - 1;
    }
}


void mov_L(char arr[], int* pos_t)
{
    if (*pos_t == 0)
    {
        printf("You can't do that. You can't move to the left of the left most person. \n \n");
        exit(0);
    }
    //no else here because i want the program to break.

    *pos_t = *pos_t - 1;
    //above is to kill the program if bad.
}

void mov_R(char arr[], int* pos_t)
{
    if (*pos_t == NUM_BYTES-1)
    {
        printf("You can't do that. You can't move to the right of the right most person. \n \n");
        exit(0);
    }
    //no else here because i want the program to break.
    *pos_t = *pos_t + 1;
    //above is to kill the program if bad.
}

void open_p(char arr[], int* pos_t)
{


}

void flow(char program[], char arrs[], int pos_p, int* pos_a)
{
    char mychar = program[pos_p];
    if (mychar == '+')
    {
        plus(arrs, pos_a);
    }
    else if (mychar == '-')
    {
        minus(arrs, pos_a);
    }
    else if (mychar == '(')
    {
        // open_p()
    }
    else if (mychar == ')')
    {
        // close_p()
    }
    else if (mychar == '<')
    {
        mov_L(arrs, pos_a);
    }
    else if (mychar == '>')
    {
        mov_R(arrs, pos_a);
    }
    else if (mychar == '*')
    {
        //yell()
    }

    // incriment pos_a by 1.
//    *pos_a = *pos_a + 1;
//    printf("pos_a = %d\n", (*pos_a));


}
void init0(char a[], int size)
{
    for (int i = 0; i < size; i ++)
    {
        a[i] = 0;
    }
}
void print(char a[], int size)
{
    for (int i = 0; i < size; i ++)
    {
        printf("%d\n", a[i]);
    }
}

int main ()
{
//    declaring some shit
    int pos_program = 0;

    int pos_arrs = 0;

    int *pos_arr_ptr = malloc(sizeof(int));
    *pos_arr_ptr = 0;
    //printf(*pos_arr_ptr);


    char program[6] = {'>','+', '+', '+', '>', '+'};
    char arrs[NUM_BYTES];
    init0(arrs, sizeof(arrs));
    int size = sizeof(program);

    while (pos_program < size)
    {
        flow(program, arrs, pos_program, pos_arr_ptr);
        pos_program = pos_program + 1;
    }
    print(arrs, sizeof(arrs));


    

}



//checks to see if the file is valid (matching parentheses error)
//line of tribe members and points at one member at a time. Sample state:
//
//[0][0][0][0][0][0][0][0][0][0][0][0]
// ^
//DP
//When the Divine Pointress executes a ‘>’ rune, she moves one step to the right, pointing to a new member of the tribe. When she executes a ‘<’ rune, she moves one step to the left. See notes on wrapping behavior for what should happen at the boundaries of the data region.
//
//When the Divine Pointress executes a ‘+’ rune, she instructs the person she is currently pointing at to add a pebble to their bag. When she executes a ‘-’ rune, she instructs them to remove one. See later notes on wrapping behavior around empty/full bags.
//
//When the Divine Pointress sees a ‘(‘ rune, she asks the person she is currently pointing at how many pebbles are in their bag. Depending on the result, she does one of two things:
//If the bag of the current person contains zero pebbles, she skips forward to the next matching ‘)’ rune on her stone tablet.
//If the bag of the current person has one or more pebbles, she proceeds to execute the next rune on the tablet.
//
//When the Divine Pointress sees a ‘)’ rune, she does one of two things:
//If the bag of the current person contains zero pebbles, she proceeds to execute the next rune on her tablet.
//If the bag of the current person contains one or more pebbles, she jumps back to the prior matching ‘(‘ rune on her stone tablet.
//
//Finally, when the Divine Pointress sees a * rune, she “yells out” (printf()s) the corresponding ASCII character to the number of pebbles in the bag she is pointing at.











