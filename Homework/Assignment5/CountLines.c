/*
** Student Solution
**   Author:    --- Don Dang ---
**   Date:      --- 10/10/2024 ---
**
** Date         Developer       Activities
*  10/10/24     Don D           Started CountLines.c
*/

#include <stdio.h>


void ReadInput(void)
{
    unsigned int ch;
    unsigned int newLine = 0;
    unsigned int isContent = 0;
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        printf("%c", ch);
        if (ch == '\n') 
        {
            newLine += 1;
        }
        isContent = 1;

    }
    if (!newLine && !isContent) /*input has no new line character and content, empty line*/
    {
        printf("\nNumber of lines: %d", newLine);
    }
    if (!newLine && isContent) /*no new line but there is content, then it's 1 line*/
    {
        printf("\nNumber of lines: %d", isContent);
    }
    if (isContent && newLine > 0) /*line count depends on newLine value*/
    {
        printf("\nNumber of lines: %d", newLine);
    }

}

int main()
{
    ReadInput();
    return 0;
}
