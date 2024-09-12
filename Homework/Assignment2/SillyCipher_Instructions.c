/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 2, SillyCipher.c, INSTRUCTIONS
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
**   Developed: October 17, 2011
**   Updated:   September 8, 2023
**
** Student Solution
**   Author:    --- Enter your name here ---
**   Date:      --- Enter date here ---
**
** OBJECTIVE
**
** This program introduces doing math on ASCII character values, operator precedence, the
** remainder (%) operator, and converting between types with cast.  It introduces the following
** items from the C language: char, #define, getchar(), % (remainder)
**
** INSTRUCTIONS
**
** Write a program that encrypts and decrypts 5 characters entered by the user.  The method to use
** is similar to the ancient technique, often refered to as the "Caesar Cipher", as described by:
**   http://en.wikipedia.org/wiki/Caesar_cipher
**
** The program first asks the user for all 5 characters to encrypt.  State to the user which characters
** are accepted.  The accepted characters are '!' (ASCII 33) to '~' (ASCII 126) which we will call the
** "legal character set".
** 
** The program encrypts each character by calling the EncryptChar function 5 times (once for each)
** and then prints them to the screen.  The encrypted characters must also fall within the same
** legal character set.
**
** The program then immediately decrypts those characters (the encrypted ones) using the DecryptChar()
** function.  Finally it prints out the decrypted characters to the screen, which should exactly
** match the original 5 characters entered by the user.
**
** - Line up the input, encrypted, and decrypted characters vertically, so that in your testing it is
**   easy to verify the input and decrypted characters match, and that the encrypted characters use the
**   same legal character set.
**
** - The encryption algorithm must be a function of both the integral value of the
**   character and its position (1-5) in the user's input.  Thus an 'A' input in position 1 will be
**   encrypted differently than an 'A' at position 2.
**
** - Limit your input, encrypted output, and decrypted output to the legal character set
**   of '!' (ASCII 33) to '~' (ASCII 126).  My favorite online ASCII chart is http://www.AsciiTable.com.
**
** - The encryption and decryption algorithms are written by you.  See EncryptChar() and DecryptChar()
**   below.  The decryption is a symmetrical reverse of encryption.  Thus, the following is always true:
**     DecryptChar( EncryptChar( number, position), position) equals number
**     For example: DecryptChar( EncryptChar( 'A', 2), 2) equals 'A'
**
** - Assume the user always enters 5 characters as input.  You are not required to validate
**   the number of characters entered, nor which characters are entered.  Just be clear to
**   the user how many they need to enter, and what the range of acceptable characters is.
**   Using the getchar() function rather than the scanf() function will provide an opportunity to
**   simplify your code in this program.
**
** - Do not use if statements, loop constructs, arrays, or strings.  We have not introduced those concepts
**   yet.  Declare three sets of 5 variables, such as:
**
**       input1,   input2,   input3,   input4,   input5
**     encrypt1, encrypt2, encrypt3, encrypt4, encrypt5
**     decrypt1, decrypt2, decrypt3, decrypt4, decrypt5
**
**   Normally it is very poor style to number variables like this, but at this very early stage, it is
**   our only choice.  Later we will learn about arrays, which will allow us to avoid numbering variables.
**
** - The remainder (%) operator is an essential tool for your encryption and decryption algorithms.
**   You may also hear it refered to as modulus.  For positive numbers, remainder and modulus are the same.
**   For negative numbers, there are differences that themselves can differ across C implementations.
**   For this program we will avoid negative numbers entirely.  Your implementation must take great
**   care not to allow numbers to go negative.  This can be done with plain math and no if statements.
**
** - The following spinning wheel analogy might help you visualize the algorithms using the % operator:
**
**   Suppose the range of legal characters you define was A-Z, just for simplicity sake.
**   The size of this range is not important; rather that it is a single continuous range of characters.
**   Now imagine a spinning wheel (like Wheel of Fortune, or the Price is Right), where each of your 26
**   legal input characters is written, equally spaced, around the outer portion of the wheel. If the
**   wheel is spun, each click of the wheel represents passing a character. No matter how slowly or quickly
**   the wheel is spun, it will slow down and eventually stop at a new (or the same) spot marking one of
**   the 26 legal characters.  This is true whether the wheel spins less than one full revolution or
**   several revolutions.  It is also true despite the wheel turning in either direction.
**    
**   The wheel starts out at a certain position, defined by an input character. Your encryption algorithm
**   decides how far to spin the wheel, as a function of the character and its position in the input string.
**   It could spin just a few clicks, or several revolutions. No matter how little or far the wheel is
**   spun, it will land on some legal character, possibly the same one, but probably a different one.
**    
**   Your decryption algorithm (a function of the encrypted character and its position) spins the wheel in
**   the opposite direction, the exact same distance, such that wheel returns to the original input character.
**
** TESTING
**
** Make your program output identical to this format:
**
**   Enter exactly 5 characters to encrypt, ranging
**   from '!' (ASCII 33) to '~' (ASCII 126).
**   
**         Input: C2C++
**     Encrypted: SEYDG
**     Decrypted: C2C++
**
** Your cipher algorithm need not behave exactly like mine.
** Yours will likely convert C2C++ into something different than SEYDG.
**
** Testing Part A
**
**   - In SillyCipher.txt, clearly label this section TESTING PART A.
**   - Include all the program output, including the prompt:
**     Enter exactly 5 characters to encrypt, ranging from '!' (ASCII 33) to '~' (ASCII 126).
**   - Include enough test cases to verify each of the following:
**     - All encrypted and decrypted characters are within the legal character set.
**     - The boundaries of the legal character set are obvious boundary conditions to test.
**     - The requirement that the same character in different positions encrypts differently.
**
** Testing Part B
**
**   - In SillyCipher.txt, clearly label this section TESTING PART B.
**   - Adjust your code so that the legal range is now A-Z. Your code should be designed such that this
**     can be done with a minimal number of modifications.
**   - Recompile your executable.
**   - Include all the program output, including the prompt:
**     Enter exactly 5 characters to encrypt, ranging from 'A' (ASCII 65) to 'Z' (ASCII 90).
**   - Append additional test cases that prove the same set of criteria tested in Part A
**     continue to work as expected with the new legal range.
*/

//char EncryptChar (char input, int position);
//char DecryptChar (char input, int position);
//
//int main(void)
//{
//    return 0;
//}
