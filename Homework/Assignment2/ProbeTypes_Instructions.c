/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 2, ProbeTypes.c, INSTRUCTIONS
**
** Limited license is granted for use by the following institution:
**   University of Washington PCE (Professional Continuing Education)
**   Course: Foundations of C - Autum 2024
**   The institution may share this work only with registered students of the course.
**   Registered students of the course may retain a copy of this work for their own personal educational use.
**
** This work is protected by copyright laws and shall not be shared publicly in whole or in part.
** The content may not be distributed, sold, or republished outside the limited license granted above.
**
** Development
**   Author:    Colby O'Donnell <colbster@uw.edu>
**   Developed: October 16, 2011
**   Updated:   October 21, 2023
**
** Student Solution
**   Author:    --- Enter your name here ---
**   Date:      --- Enter date here ---
**
** OBJECTIVE
**
** This program introduces aligning the output of printf, understanding the storage size
** of the data types in C, and how overflow works.  It also introduces the following
** items in C: const, <limits.h>, sizeof, short, long, double, and unsigned.
**
** INSTRUCTIONS:
**
** Write a program that, for each of the following data types listed below, prints the following
** information (listed immediately below) about each of them.
**
**   sizeof    (i.e. the number of bytes used to store that type's value)
**   minimum   (the smallest value the type can contain)
**   maximum   (the largest value the type can contain)
**   maximum+1 (1 larger than the largest value the type can contain.
**              For integral types, maximum+1 equals minimum)
**
** For maximum+1, you are deliberately overflowing the maximum value of the type by 1.
** The compiler may emit warnings regarding overflow.  You can disable those particular warnings
** for this assignment, because we are doing it on purpose as an experiment.
** 
** Make sure the maximum+1 value is of your target type, and not a bigger type.  For example, if
** you have unsigned char max holding the largest unsigned char value (usually 255) make sure
** max+1 is of type unsigned char, and not of type int. Otherwise, you could get 256 (as an int)
** instead of what you want, which is 0 (as unsigned char).
**
** Here are the types:
**   char
**   short
**   int
**   long
**   unsigned char
**   unsigned short
**   unsigned int
**   unsigned long
**   float
**   double
**
** - For floating types float and double, only the sizeof numbers are required.
**   Omit the minimum, maximum, and maximum+1.
**
** - Use printf format modifiers to neatly line up the information vertically.
**   Numbers should be right-aligned in each column.
**
** - Add #include <limits.h> and use the constants defined there.
**
** - You will not find any defined constants for unsigned minimum values.  Just use 0, since by
**   definition, the smallest unsigned value is 0.
**
** - It is OK for your program to be in one long main() function.  However try to use scope
**   (as mentioned in Commentary 1) to limit the scope and visibility of variables.
**
** - EXTRA CREDIT: For a small bonus, you may optionally add these two C99 64-bit types:
**     long long            (Insert this after long)
**     unsigned long long   (Insert this after unsigned long)
**
** TESTING:
**
** Put your program's output in a file called ProbeTypes.txt.  Since your program is only executed
** once and has no user input, this is great opportunity to run your program from the command line and
** redirect the output to the text file.
**
** On most command shells, you will type this:
**
**   ProbeTypes > ProbeTypes.txt
**
** The first 3 lines of your output should look similar to this:
**
** 
** Welcome to (Debug 32 bit) ProbeTypes.
** 
**                 Type | sizeof |                  min |                  max |              max + 1 |
**                 char |      1 |                 -128 |                  127 |                 -128 |
**                short |      2 |               -32768 |                32767 |               -32768 |
**
** The extra column spaces make room for the larger type names and numbers.
*/

#include <stdio.h>
#include <stdlib.h>

void RunProgram()
{
    printf("Not yet implemented.\n");  /* STUDENTS: Delete this line. */

    /* TODO: Implement your solution here. */
}

/*
** STUDENTS - DO NOT MODIFY below this point.
*/

/* Returns the number of bits as an unsigned int. */
static unsigned int GetBitness(void)
{
    return (unsigned int)sizeof(size_t) * 8;
}

/* Returns the name of the build (based on NDEBUG) as a string. */
static const char* GetNameOfBuild(void)
{
#ifndef NDEBUG
    return "Debug";
#else
    return "Release";
#endif
}

int main(void)
{
    printf("Welcome to (%s %d bit) ProbeTypes.\n\n", GetNameOfBuild(), GetBitness());
    RunProgram();
    return 0;
}
