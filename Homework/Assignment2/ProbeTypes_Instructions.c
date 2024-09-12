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
**   Author:    Don Dang
**   Date:      9/11/2024
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
* 
* References:
* 1. Tutorials Points: <limits.h> Library Macros
*   - https://www.tutorialspoint.com/c_standard_library/limits_h.htm
* 2. cplusplus.com: printf
*   - https://cplusplus.com/reference/cstdio/printf/
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Over Flow Helpers Functions///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


short OverFlowShort(int num)
{
    short shortOverFlow = SHRT_MAX;
    return shortOverFlow + num;
}

int OverFlowInt(int num)
{
    int intOverFlow = INT_MAX;
    return intOverFlow + num;
}

long OverFlowLong(int num)
{
    long longOverFlow = LONG_MAX;
    return longOverFlow + num;
}

unsigned char OverFlowUnsignedChar(int num)
{
    unsigned char uCharOverFlow = UCHAR_MAX;
    return uCharOverFlow + num;
}

unsigned short OverFlowUnsignedShort(int num)
{
    unsigned short uShortOverFlow = SHRT_MAX;
    return uShortOverFlow + num;
}

unsigned int OverFlowUnsignedInt(int num)
{
    unsigned int uIntOverFlow = UINT_MAX;
    return uIntOverFlow + num;
}

unsigned long OverFlowUnsignedLong(int num)
{
    unsigned long uLongOverFlow = ULONG_MAX;
    return uLongOverFlow + num;
}

long long OverFlowLongLong(int num)
{
    long long longlongOverFlow = LLONG_MAX;
    return longlongOverFlow + num;
}

unsigned long long OverFlowUnsignedLongLong(unsigned long long num)
{
    unsigned long long uLongLongOverFlow = ULLONG_MAX;
    return uLongLongOverFlow + num;
}

void RunProgram()
{
    const int spaces = 25;
    const int numOne = 1;
    const int numZero = 0;
    printf("%*s | %s | %*s | %*s | %*s |\n", spaces, "Type", "sizeof", spaces, "min", spaces, "max", spaces, "max + 1");
    printf("%*s | %*zu | %*d | %*d | %*d |\n", spaces, "char", 6, sizeof(char), spaces, SCHAR_MIN, spaces, SCHAR_MAX, spaces, SCHAR_MAX + 1);
    printf("%*s | %*zu | %*d | %*u | %*d |\n", spaces, "short", 6, sizeof(short), spaces, SHRT_MIN, spaces, SHRT_MAX, spaces, OverFlowShort(numOne));
    printf("%*s | %*zu | %*d | %*u | %*d |\n", spaces, "int", 6, sizeof(int), spaces, INT_MIN, spaces, INT_MAX, spaces, OverFlowInt(numOne));
    printf("%*s | %*zu | %*d | %*ld | %*ld |\n", spaces, "long", 6, sizeof(long), spaces, LONG_MIN, spaces, LONG_MAX, spaces, OverFlowLong(numOne));
    printf("%*s | %*zu | %*u | %*u | %*u |\n", spaces, "unsigned char", 6, sizeof(unsigned char), spaces, numZero, spaces, UCHAR_MAX, spaces, OverFlowUnsignedChar(numOne));
    printf("%*s | %*zu | %*u | %*u | %*u |\n", spaces, "unsigned short", 6, sizeof(unsigned short), spaces, numZero, spaces, USHRT_MAX, spaces, OverFlowUnsignedChar(numOne));
    printf("%*s | %*zu | %*u | %*u | %*u |\n", spaces, "unsigned int", 6, sizeof(unsigned int), spaces, numZero, spaces, UINT_MAX, spaces, OverFlowUnsignedInt(numOne));
    printf("%*s | %*zu | %*u | %*u | %*u |\n", spaces, "unsigned long", 6, sizeof(unsigned long), spaces, numZero, spaces, ULONG_MAX, spaces, OverFlowUnsignedLong(numOne));
    printf("%*s | %*zu | %*s | %*s | %*s |\n", spaces, "float", 6, sizeof(float), spaces, "N/A", spaces, "N/A", spaces, "N/A");
    printf("%*s | %*zu | %*s | %*s | %*s |\n", spaces, "double", 6, sizeof(double), spaces, "N/A", spaces, "N/A", spaces, "N/A");
    printf("%*s | %*zu | %*lld | %*lld | %*lld |\n", spaces, "long long", 6, sizeof(long long), spaces, LLONG_MIN, spaces, LLONG_MAX, spaces, OverFlowLongLong(numOne));
    printf("%*s | %*zu | %*llu | %*llu | %*llu |\n", (int)spaces, "unsigned long long", 6, sizeof(unsigned long long), (int)spaces, (unsigned long long)numZero, (int)spaces, ULLONG_MAX, (int)spaces, OverFlowUnsignedLongLong((unsigned long long)numOne));
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
