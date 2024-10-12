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
#include <ctype.h>


void ReadInput(void)
{
    unsigned int ch;
    unsigned int newLine = 0;
    unsigned int isContent = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n') newLine += 1;
        if (isalnum(ch))isContent = 1; 
    }
    
    
    if (!isContent && !newLine) printf("Number of lines: %d", newLine); /*input has no content and no new line, empty line*/
    if (!isContent && newLine > 0) printf("Number of lines: %d", newLine); /*there is no content but new line detected*/
    if (isContent && !newLine) printf("Number of lines: %d", isContent); /*there is content but no new line, then it's 1 line*/
    if (isContent && newLine > 0) printf("Number of lines: %d", newLine); /*there is content, line count depends on newLine value*/


}

//int main()
//{
//    ReadInput();
//    return 0;
//}
