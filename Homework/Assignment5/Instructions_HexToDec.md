# CPROG 310 - Foundations of C Programming

University of Washington PCE (Professional Continuing Education)
Instructor: Colby O'Donnell - <colbster@uw.edu>

## Assignment 5 - HexToDec - INSTRUCTIONS

Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>

Limited license is granted for use by the following institution:
  - University of Washington PCE (Professional Continuing Education)
  - Course: Foundations of C - Autumn 2024

The institution may share this work only with registered students of the course.
Registered students of the course may retain a copy of this work for their own personal educational use.
This work is protected by copyright laws and shall not be shared publicly in whole or in part.
The content may not be distributed, sold, or republished outside the limited license granted above.

## DEVELOPMENT

- Author:    Colby O'Donnell - <colbster@uw.edu>
- Developed: October 10, 2011
- Updated:   October 9, 2024

## OBJECTIVE

This program introduces you validating number and letter input from the user using getchar()
and converting characters to numbers. The SkipRestOfLine() idiom is introduced, and the
continue statement is used in main().

## INSTRUCTIONS

This program requests a hexadecimal (base 16) integer from the user, converts
it to a (base 10) unsigned long, and prints out the converted number to the screen.
Both upper or lower case letters A-F must be accepted. (1a is treated the same as 1A).

The program should gracefully reject the following input:

- Illegal hex digits (like C3P0 and R2D2) and these special cases:
  - Negative numbers (starts with -)
  - Leading or trailing spaces
- Numbers too large to be converted to unsigned long
- Blank input (do not assume it means 0).

Include unique error messages for these categories:

- Unrecognized hex number (illegal hex character, negative, leading/trailing space).
- Too many hex digits entered.
- Blank input.  (The user pressed enter without entering any input at all).

The program repeats until the user types 'q' or 'Q' to quit.  While your program is reading legal
hex digits, it may react immediately to the first non-hex digit it reads to either quit or
reject non-hex digits.  (You program does NOT have to scan the entire input in case there might
be a 'q' or 'Q' trailing behind other non-hex digits.)  So, the Q in 1QX would cause the program
to quit, whereas the X in 1XQ would cause the program to reject the input and prompt for a new value.

- DO NOT use scanf().
- DO NOT include <ctype.h>. Do NOT use toupper or tolower.
- DO NOT include <math.h> or use the pow() function.

## DESIGN HINTS

Things to remember:

- Keep the code simple, clean, and tight.
- The program does not need to be broken into pieces smaller than the function prototypes provided.
- Minimize the number of variables and avoid unnecessary complexity.
- Always handle EOF when calling getchar().
- To print the FF in "Hex FF converted to decimal is 255.", you may use
  the printf format specifier %lX on your converted number.

Common mistakes to avoid:

- Avoid the use of arrays.  They are not needed to solve the problem.
- Avoid cryptic integer values (like 48).  Use readable ASCII characters (like '0').
- Avoid declaring global variables.
- Don't forget to use the SIGNAL constants below.

## TESTING

- Test your program manually.
- Providing a thorough set of test cases to verify boundary conditions.
- Provide at least one execution of your program compiled in DEBUG, and one in RELEASE.
- Copy and paste your testing into HexToDec.txt.

## EXAMPLES

Here are some example test cases (run on a 32 bit Windows platform).
Note: The 8 digit limit would be a 16 digit limit on a 64 bit platform.


    Welcome to (Debug 32 bit) HexToDec.
    
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: R2D2
    
      ERROR: Unrecognized hex number, try again.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: C3P0
    
      ERROR: Unrecognized hex number, try again.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: 0
    
      Hex 0 converted to decimal is 0.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: 1
    
      Hex 1 converted to decimal is 1.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: 2
    
      Hex 2 converted to decimal is 2.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: a
    
      Hex A converted to decimal is 10.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: F
    
      Hex F converted to decimal is 15.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: 10
    
      Hex 10 converted to decimal is 16.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: 123456789
    
      ERROR: Cannot enter more than 8 hex digits, try again.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits:
    
      ERROR: Nothing was entered, try again.
    
    Enter a non-negative base 16 (hexadecimal) number to be converted to base 10.
    Enter 'q' or 'Q' to quit, and enter no more than 8 digits: Q
    
    Goodbye.