/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 3, IntPow.c (OPTIONAL), INSTRUCTIONS
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
**   Developed: October 14, 2011
**   Updated:   September 8, 2024
**
** Student Solution
**   Author:    --- Enter your name here ---
**   Date:      --- Enter date here ---
**
** INSTRUCTIONS
**
** Write an integer version of the pow() function, called IntPow, which takes an
** int base and unsigned int power, and returns the integer result.
**
** Definition: pow(base, exponent) raises base to the power of exponent.  Thus:
**             1 * base * base * ... * base, repeated exponent number of times
**
** The C90 pow() function uses double for its parameters and return,
** as described in these references.
**   http://www.cplusplus.com/reference/cmath/pow/
**   http://en.cppreference.com/w/c/numeric/math/pow
**
** TESTING
**
** Your testing will be automated instead of manual.
** The main() function that you write will drive the testing of this program.
** You will execute the program one time, redirecting the output
** to the test file via a command similar to this:
**
**   IntPow > IntPow.txt
**
** Neatly print out your input values, the answer returned by IntPow(), along with
** the expected result.  Align the output vertically, as shown below.
** You may calculate the expected results by hand and hard code those numbers into
** your test code in main().
**
** Provide a modest number of test cases that demonstrate results at the boundary
** conditions are correct.  Do not test negative values for power, nor large numbers
** that will overflow.  My solution has 20 test cases.
**
** Make your output look like this:
**
**   IntPow (  2, 3) =     8 (expected     8)
**   IntPow ( 10, 0) =     1 (expected     1)
**   IntPow ( 10, 1) =    10 (expected    10)
*/

/* TODO: Implement the calculation.  Note that this function does not print. */
/* TODO: Make both parameters const. */
int IntPow(int base, unsigned int power);

//int main(void)
//{
//    /* TODO: Your test cases go here. */
//    /* TODO: There is an opportunity to consolidate repetitious printf code. */
//
//    return 0;
//}
