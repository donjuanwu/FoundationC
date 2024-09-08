/*
** Copyright (C) August 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 1, Convert.c, INSTRUCTIONS
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
**   Developed: October 4, 2022
**   Updated:   August 24, 2024
**
** Student Solution
**   Author:    Don Dang
**   Date:      9/7/2024
**
** OBJECTIVE
**
** This program exposes you to code readability, basic data types,
** input with scanf, type conversion and casting, and functions with arguments,
** while introducing float, *, /, and scanf().
**
** INSTRUCTIONS
**
** Write a program that converts non-negative integer temperatures entered
** by the user from Fahrenheit to Celsius and Celsius to Fahrenheit.
**
** Taking these as REAL mathematical numbers, the mathematical formulas are:
**
**   Celsius = (Fahrenheit - 32) * (5 ÷ 9)
**   Fahrenheit = (9 ÷ 5) * Celsius + 32
**
** But in C there are no REAL numbers, just integers (like int: whole counting numbers) and finite
** precision decimal numbers (like float and double: both with limited significant digits).
** So we must choose the C types to approximate the real numbers, and carefully choose the order
** of math operations (+, -, * /) to avoid gross rounding errors.
**
** In C:  5 / 9 produces the integer 0, because 5 and 9 are integers.
**        5.0f / 9.0f produces a float value.
**        5.0 / 9.0 produces a double value.
**
** Write 8 functions, 4 versions of each conversion.
** These are listed from easiest to hardest to implement.
**
** AccurateFloat
**   - Input is int, but output is float.
**   - Internally can use a mixture of floating point and integer operations.
**   - The returned value is as accurate as a float can be.
**
**   float FahrenheitToCelsius_AccurateFloat (int fahrenheit);
**   float CelsiusToFahrenheit_AccurateFloat (int celsius);
**
** IntRoundedCorrectlyUsingFloat
**   - Input and output are both int.
**   - Internally can use a mixture of floating point and integer operations.
**   - The returned value is within 0.5 degrees of the correct answer.
**   - Rounds correctly, up or down, yielding the closest integer.
**
**   int FahrenheitToCelsius_IntRoundedCorrectlyUsingFloat (int fahrenheit);
**   int CelsiusToFahrenheit_IntRoundedCorrectlyUsingFloat (int celsius);
**
** PureIntRoundedDown
**   - Input and output are both int.
**   - Internal operations are pure integer (no float or double), which is faster on some processors.
**   - The returned value is within 1.0 of the correct answer.
**   - Rounds down even if rounding up would be closer to decimal answer.
**
**   int FahrenheitToCelsius_PureIntRoundedDown (int fahrenheit);
**   int CelsiusToFahrenheit_PureIntRoundedDown (int celsius);
**
** PureIntRoundedCorrectly
**   - Input and output are both int.
**   - Internal operations are pure integer (no float or double), which is faster on some processors.
**   - Inflate (scale by a factor of 10) the input to perform correct rounding.
**   - The returned value is within 0.5 degrees of the correct answer.
**   - Rounds correctly, up or down, yielding the closest integer.
**
**   int FahrenheitToCelsius_PureIntRoundedCorrectly (int fahrenheit);
**   int CelsiusToFahrenheit_PureIntRoundedCorrectly (int celsius);
**
** DESIGN NOTES
**
**   - In the two pairs of float functions (AccurateFloat, IntRoundedCorrectlyUsingFloat),
**     confine your internal operations to float and avoid the use of double. The aim is to ensure
**     that you understand the difference between them. They each carry space, performance,
**     and precision trade-offs.
**   - In the two pairs of "pure integer" functions (PureIntRoundedDown, PureIntRoundedCorrectly),
**     we mean that the words float, double, nor any decimal number literal (e.g. 5.0, 5.0f, 9.0, 9.0f)
**     should NOT appear anywhere in this function.
**   - The modulus (%) operator is not needed to solve any of these functions.  It can be used, but
**     leads to an overly complex solution that will loose a few style points.
**   - Cleanly separate pure calculation logic from printing logic. Imagine someone reusing a
**     calculation function for a purpose other than printing the answer.
**
** TESTING
**
** - IMPORTANT, read section 3.4.2, Testing, of the Course Introduction!
** - Demonstrate the output of your program on input values that exercise
**   important boundary cases and equivalence classes.
** - Do not pick repetitious test cases, but pick a few boundary cases that
**   make it obvious that each aspect of the program works correctly.
** - Include additional test cases that demonstrate the rounding errors made by the
**   PureIntRoundedDown converters.
** - Do NOT test negative inputs or outputs, because rounding behaves
**   differently for negative numbers, and we cannot handle that at this early
**   point in the class.  Do NOT add complexity to handle negative numbers.
** - For this assignment, there is no need to test gigantic numbers.
** - Do NOT support or test non-numeric (string) input.
** - HINT: I look for 8 test cases that can be demonstrated by running the program 4 times.
**
** OUTPUT FORMAT
**
** Make your output look similar to this:
**
**   Enter fahrenheit temperature (integer): 33
**
**                     AccurateFloat: 33 fahrenheit is 0.555556 celsius
**     IntRoundedCorrectlyUsingFloat: 33 fahrenheit is 1 celsius
**                PureIntRoundedDown: 33 fahrenheit is 0 celsius
**           PureIntRoundedCorrectly: 33 fahrenheit is 1 celsius
**
**   Enter celsius temperature (integer): 1
**
**                     AccurateFloat: 1 celsius is 33.799999 fahrenheit
**     IntRoundedCorrectlyUsingFloat: 1 celsius is 34 fahrenheit
**                PureIntRoundedDown: 1 celsius is 33 fahrenheit
**           PureIntRoundedCorrectly: 1 celsius is 34 fahrenheit
*
*
* Date      Developer       Activities
* 9/7/24    Don D           Begin working assignment1
*                           Replaced scanf() with scanf_s() for VS Studio security warnings
*
*/

/* Do NOT include any other header files.  Do NOT include <math.h>.  */
#include <stdio.h>


float FahrenheitToCelsius_AccurateFloat(int fahrenheit)
{
    return (fahrenheit - 32) * (5.0f / 9.0f);
}

//float CelsiusToFahrenheit_AccurateFloat(int celsius);

int FahrenheitToCelsius_IntRoundedCorrectlyUsingFloat(int fahrenheit)
{
    double preRoundedTemp = (fahrenheit - 32) * (5.0f / 9.0f);
    return  ManualIntRoundedCorrectlyUsingFloat(preRoundedTemp);

}
//int CelsiusToFahrenheit_IntRoundedCorrectlyUsingFloat(int celsius);

int FahrenheitToCelsius_PureIntRoundedDown(int fahrenheit)
{
    float preRoundedTemp = (fahrenheit - 32) * (5.0f / 9.0f);
    return ManualRoundDown(preRoundedTemp);
}


//int CelsiusToFahrenheit_PureIntRoundedDown(int celsius);
int FahrenheitToCelsius_PureIntRoundedCorrectly(int fahrenheit)
{
    int adjustedFah = fahrenheit - 32;
    int inflatedCel = adjustedFah * 50;
    int roundedCel = (inflatedCel + 45) / 90;
    return roundedCel;
}



//int CelsiusToFahrenheit_PureIntRoundedCorrectly(int celsius);
int PromptForTemperature(char* tempType) {
    int tempEntered;

    if (*tempType == 'f')
    {
        printf("Enter your Fahrenheit temperature as a whole number: ");
        scanf_s("%d", &tempEntered);
    }
    else if (*tempType == 'c')
    {
        printf("Enter your Celsius temperature as a whole number: ");
        scanf_s("%d", &tempEntered);
    }
    else
    {
        printf("Invalid temperature type!\n");
        tempEntered = -999;
    }
    return tempEntered;

}

/*
    Function to manually calculate the floor of a number
    If num is positive or exactly an integer, just reutn intPart
    Otherwise, for negative numbers with a decimal part, substract 1
*/
int ManualRoundDown(float num)
{
    int intPart = (int)num; /* get the integer part*/
    if (num >= 0)
    {
        return intPart;
    }
    if (num < intPart)
    {
        return intPart - 1;
    }
    return intPart;

}

/*
    Function to manually calculate the ceiling of a number
    If the numjber is positive and has a decimal part, add 1 to the integer part
    If the number is already an integer, return the integer part
*/
int ManualRoundUp(float num)
{
    int intPart = (int)num;
    if (num > intPart)
    {
        return intPart + 1;
    }
    return intPart;
}

/*
    Function to manaully calculate the rounded (up or down) int correctly
    If the fractional part of the number is greater than or equals to .5 then return 1 higher
    Otherwise return the integer value of the number

    Notes:
    Floating-point numbers are not always represented exactly due to precision limitations. 
    By introducing a small epsilon, we allow some "wiggle room" in the comparison, 
    ensuring that values near 0.5 are treated as 0.5 for the rounding logic.

*/
int ManualIntRoundedCorrectlyUsingFloat(double num)
{
  
    int intPart = (int)(num); 
    double fractionalPart = num - intPart; 

    if (fractionalPart >= 0.5) 
    {
        return intPart + 1;
    }
     return intPart; 
}

int main(void)
{
    char* tempFah = "f";
    char* tempCel = "c";
    int temp;

    // get Fahrenheit temp
    temp = PromptForTemperature(tempFah);
    if (temp == -999)
    {
        printf("Error: Invalid temperature. Exit application with code: 1.\n");
        return 1;
    }
    float tempConvertCel = FahrenheitToCelsius_AccurateFloat(temp);
    printf("%-35s: %d Fahrenheit is %f Celsius\n", "AccurateFloat", temp, tempConvertCel);

     int tempRoundedUp = FahrenheitToCelsius_IntRoundedCorrectlyUsingFloat(temp);
    printf("%-35s: %d Fahrenheit is %d Celsius\n","IntRoundedCorrectlyUsingFloat", temp, tempRoundedUp);

    int tempRoundedDown = FahrenheitToCelsius_PureIntRoundedDown(temp);
    printf("%-35s: %d Fahrenheit is %d Celsius\n", "PureIntRoundedDown", temp, tempRoundedDown);

  
    int tempRoundedCorrect = FahrenheitToCelsius_PureIntRoundedCorrectly(temp);
    printf("%-35s: %d Fahrenheit is %d Celsius\n", "PureIntRoundedCorrectly", temp, tempRoundedCorrect);

    printf("\n");
    temp = PromptForTemperature(tempCel);


    return 0;
}