/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 5, HexToDec.c, INSTRUCTIONS
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
**   Developed: October 10, 2011
**   Updated:   October 9, 2024
**
** Student Solution
**   Author:    Don Dang
**   Date:      10/11/24
**
** Date         Developer       Activities
** 10/11/24     Don D           Started HexToDec.c
** 
*/

#include <stdio.h>

/*
** Special signals when non-hex digit is read.
**
** A better design would be to separate the signals from the hex numbers. That design would require functions to
** return multiple values, using out parameters (pass by pointer).  That will be covered during Assignment 6.
** For an interesting read on this design problem, read Writing Solid Code by Steve Maguire,
** Chapter 5: "Candy-Machine Interfaces".  http://www.softwarequotes.com/printableshowquotes.aspx?id=552
*/
const int SIGNAL_NEWLINE    = -1;  /* Signals '\n' character was entered */
const int SIGNAL_ILLEGAL    = -2;  /* Signals an illegal character was entered */
const int SIGNAL_QUIT       = -3;  /* Signals 'Q' or 'q' was entered */

/*
** Reads a single hex digit from standard input using getchar().
**   - If a hex digit character is read, returns 0 to 15.
**   - If a newline character is read, returns SIGNAL_NEWLINE.
**   - If an illegal character is read, returns SIGNAL_ILLEGAL.
**   - If 'q', 'Q', or EOF is read, returns SIGNAL_QUIT.
**
** Does NOT print anything to the user.
**
** Hint: Colby's solution is 7 lines long (counting only those with code between the outer braces).
*/
int ReadHexDigit(void);

/*
** Reads and consumes the standard input, using getchar(), until newline ('\n') or end of file (EOF)
** are encountered.  The newline ('\n') character is also consumed.
*/
void SkipRestOfLine(void)
{
    while (getchar() != EOF);
}

/*
** Converts a hexadecimal number entered by the user into a decimal number, and prints
** the answer to the console.
**
** Returns 1 (true) to signal the program to keep running, or 0 (false) to signal the program to quit.
** A better design than returning int would be to return a Boolean (bool), so it was clear
** there are only two values, true and false, that are returned from this function.
** We will introduce the bool type in Assignment 6.
**
** All printing to the user is done in this function.
**
** Hint: Colby's solution is 27 lines long (counting only those with code between the outer braces).
*/
int ConvertNumber(void)
{
    const unsigned int base16 = 16;
    const unsigned int base10 = 10;
    printf("Enter a non-negative base %d (hexadecimal) number to be converted to base %d.\n", base16, base10);
    printf("Enter 'q' or 'Q' to quit, and enter no more than %d digits: ", GetBitness());
    
    {

        unsigned int ch;
        while ((ch = getchar()) != EOF)
        {
            return 0;
        }
    }


    return 0;
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
    printf("Welcome to (%s %d bit) HexToDec.\n\n", GetNameOfBuild(), GetBitness());
    while (ConvertNumber()) continue;
    printf ("\nGoodbye.\n");
    return 0;
}
