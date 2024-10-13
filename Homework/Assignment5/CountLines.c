/*
** Student Solution
**   Author:    --- Don Dang ---
**   Date:      --- 10/10/2024 ---
**
** Date         Developer       Activities
*  10/10/24     Don D           Started CountLines.c
*  10/1124      Don D           Completed assignment and tested using 11 test files
*/

#include <stdio.h>
/*Keep for historical review - too much redundancy with if conditions*/
//void ReadInput2(void)
//
//{
//    unsigned int ch;
//    unsigned int newLine = 0;
//    unsigned int isContent = 0;
//    while ((ch = getchar()) != EOF)
//    {
//        if (ch == '\n')
//        {
//            newLine += 1;
//        }
//        else
//        {
//            isContent = 1;
//        }
//    }
//
//
//    if (!isContent && !newLine) printf("Number of lines: %d", newLine); /*there is no content and no new line, empty line*/
//if (!isContent && newLine > 0) printf("Number of lines: %d", newLine); /*there is no content but new line detected*/
//if (isContent && !newLine) printf("Number of lines: %d", isContent); /*there is content but no new line, then it's 1 line*/
//if (isContent && newLine > 0) printf("Number of lines: %d", newLine); /*there is content, line count depends on newLine value*/
//}


void ReadInput(void)
{
    int ch;
    int newLine = 0;
    int isContent = 0;
    int lastChar = 0;  // Store last character read

    while ((ch = getchar()) != EOF)
    {
        lastChar = ch;  // Track last character read
        if (ch == '\n')
        {
            newLine++;
            isContent = 0;  // Reset isContent after a newline
        }
        else
        {
            isContent = 1;  // Mark content was read
        }
    }

    // Last character was not a newline, and there was content, increment the line count
    if (lastChar != '\n' && isContent)
    {
        newLine++;
    }

    printf("Number of lines: %d\n", newLine);
}


int main()
{
    ReadInput();
    return 0;
}
