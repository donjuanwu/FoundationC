/*
** Copyright (C) August 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 1, Mistakes.c, INSTRUCTIONS
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
**   Developed: August 27, 2011
**   Updated:   August 24, 2024
**
** Student Solution
**   Author:    Don Dang
**   Date:      9/7/2024
**
** OBJECTIVE
**
** Learn to fix a broken program, compile, and run it.
** You are exposed to an introductory C program with comments,
** compiler errors, console display, and special characters.
** You are introduced to main(), printf(), void, #include <stdio.h>,
** int, return, and =.
**
** INSTRUCTIONS
**
** This program should produce this output on the console (terminal, command line):
**
**   Hello world, this is Assignment 1!
**   This program prints 3 lines to the screen.
**   I wish I was perfect, but alas I am not.
**
** But there are 11 mistakes in the code below.
**
** - Add comments to the bottom of the file (NOT inside the code) that describe
**   each mistake and why it is necessary or good practice.
** - Then fix the mistake, compile the program, and run it.
** - As part of your solution, create a text file Mistakes.txt, and copy and paste
**   the program's output to that file.
**
** - Test this program manually, by running it interactively and trying test cases as a human user.
**   Copy your test session from the console and paste into Convert.txt.
**
** TESTING
*  Mistakes                                      Comments
*  01. Thanks has no begining  '/*'              Removed  ending comment after mistakes
*  02. incosistent naming convention             set all variable name to camel case
*  03. multiple variables declare on same line   declare each variable on each separate line
*  04. declare assignmentNumber w/o initialize   declare and initialize
*  05. Incorrect inline comment for numLines     Correct comment to 3 but then decide to remove the comment
*  06. Missing format specifier for %d           Include "!\n, assignmentNumber"
*  07. Missing format specifier for %d           Include \n, numLines
*  08. Incorrect new line return                 Remove !\n in front of the sentence
*  09. Incorrect new line return                 Add \n to end of sentence
*  10. Return 1 is not correct                   Replace 1 with 0
*
** Date     Developer       Activities
*  9/7/24   Don D.          Begin compiling and fix mistakes and testing
*
*
*/

//#include <stdio.h>
//
///* Please help me fix all my goofy mistakes.
//Thanks! 
//*/
//int main(void)
//{
//    int assignmentNumber = 1;
//    int numLines = 3; 
//
//    // output info
//	printf("Hello world, this is Assignment %d!\n", assignmentNumber);
//    printf("This program prints %d lines to the screen.\n", numLines);
//	printf("I wish I was perfect, but alas I am not.\n");
//
//    // return 0 to indicate success execution
//    return 0;
//}
