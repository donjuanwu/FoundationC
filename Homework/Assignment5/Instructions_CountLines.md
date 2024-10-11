# CPROG 310 - Foundations of C Programming

University of Washington PCE (Professional Continuing Education)
Instructor: Colby O'Donnell - <colbster@uw.edu>

## Assignment 5 - CountLines - INSTRUCTIONS

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
- Developed: November 23, 2011
- Updated:   October 10, 2023

## OBJECTIVE

This program introduces you to reading from standard input and redirecting I/O
on the command line.  The function getchar() and constant EOF are introduced.

## INSTRUCTIONS

Write a program which reads from stdin (standard input), counts the number of lines
in the input, and prints the total count to stdout (standard output). Your program
must gracefully handle EOF (End Of File).

Given the following two legitimate methods of line counting...

1. Count the number of '\n' (newline) characters in the input, regardless of where they are.

  - EOF following non-newline characters does NOT count as a line.
  - The sum of the line counts of any two files equals the line count
    of the file created by concatenating the two files.

2. Count the number of '\n' (newline) characters, but also count the EOF if it
    follows a non-newline character.

  - EOF following non-newline characters DOES count as a line.
  - Empty files have zero lines, which is consistent with 2a.

This assignment shall use method #2, mainly because the test cases are more interesting.

## TESTING

Your testing shall be manual.  For each test case, run your program from the command line
using file redirection to a test output file.  You will create a set of test files called
CountLines_NUMLINES_CONTENT.txt, where:

- NUMLINES is the number (0, 1, 2, 3, etc.) of lines the program is expected to count.
- CONTENT is a sequence of letters describing the content of the file:
  - N represents one newline ('\n') character.
  - F represents EOF (end of file).
  - c represents a sequence of 1 or more characters besides newline and EOF.
- A filename with cF is not treated differently than ccF or cccF.
  - Thus, no file name will have 2 or more consecutive c's.
  - But, cF is different than cNF and cNcF.
  - But, NF is different than NNF and NNNF.
- Note: All file names will end in F to signal end-of-file (EOF).

Manually create each test file.  To help you see the newlines and EOF
markers in your files, enable viewing of whitespace in your editor.

- In Visual Studio under Edit -> Advanced -> View White Space.
- In Notepad++, under View -> Show Symbol -> Show All Characters.

To demonstrate your testing:

- Generate a CountLines.txt that shows your entire test session running ALL of the test files.
  - Countlines.txt should show the NAME of each test file.
  - Countlines.txt should show the output of your program for each test file.
  - Run the test files IN THE SAME ORDER as they are listed in your directory structure,
    alphabetized by filename.  This is worth 2 test points.
- Include ALL combinations of files with 0, 1, and 2 lines.
- Include 1 test case with 3 lines.
- Include 1 test case with 4 lines.
- Include CountLines.txt AND all of the individual input test files in your submission.

Here is an example of what 3 of the test files might look like:

    CountLines_0_F.txt (empty file)

    CountLines_1_cF.txt:
    This file has 1 line, because this line ends in EOF.

    CountLines_1_cNF.txt
    This file has 1 line, because this line ends in newline then EOF.


In DOS and Unix, you would run the following commands.  Notice the program outputs
the number of lines, which matches the number in the filename.

    CountLines < CountLines_0_F.txt
    Number of lines: 0
  
    CountLines < CountLines_1_cF.txt
    Number of lines: 1
  
    CountLines < CountLines_1_cNF.txt
    Number of lines: 1
  
    CountLines < CountLines_3_cNNcNF.txt
    Number of lines: 3

## DESIGN HINTS

- Keep your code clean and simple!  Reduce the number of variables to a practical minimum.
- Avoid unneeded moving parts (unnecessarily complexity).
- There is no need to use an array to solve this problem.
- Mind the DRY principle: Don't repeat yourself.  There should be only one call to getchar().
  - Use a loop structure that avoids repeating the same code redundantly.
  - Do avoid unnecessary variables, but not at the expense of duplicating code.

## OTHER HINTS

My solution...

- has a GoodVersion    that is 14 lines long.
- has a BetterVersion  that is 10 lines long.
- has a BestVersion    that is 11 lines long.
- has a CrypticVersion that is  6 lines long.
- My solution has 13 test cases, 12 of which are essential.
