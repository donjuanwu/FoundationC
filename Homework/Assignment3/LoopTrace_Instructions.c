/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 3, LoopTrace.c, INSTRUCTIONS
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
**   Developed: October 28, 2011
**   Updated:   September 9, 2023
**
** Student Solution
**   Author:    Don Dang
**   Date:      9/17/2024
**
** INSTRUCTIONS:
**
** This program introduces you to the mechanics of the while and for loops in C.
** New keywords, operands, and functions: while, for, ++, --, <, <=, >, >=

** The test driver code for the program is already written. You will finish the
** program by implementing each of the 8 looping functions, which represent the
** 4 most common ways of looping.
**
** There are 4 functions using while loops, and 4 more functions using for loops.
** Each set of 4 functions performs the loop in the following ways:
**
**           StartLessEnd - Loop increases from start to 1 less than end
**      StartLessEqualEnd - Loop increases from start to end
**        StartGreaterEnd - Loop decreases from start to 1 more than end
**   StartGreaterEqualEnd - Loop decreases from start to end
**
** Examine the given main() code to see the order in which the functions will be
** called.  For each of the 8 functions, implement the appropriate loop with
** formatted printf statements.
**
** The first quarter of the program's output should look identical to this:
**
**          WhileTrace_StartLessEnd (0, 0) starting: done!
*           WhileTrace_StartLessEnd (0, 1) starting: 0 done!
*           WhileTrace_StartLessEnd (0, 2) starting: 0 1 done!
*           WhileTrace_StartLessEnd (0, 3) starting: 0 1 2 done!
*           WhileTrace_StartLessEnd (0, 3) starting: 0 1 2 done!
*           WhileTrace_StartLessEnd (1, 3) starting: 1 2 done!
*           WhileTrace_StartLessEnd (2, 3) starting: 2 done!
*           WhileTrace_StartLessEnd (3, 3) starting: done!
*           WhileTrace_StartLessEnd (4, 3) starting: done!
*
*			ForTrace_StartLessEnd (0, 0) starting: done!
*           ForTrace_StartLessEnd (0, 1) starting: 0 done!
*           ForTrace_StartLessEnd (0, 2) starting: 0 1 done!
*			ForTrace_StartLessEnd (0, 3) starting: 0 1 2 done!
*			ForTrace_StartLessEnd (1, 3) starting: 1 2 done!
*			ForTrace_StartLessEnd (2, 3) starting: 2 done!
*			ForTrace_StartLessEnd (3, 3) starting: done!
*			ForTrace_StartLessEnd (4, 3) starting: done!
**
** TESTING
**
** The testing will be automated instead of manual. The test code in main was
** already written, so you need only run the program one time,
** redirecting the output to the test file via a command similar to this:
**
**   LoopTrace > LoopTrace.txt
**
** GRADING
**
** Two small components of the grade are worth noting...
**
** - Make your program output be identical to the example above.
** - Make your code conform to strict ANSI-C.
**   - ANSI-C does not allow variable to be declared after statements in the same block of code.
**   - ANSI-C does not allow declaring a variable in the for loop initializer. (C99 and C++ support this)
*
*
* Date          Developer          Activities
* 9/17/24       Don D              Started working on assignment3
*/

#include <stdio.h>

/*
** This global constant is used to enforce consistency across
** all functions that depend on this concept, to enforce a fixed width of all
** function names printed.
** The g_ makes it plainly obvious this is a global rather than local variable.
** The variable is declared constant for safety, since there is no desire to
** change the value during execution.
**
** Take advantage of the * modifier in printf() as described in section 22.3.2
** under "Minimum field width".
*/
const int g_functionNameWidth = 32;


/*
** TODO: Implement these functions.
** TODO: As a best practice, make unmodified parameters const to protect them from
**       accidental, unintended modification in the body of the function.
** TODO: Each call to these functions emits 1 line of output as seen in the
**       example test output above.
*/

void WhileTrace_StartLessEnd(int start, const int end)
{
	char funcName[] = "WhileTrace_StartLessEnd";
	printf("%*s (%d, %d) starting: ", g_functionNameWidth, funcName, start, end);
	while (start < end)
	{
		printf("%d ", start);
		start++;
	}
	printf("done!\n");
}

void ForTrace_StartLessEnd(int start, const int end)
{
	char funcName[] = "ForTrace_StartLessEnd";
	printf("%*s (%d, %d) starting: ", g_functionNameWidth, funcName, start, end);
	for (start; start < end; start++)
	{
		printf("%d ", start);
	}
	printf("done!\n");

}

void WhileTrace_StartLessEqualEnd(int start, const int end)
{
	const char* funcName = "WhileTrace_StartLessEqualEnd"; /*pointer to a string literal, string literal stored in read-only part of memory*/
	printf("%*s (%d, %d) starting: ", g_functionNameWidth, funcName, start, end);
	while (start <= end)
	{
		printf("%d ", start);
		start++;
	}
	printf("done!\n");

}

void ForTrace_StartLessEqualEnd(int start, const int end)
{
	const char* funcName = "ForTrace_StartLessEqualEnd";
	printf("%*s (%d, %d) starting: ", g_functionNameWidth, funcName, start, end);
	for (start; start <= end; start++)
	{
		printf("%d ", start);
	}
	printf("done!\n");

}

//void WhileTrace_StartGreaterEnd      (int start, int end);
//void WhileTrace_StartGreaterEqualEnd (int start, int end);



//void ForTrace_StartGreaterEnd        (int start, int end);
//void ForTrace_StartGreaterEqualEnd   (int start, int end);
//
///* ---------------------------------------------- */
///* STUDENTS: Do not modify code below this point. */
///* ---------------------------------------------- */

void TraceBoth_StartLessEnd(const int start, const int end)
{
	WhileTrace_StartLessEnd(start, end);
	ForTrace_StartLessEnd(start, end);
}



void TraceBoth_StartLessEqualEnd(const int start, const int end)
{
	WhileTrace_StartLessEqualEnd(start, end);
	ForTrace_StartLessEqualEnd(start, end);
}

//void TraceBoth_StartGreaterEnd(const int start, const int end)
//{
//    WhileTrace_StartGreaterEnd(start, end);
//    ForTrace_StartGreaterEnd(start, end);
//}
//
//void TraceBoth_StartGreaterEqualEnd(const int start, const int end)
//{
//    WhileTrace_StartGreaterEqualEnd(start, end);
//    ForTrace_StartGreaterEqualEnd(start, end);
//}

int main(void)
{
	TraceBoth_StartLessEnd(0, 0);
	TraceBoth_StartLessEnd(0, 1);
	TraceBoth_StartLessEnd(0, 2);
	TraceBoth_StartLessEnd(0, 3);
	TraceBoth_StartLessEnd(1, 3);
	TraceBoth_StartLessEnd(2, 3);
	TraceBoth_StartLessEnd(3, 3);
	TraceBoth_StartLessEnd(4, 3);

	TraceBoth_StartLessEqualEnd(0, 0);
	TraceBoth_StartLessEqualEnd(0, 1);
	TraceBoth_StartLessEqualEnd(0, 2);
	TraceBoth_StartLessEqualEnd(0, 3);
	TraceBoth_StartLessEqualEnd(1, 3);
	TraceBoth_StartLessEqualEnd(2, 3);
	TraceBoth_StartLessEqualEnd(3, 3);
	TraceBoth_StartLessEqualEnd(4, 3);

	/*TraceBoth_StartGreaterEnd(0, 0);
	TraceBoth_StartGreaterEnd(1, 0);
	TraceBoth_StartGreaterEnd(2, 0);
	TraceBoth_StartGreaterEnd(3, 0);
	TraceBoth_StartGreaterEnd(3, 1);
	TraceBoth_StartGreaterEnd(3, 2);
	TraceBoth_StartGreaterEnd(3, 3);
	TraceBoth_StartGreaterEnd(3, 4);

	TraceBoth_StartGreaterEqualEnd(0, 0);
	TraceBoth_StartGreaterEqualEnd(1, 0);
	TraceBoth_StartGreaterEqualEnd(2, 0);
	TraceBoth_StartGreaterEqualEnd(3, 0);
	TraceBoth_StartGreaterEqualEnd(3, 1);
	TraceBoth_StartGreaterEqualEnd(3, 2);
	TraceBoth_StartGreaterEqualEnd(3, 3);
	TraceBoth_StartGreaterEqualEnd(3, 4);*/

	return 0;
}
