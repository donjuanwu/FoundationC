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
**   Author:    Don Dang
**   Date:      9/21/24
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
* 
* Date      Developer       Activities
* 9/21/24   Don D           Added #include <stdio.h>
* 
*/
#include <stdio.h>

/* TODO: Implement the calculation.  Note that this function does not print. */
/* TODO: Make both parameters const. */
int IntPow(const int base, const unsigned int power)
{
    if (base == 0 && power == 0)
    {
        return 1; /*define 0^0 as 1 for practical purposes*/
    }
    
    if (power == 0)
    {
        return 1; /*any base to the power of 0 is 1*/
       
    }
    /*
    * create scope variables
    * exponent is greater than 0
    */
    { 
        int result = 1; 
        unsigned int index = 0;
        for (index = 0; index < power; index++)
        {
            result *= base;
        }
        return result;
    };
    
}
void PrintIntPowerResult(const int base, const unsigned int power, const int result, const int expected)
{
    unsigned int numSpaces = 10;
    char funcName[] = "IntPow";
    printf("%*s (   %3d, %3d) = %*d (expected %*d)\n", numSpaces, funcName, base, power, numSpaces + 5, result, numSpaces + 5, expected);
}

int main(void)
{
    /* TODO: Your test cases go here. */
    /* TODO: There is an opportunity to consolidate repetitious printf code. */
    int base;
    unsigned int power;
    int result;
    int expected;
    unsigned int numSpaces = 10;
    char funcName[] = "IntPow";

    base = -10;
    power = 0;
    result = IntPow(base, power);
    expected = 1;
    PrintIntPowerResult(base, power, result, expected);
    
    base = 10;
    power = 0;
    result = IntPow(base, power);
    expected = 1;
    PrintIntPowerResult(base, power, result, expected);

    base = 10;
    power = 1;
    result = IntPow(base, power);
    expected = 10;
    PrintIntPowerResult(base, power, result, expected);

    /* test postive int max value: 2,147,483,647
    *  b^e < 2,147,483,647
    */
    base = 10;
    power = 9;
    result = IntPow(base, power);
    expected = 1000000000;
    PrintIntPowerResult(base, power, result, expected);

    /* test negaive int max value: -2,147,483,648
   *  b^e > -2,147,483,648
   */
    base = -10;
    power = 9;
    result = IntPow(base, power);
    expected = -1000000000;
    PrintIntPowerResult(base, power, result, expected);

    /* test postive unsigned int max value: 4,294,967,295
    *  b^e < 4,294,967,295
    */
    base = 3;
    power = 19;
    result = IntPow(base, power);
    expected = 1162261467;
    PrintIntPowerResult(base, power, result, expected);

    return 0;
}
