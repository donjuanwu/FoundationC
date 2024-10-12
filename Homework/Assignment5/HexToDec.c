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
#include <ctype.h>

/*
** Special signals when non-hex digit is read.
**
** A better design would be to separate the signals from the hex numbers. That design would require functions to
** return multiple values, using out parameters (pass by pointer).  That will be covered during Assignment 6.
** For an interesting read on this design problem, read Writing Solid Code by Steve Maguire,
** Chapter 5: "Candy-Machine Interfaces".  http://www.softwarequotes.com/printableshowquotes.aspx?id=552
*/
enum
{
	SIGNAL_NEWLINE = -1,  /* Signals '\n' character was entered */
	SIGNAL_ILLEGAL = -2,  /* Signals an illegal character was entered */
	SIGNAL_QUIT = -3  /* Signals 'Q' or 'q' was entered */
};
//const int SIGNAL_NEWLINE = -1;  /* Signals '\n' character was entered */
//const int SIGNAL_ILLEGAL = -2;  /* Signals an illegal character was entered */
//const int SIGNAL_QUIT = -3;  /* Signals 'Q' or 'q' was entered */

/*
** Reads and consumes the standard input, using getchar(), until newline ('\n') or end of file (EOF)
** are encountered.  The newline ('\n') character is also consumed.
*/
void SkipRestOfLine(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n') break; /*move to next iteration, skip new line*/
	}
}

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
int ReadHexDigit(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == 'q' || ch == 'Q')
		{
			SkipRestOfLine(); /*clear input buffer*/
			printf("ERROR: Q or q was entered, return\n");
			return SIGNAL_QUIT;
		}
		if (ch == '\n')
		{
			//SkipRestOfLine(); /* skip calling because newline is already consumed*/
			printf("ERROR: Nothing was entered, return\n");
			return SIGNAL_NEWLINE;
		}
		if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'F') && (ch < 'a' || ch > 'f'))
		{
			SkipRestOfLine(); /*clear input buffer*/
			printf("ERROR: Unrecognized hex number, return\n");
			return SIGNAL_ILLEGAL;
		}


		switch (ch)
		{
			/* handle 0 - 9*/
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			return ch - '0'; /* subtract '0' to get numeric value*/
			/* handle A - F*/
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
			return ch - 'A'; /* convert upper case A-F to get numeric value from 10 - 15*/
			/* hand a -f*/
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
			return ch - 'a'; /* convert upper case a-f to get numeric value from 10 - 15*/
		default:
			return SIGNAL_ILLEGAL; /* illegal character*/

		}
	}

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
	const unsigned int maxDigits = (GetBitness() / 4); /*reduce to the maximum hex digits to enter*/
	unsigned int countHex = 0; /*keep a count on valid hex value entered*/
	unsigned long decValue = 0;
	int retReadHex;
	/*printf("Enter a non-negative base %d (hexadecimal) number to be converted to base %d.\n", base16, base10);
	printf("Enter 'q' or 'Q' to quit, and enter no more than %d digits: ", maxDigits);*/
	/*retReadHex = ReadHexDigit();
	if (retReadHex == SIGNAL_ILLEGAL)
	{
		printf("ERROR: Unrecognized hex number, try again.\n");
		return 1;

	}
	if (retReadHex == SIGNAL_NEWLINE)
	{
		printf("ERROR: Nothing was entered, try again.\n");
		return 1;
	}
	if (retReadHex == SIGNAL_QUIT)
	{
		return 0;
	}
	if (countHex > maxDigits)
	{
		printf("ERROR: Cannot enter more than 8 hex digits, try again.\n");
		return 1;
	}
	while (retReadHex > SIGNAL_NEWLINE)
	{
		countHex += 1;
		decValue += retReadHex;
		unsigned int index;
		for (index = 0; index < countHex; index++)
		{
			decValue *= base16;
		}
		printf("Decimal value: %d", decValue);
	}*/

	do /*display the menu at least once*/
	{
		printf("Enter a non-negative base %d (hexadecimal) number to be converted to base %d.\n", base16, base10);
		printf("Enter 'q' or 'Q' to quit, and enter no more than %d digits: ", maxDigits);
		retReadHex = ReadHexDigit();
		switch (retReadHex)
		{
		case SIGNAL_ILLEGAL:
			printf("ERROR: Unrecognized hex number, try again.\n");
			return 1;
		case SIGNAL_NEWLINE:
			printf("ERROR: Nothing was entered, try again.\n");
			return 1;
		case SIGNAL_QUIT:
			return 0;

		default: 
			countHex += 1;
			decValue += retReadHex;
			unsigned int index;
			for (index = 0; index < countHex; index++)
			{
				decValue *= base16;
			}
			printf("Decimal value: %d", decValue);
		}
	} while (retReadHex > -1); /*evaluate after switch block*/
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
	while (ConvertNumber())
	{
		//to do
	}
	printf("\nGoodbye.\n");
	return 0;
 }
