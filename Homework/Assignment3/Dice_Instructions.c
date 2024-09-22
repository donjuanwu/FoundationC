/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 3, Dice.c, INSTRUCTIONS
**
** Limited license is granted for use by the following institution:
**   University of Washington PCE (Professional Continuing Education)
**   Course: Foundations of C - Autumn 2024
**   The institution may share this work only with registered students of the course.
**   Registered students of the course may retain a copy of this work for their own personal educational use.
**
** This work is protected by copyright laws and shall not be shared publicly in whole or in part.
** The content may not be distributed, sold, or republished outside the limited license granted above.
**
** Development
**   Author:    Colby O'Donnell <colbster@uw.edu>
**   Developed: October 31, 2011
**   Updated:   September 8, 2024
**
** Student Solution
**   Author:    Don Dang
**   Date:      9/18/24
**
** INSTRUCTIONS
**
** This program introduces you to tallying and summarizing results, working with
** an array, and automatically computing the static array length at compile time.
** New keywords, operands, and functions: rand(), <stdlib.h>, srand(), <time.h>,
** time(), +=
**
** Write a program that simulates rolling two dice. The first die is trustworthy
** and produces equally random rolls of 1-6. The second die is a shady character
** and has a slight tendency to roll one of the numbers more often than the rest.
**
** Your program is interactive and asks the user (once) how many rolls of both
** dice they desire.
**
** For the weighted (shady) die, alter your random number generation to slightly
** favor the number 2.  The other five numbers (1 and 3-6) should have an equal
** probability of rolling.
**
** For each die, display the following information:
** - The sequence of rolls compactly (stream of single digit numbers with no spaces or newlines).
** - The number of times each number on the die was rolled, along with the total.
** - The percentage (0-100%) each number was rolled, along with the total.  Keep 2 decimal places (e.g.: 21.67%).
** - The average number rolled (a floating point type).  Keep 2 decimal places (e.g.: 3.27)
**
** For 60 rolls, your output would look similar to this:
**
**   How many times would you like to roll each 6 sided die? 60
**   
**   Trusty Die (60 rolls): 216154266245345124215642216152422154411432651266513522611542
**   
**     The  1 was rolled:    13 ( 21.67%)
**     The  2 was rolled:    15 ( 25.00%)
**     The  3 was rolled:     3 (  5.00%)
**     The  4 was rolled:    10 ( 16.67%)
**     The  5 was rolled:    10 ( 16.67%)
**     The  6 was rolled:     9 ( 15.00%)
**                 TOTAL:   196 (100.00%)
**   
**     Average number rolled: 3.27
**   
**   Shady Die (60 rolls): 253113153521615616125221424413165322425623446552446666545121
**     The  1 was rolled:    12 ( 20.00%)
**     The  2 was rolled:    12 ( 20.00%)
**     The  3 was rolled:     6 ( 10.00%)
**     The  4 was rolled:     9 ( 15.00%)
**     The  5 was rolled:    11 ( 18.33%)
**     The  6 was rolled:    10 ( 16.67%)
**                 TOTAL:   205 (100.00%)
**
**     Average number rolled: 3.42
**
** DESIGN GUIDELINES
**
** - No additional GLOBAL variables, constants, or #defines are needed for this program.
**   Adding any will bring style point deductions.
** - Do NOT write special code to handle zero rolls.
** - One practical way to design RollShady is to define a lookup table for the rolled die numbers.
**   - Use the rand() function to generate a random index into this lookup table, which you
**     define as an array of constant integers that you manually initialize to the
**     desired die numbers.  See book section 8.1.3 to learn how to initialize an array.
**   - See book section 8.1.6 for automatically computing the number of array elements.
**   - Give the favored number more spots in the lookup table than other numbers,
**     which will give it a greater chance of being picked.  Book section 8.2.3 gives an example.
**
** TESTING
**
** - Do not bother testing less than 1 roll (0 or negative).
** - Show that all trusty numbers demonstrate equal probability.
** - Show that all but one shady number demonstrate equal probability.
** - Show that the difference between trusty and shady is:
**   - hard to tell apart with a low number of rolls.
**   - easy to tell apart with a high number of rolls.
** - Run one single test with NUM_SIDES_ON_DIE set to 10 instead of 6.
**   - Recompile your program for a 10-sided dice.
**   - Run the program once and choose 10000 for the number of rolls.
**   - Demonstrate that the trusty die works correctly.
**   - Demonstrate that the shady die has a bug.
**   - You are NOT required to fix the implementation of the shady die for 10 sides.
** - Show correct verticle alignment for differnt number of digits for both counts and percentages.
** - HINT: Include a test case showing that 100% prints readably.
** - Copy your interactive output to Dice.txt.
* Date      Developer       Activities
* 0/20/24   Don D           Added #define _CRT_SECURE_NO_WARNINGS to suppress scanf waring from Visual Studio
*/
#define _CRT_SECURE_NO_WARNINGS /*suppress Visual Studio scanf warnings*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
** This constant must be a preprocessor rather than a const int, because ANSI-C
** has the limitation that the size of an array must be known at compile time,
** and unfortunately, the compiler does not treat a const int as a constant at
** compile time, but rather as a variable that is not allowed to change.
** C99 and C++ correct this limitation, making it possible to use a constant
** integer value to define the size of an array.
**
** TODO: Change this #define to an enum constant with the same name.
*/
enum 
{
    NUM_SIDES_ON_DIE = 10
};

/*
** Stores the count (number of times) each number is rolled.
** The array has NUM_SIDES_ON_DIE storage locations.
** The array indexes are 0-based: 0 to NUM_SIDES_ON_DIE - 1.
** The die   numbers are 1-based: 1 to NUM_SIDES_ON_DIE.
**
** Having this array be global is not desirable, but we have no yet learned
** how to pass arrays as parameters to functions.
**
** TODO: Make this unsigned.  A best practice in C/C++: Use unsigned types for
** quantities that are known, by design, to be non-negative.
*/
unsigned int g_tallyCount[NUM_SIDES_ON_DIE];

/* Resets the g_tallyCount array to zero. */
void InitializeTally(void)
{
    unsigned int index;
    for (index = 0; index < NUM_SIDES_ON_DIE; index++)
    {
        g_tallyCount[index] = 0;
    }
}

/* Prints a summary of the roll statistics for one die. */
/* TODO: Make parameter const unsigned int. */
void PrintTally(const unsigned int numRolls)
{
    unsigned int index;
    unsigned int numRolled;
    unsigned int numSpaces = 5;
    float numRolledPercentage;
    unsigned int totalNumRolledCount = 0;
    float totalRolledPercentage = 0.0;
    for (index = 0; index < NUM_SIDES_ON_DIE; index++)
    {
        numRolled = g_tallyCount[index];
        totalNumRolledCount += numRolled * (index + 1);
        if (g_tallyCount[index] == 0)
        {
            numRolledPercentage = 0.0;
        }
        else
        {
            numRolledPercentage = ((float)g_tallyCount[index] / numRolls) * 100;
        } 
        totalRolledPercentage += numRolledPercentage;
        printf("%*s %*d was rolled: %*d ( %*.2f%%)\n", numSpaces, "The", 2, index + 1, numSpaces, numRolled, numSpaces, numRolledPercentage);
    }
    printf("%*s %*d (%*.2f%%) \n", 20, "TOTAL:", numSpaces, totalNumRolledCount, numSpaces, totalRolledPercentage);
    printf("%*  Average number rolled: %*.2f\n", numSpaces + 10, 2, (float) totalNumRolledCount / numRolls);

}

/* TODO: Make parameter const unsigned int. */
void RollTrusty(const unsigned int numRolls)
{
    /* TODO: Implement this function
    **
    ** 1) Call InitializeTally()
    ** 2) Roll the die, printing as you go
    ** 3) Call PrintTally()
    */
    const unsigned int titleWidth = 10;
    InitializeTally(); /*initialize global array to 0*/
    printf("%*s (%d rolls): ", titleWidth, "Trusty Die", numRolls);
    unsigned int randNum;
    unsigned int index;
    for (index = 0; index < numRolls; index++)
    {
        randNum = rand() % NUM_SIDES_ON_DIE;
        g_tallyCount[randNum]++;
        printf("%d", randNum + 1);
    }
    printf("\n");
    PrintTally(numRolls);
    
}

/* TODO: Make parameter const unsigned int. */
void RollShady(const unsigned int numRolls)
{
    /* TODO: Implement this function
    **
    ** 1) Call InitializeTally()
    ** 2) Roll the die, printing as you go
    ** 3) Call PrintTally()
    */
    const unsigned int titleWidth = 10;
    InitializeTally();
    printf("%*s (%d rolls): ", titleWidth, "Shady Die", numRolls);
    unsigned int randNum;
    unsigned int index;
    
    unsigned int numSkewed;

    if (NUM_SIDES_ON_DIE == 10)
    {
        unsigned int skewedDice[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 2, 2, 2};
        unsigned int arraySize = sizeof(skewedDice) / sizeof(skewedDice[0]);
        for (index = 0; index < numRolls; index++)
        {
            randNum = rand() % arraySize; /*generate random number from 0 up to arraySize -1*/
            numSkewed = skewedDice[randNum]; /*get the weighted value*/
            g_tallyCount[numSkewed - 1]++;
            printf("%d", numSkewed);
        }
    }
    else /*6 sided dice*/
    {
        unsigned int skewedDice[] = { 1, 2, 3, 4, 5, 6, 2, 2, 2, 2 };
        unsigned int arraySize = sizeof(skewedDice) / sizeof(skewedDice[0]);
        for (index = 0; index < numRolls; index++)
        {
            randNum = rand() % arraySize; /*generate random number from 0 up to arraySize -1*/
            numSkewed = skewedDice[randNum]; /*get the weighted value*/
            g_tallyCount[numSkewed - 1]++;
            printf("%d", numSkewed);
        }

    }

    printf("\n");
    PrintTally(numRolls);
 }

/* ---------------------------------------------- */
/* STUDENTS: Do not modify code below this point. */
/* ---------------------------------------------- */

int main(void)
{
    /*
    ** srand() seeds (initializes) the random the number generator.
    ** Call it once per execution of the entire program.
    **
    ** Call rand() for each random number you wish to obtain from the random pool.
    ** Use the modulus (%) operator to constrain the values between 0 and N-1,
    ** where N is an integer of your choosing.
    */
    srand((unsigned int)(time(0)));

    printf("How many times would you like to roll each %d sided die? ", NUM_SIDES_ON_DIE);
    {
        unsigned int numRolls = 0;

        /* Before Module 4, it is OK to ignore warnings about ignoring scanf return value. */
        (void) scanf("%d", &numRolls);

        RollTrusty(numRolls);
        RollShady(numRolls);
    }
    return 0;
}
