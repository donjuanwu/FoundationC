/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 4, CheapskateAir.c, INSTRUCTIONS
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
**   Developed: October 28, 2011
**   Updated:   Septmeber 14, 2024
**
** Student Solution
**   Author:    Don Dang
**   Date:      9/25/24
**
** OBJECTIVE
**
** This program introduces you to branching and validating input.
** New keywords, operands, and functions: if, else, switch, break, do while, <ctype.h>,
** toupper(), &&, ||, ==, !=
**
** INSTRUCTIONS
**
** Write an airline reservation program for CheapSkate Air.  CheapSkate Air owns a single plane with
** 48 seats.  This is the only plane available for reservation.
**
** The Seats
**
**   There are 12 rows of seats on the plane.  The rows are labelled 1 to 12.
**   Each row has 4 seats labelled A, B, C, D.  There is a walking aisle between A, B and C, D.
**   The first seat is 1A, then 1B, 1C, 1D, 2A, 2B, ..., 12C, and 12D (the last seat).
**
** Passengers
**
**   Unfortunately, CheapSkate Air's reservation system is quite impersonal, and only keeps passenger
**   IDs (positive integers), not their names.  Passenger IDs can be 1 to 999.
**
** Validating Input
**
**   Your program should check for valid inputs, and gracefully inform the user when invalid input is
**   encountered.  Using scanf() rather than getchar() is simpler and adequate for this programming
**   assignment.  Your handling of malformed input does not have to be completely robust.
**   For example, if the user enters a letter instead of a number, you will find that
**   using scanf("%d") inside a loop causes the program to run infinitely.  To prevent this,
**   check the return value of scanf.  If scanf is unable to match requested fields, it is
**   acceptable to terminate the program.  Later assignments will add the requirement of having
**   user friendly, robust handling of malformed input.  For now, just check that the value is within
**   range (like passenger ID is 1-999, seat row is 1-12, and seat letter is A-D or a-d).
**
** Design
**
**   - Be careful not to limit the design of your program to 12 rows and 4 letters.
**     There will be a follow-up assignment that builds on this and expands the requirements,
**     with a bigger plane having more rows and letters.
**   - Do enforce the current limits, but do not make your code so rigid that expanding the
**     requirements causes an update of many hard coded numbers throughout the program.
**   - There is no need for additional global variables.  Adding more globals will bring point deductions.
**   - Be careful not to use control flow (if, else, switch) for things that should be calculated.
**     For example, mapping an already-validated seat name 2C to seat index 6 (or the reverse) can be 
**     calculated without (if, else, switch).  Validating that user-inputted seat rows and letters
**     are in range does require branching (if, else).
**   - Hunt down and eliminate redundant, complex, repetitious, nested code.  Simplify.
**   - Take action on any TODOs that you find in the code below.
**   - Make sure that all prompts and error messages that you create are unique and not duplicated.
**     This helps us know during testing (without ambiguity) which line of code produced each of them.
**
** The Workflow
**
**   Initially all seats are empty and ready for reservation.  A menu provides the following functions:
**
**     (0) Exit the Program
**     (1) Reserve a Seat
**     (2) Cancel a Reservation
**     (3) Move Seat Reservation
**     (4) Display Current Seating
**
**   - The current seating should only be displayed if the user picks option 4.  It should
**     NOT automatically be printed after other options are picked from the menu.
**   - The program does NOT have to offer the user the ability to immediately exit the program from
**     a deeply nested prompt, such as when asking for the passenger ID when reserving a seat.
**
** EXAMPLE WORKFLOW
**
**   ---------------------------
**   --- CheapSkate Air Menu ---
**   ---------------------------
**     (0) Exit the Program
**     (1) Reserve a seat
**     (2) Cancel Reservation
**     (3) Move Seat Reservation
**     (4) Display Current Seating
**   
**   Please choose: 1
**   
**   Enter a seat to reserve: 2B
**   Enter passenger ID: 30
**   Seat 2B is now occupied by passenger 30.
**   
**   ---------------------------
**   --- CheapSkate Air Menu ---
**   ---------------------------
**     (0) Exit the Program
**     (1) Reserve a seat
**     (2) Cancel Reservation
**     (3) Move Seat Reservation
**     (4) Display Current Seating
**   
**   Please choose: 4
**   
**   ------------------------------
**    Current Seating Reservations
**   ------------------------------
**        |  A  |  B  |  C  |  D  |
**   -----+-----+-----+-----+-----+
**      1 |     |     |     |     |
**      2 |     |  30 |     |     |
**      3 |     |     |     |     |
**      4 |     |     |     |     |
**      5 |     |     |     |     |
**      6 |     |     |     |     |
**      7 |     |     |     |     |
**      8 |     |     |     |     |
**      9 |     |     |     |     |
**     10 |     |     |     |     |
**     11 |     |     |     |     |
**     12 |     |     |     |     |
**
** TESTING
**
** Testing will be done manually for this program.
** Copy and paste your console testing session into CheapAir.txt.
**
** Part A - Compiled using the original plane size
** 
** - Provide thorough coverage of your program by testing each unique control path.
**   Hint: Demonstrate every unique message (including errors) at least once.
** - Test these specific seat names: 0E, 1E, 1F, 2?, 2@
** - Test these specific passenger IDs: -1, 0, 1, 999, 1000
** - Test these specific menu choices: -1, 0, 1, 2, 3, 4, 5
**
** Part B - Compiled using NUM_ROWS = 20 and NUM_LETTERS = 6
* 
** - Test all operations on all 4 corners of the plane:
**   ReserveSeat, CancelReservation, MoveSeat, FindSeatWithPassenger, DisplaySeating
* 
** Date         Developer           Activities
* 9/25/24       Don D               Started working on assignment 4
*                                   - added #define _CRT_SECURE_NO_WARNINGS to suppress scanf() wanring
* 9/28/24       Don D               Added void PrintRserverSeatExplation(void) 
*                                      - explains system expect seat input
*                                   Added int convertSeatNumToSeatIndex(unsigned int row, char seatLetter)
*                                       - convert valid human-readable seat to 0 base index array
* 
*/

#define _CRT_SECURE_NO_WARNINGS /*suppress Visual Studio scanf warnings*/
#include <stdio.h>
#include <ctype.h>

/*
** These are defined as preprocessor macros rather than constant integers, because the array below
** must know its size at compile time. They are global because the array must be global, and because they
** used by several functions.  Global variables and symbols are not as much of a design risk when they are
** constant (unchangeable).  Preprocessor macros are easy to identify because we name the with ALL_CAPS.
** Later in the course we will drastically reduce and often eliminate the use of macros and global variables.
**
** TODO: Change these to enum constants.
*/
enum
{
    NUM_ROWS = 12,
    NUM_LETTERS = 4,
    NUM_SEATS = (NUM_ROWS * NUM_LETTERS)
};
//#define NUM_ROWS 12
//#define NUM_LETTERS 4
//#define NUM_SEATS (NUM_ROWS * NUM_LETTERS)

/*
** Represents an error condition to test for, when a seat index
** is outside the legal range of 0 to NUM_SEATS - 1.
** 
** STUDENTS: Note: This global signal value is a "bad coding smell" that we will
**           eliminate and replace with something better in Assignment 8, EconoAir.
*/
const int INVALID_SEAT = -1;

/*
** The registry of reservations, an array with NUM_SEATS elements, where each element is
** either 0 (for empty seat) or a passenger ID (for an occupied seat).
**
** STUDENTS:
**   Normally declaring a modifiable global variable is a terrible design decision.
**   Unfortunately, we won't learn about better tools to avoid this until later in the course.
**   We prefix the variable name with g_ to emphasize it is global so it is easier to
**   find global variables and to reduce the chance there is a name conflict with a local
**   variable in the functions below.
**   
**   The g_ prefix itself is ugly, but it helps warn of the (unfortunate) use of a global variable.
**   Remember! As with all arrays in C, the array index is 0-based, so its goes from 0 to NUM_SEATS - 1.
*/
int g_reservations[NUM_SEATS];


/*
******************************************************************************************************************
******************************************Helper Functions********************************************************
******************************************************************************************************************
*/
void PrintReserveSeatExplanation(void)
{
    printf("Welcome to CheapAir. We are in the business of providing air travel service to our guests at affordable price. \n");
    printf("Our plane has 12 rows of seats starting from  row 1 (front of airplane) - row 12 (back of airplane) \n");
    printf("Each row has 4 seats. Each seat has an assigned letter from A - D. \n");
    printf("The seat letter read from right (A) to left (D) as you look toward the back of the plane. \n");
    printf("We are happy to accomodate your seating arrangement. \n");
    printf("You may reserve a seat by entering the seat row follow by the seat assigned letter like 12A. 12th row and colum A \n");
}


int convertSeatNumToSeatIndex(unsigned int row, char seatLetter)
{
    unsigned int rowLow = 1;
    unsigned int rowHigh = 12;
    unsigned int letterLow = 0;
    unsigned int letterHigh = 3;

    if (row < rowLow || row > rowHigh)
    {
        return INVALID_SEAT;
    }
    
    unsigned int letterOffSet = toupper(seatLetter) - 'A'; /*convert seat letter to offset index (A = 0, B = 1, C = 2, D = 3*/
    if (letterOffSet < letterLow || letterOffSet > letterHigh)
    {
        return INVALID_SEAT;
    }

    /*scope of local variables*/
    {
        unsigned int column = 4;
        unsigned int index = (row - 1) * column + letterOffSet;
        return index;
    }

}
/*

*/
void ClearInputBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && (ch != EOF)); /*flush input buffer*/
}



/*******************************************************************************************************************/

/*
** Clears g_reservations so that all seats are empty.
** Sets the passenger ID to 0 for all seats in the array.
*/
void ClearReservations(void)
{
    // TODO: Implement this function.
    // HINT: There is an opportunity to use unsigned int here.
    unsigned int index = 0;
    for (index = 0; index < NUM_SEATS; index++)
    {
        g_reservations[index] = 0;
    }


}


/*
** Translates from code-friendly seat index (0, 1, 2, etc.) to
** human-friendly seat name (1A, 2B, 3C, etc.). This insulates the rest
** of the code from the complex nature of seat rows and letters and
** allows the rest of the program to deal with simple 0-based seat index.
**
** Given a seat index (0, 1, 2, ..., NUM_SEATS - 1), prints the row number
** and letter to the console.
**
** If the seat index is outside that range, print: (invalid seat index N)
** where N is the value. This will not be something that you can test manually,
** because a correctly working program will never trigger it to happen.
** FYI: In Module 12 we will learn about <assert.h>, a better tool for this problem.
**
** Example: A seat index of 0 is printed as 1A.  Seat index 7 is printed as 2D.
** Example: A seat index of -1 is printed as (invalid seat index -1).
** 
** STUDENTS: Remember that integers and characters in C are related,
**           and arithmetic can be done on both.
** Notes:
*  1. Calculate 0 base index
*   index = (row -1) * 4 + offset
*  2. Calculate letter value in number format
*   intLetter = seatIndex % 4
*  3. Calculate seat row in human-readable format
*    row = ( (index - offset) / 4 ) + 1
*/
void PrintSeatName(int seat)
{
    if (seat < 0)
    {
        printf("Invalid seat index: %d\n", seat);
    }
    else
    {
        unsigned int column = 4;
        unsigned int intLetter = seat % column;
        unsigned int row = ((seat - intLetter) / column) + 1;
        char letter;
        switch (intLetter)
        {
        case 0: 
            letter = 'A';
            break;
        case 1:
            letter = 'B';
            break;
        case 2:
            letter = 'C';
            break;
        default:
            letter = 'D';
            break;
        }
        /* TODO: Implement this function. */
        printf("Seat %d%c is now occupied by passenger ", row, letter);
    }


}

/*
** Returns true (non-0) if the 0-based seat index represents a seat on the
** plane (is within the valid range of seats).  Otherwise returns false (0).
** The seat index is 0-based, from 0 to NUM_SEATS - 1.
*/
int IsValidSeatIndex(int seat)
{
    if (seat < 0 || seat > NUM_SEATS - 1)
    {
        return 0;
    }

    return 1;
}

/*
** Translates from human-friendly seat name (1A, 1B, 1C, etc.) to
** code-friendly seat index (0, 1, 2, etc.). This insulates the rest
** of the code from the complex nature of seat letters and numbers and
** allows the rest of the program to deal with simple 0-based seat index.
**
** Scans for a user-entered seat row and letter, such as 1A, 2B, etc.
** Returns the seat index (0 to NUM_SEATS - 1) if the user input is valid,
** otherwise returns INVALID_SEAT.
**
** STUDENTS: Remember that integers and characters in C are related, and
**           arithmetic can be done on both.
*/
int GetSeatInput(void)
{
    char seat[4]; /*hold seat input 3 characters and null terminator */
    unsigned int row = 0; /*seat row 1 - 12*/
    char letter = '\0'; /*hold seat letter A - D*/

    unsigned int itemsRead;
    itemsRead = scanf("%3s", seat); /*limit the input to just 3 characters to prevent buffer overflow*/
    if (itemsRead != 1)
    {
        printf("Invalid - no input \n");
        return INVALID_SEAT;
    }
    {
        unsigned int index = 0;
        char zero = '0';
        while (seat[index] != '\0')
        {
            if (index == 0) /*1st character in seat input*/
            {
                if (toupper(seat[index]) <= zero || !isdigit(seat[index])) /*catch all 0, negative and non digits character*/
                {
                    printf("Invalid input - 1s character: %c\n", seat[index]);
                    return INVALID_SEAT;
                }
                /* 1st input character is a digit 1 - 9 */
                row = seat[index] - zero; /*convert number to range 0 - 9*/
            }
            else if (index == 1) /*2nd character in seat input*/
            {
                if (isalpha(seat[index])) /*2nd character is a letter*/
                {
                    letter = seat[index];

                }
                else if (isdigit(seat[index])) /*2nd character is a digit 0 - 9*/
                {
                    row *= 10; /*make row (1st digit) base 10 to add 2nd digit*/
                    row += seat[index] - zero; /*convert row to range from 0 - 99*/
                }
                else /* is neither a character or a digit*/
                {
                    printf("Invalid input - 2nd character: %c\n", seat[index]);
                    return INVALID_SEAT;
                }
            }
            else /*3rd character*/
            {
                if (isdigit(seat[index])) /*validate 3rd character can't be 0 - 9*/
                {
                    printf("Invalid input - 3rd character: %c", seat[index]);
                    return INVALID_SEAT;
                }
                else if (toupper(seat[index - 1]) >= 'A') /*validate 3rd chacter can't be another letter*/
                {
                    printf("Invalid input - 3rd character: %c", seat[index]);
                    return INVALID_SEAT;
                }
                else
                {
                    letter = seat[index];
                }
            }
            index++;
        }
    }

    int seatIndex = convertSeatNumToSeatIndex(row, letter); /*convert user reserve seat to 0 base index*/
    printf("Converted seat is index: %d\n", seatIndex);
    return seatIndex;

}

/*
** Asks the user once to enter a seat that is either
** occupied (isOccupied == 1, true) or empty (isOccupied == 0, false).
** If an invalid seat is entered, print this exact message:
** ERROR: Sorry, that seat is not valid.
**
** If the seat is supposed to be empty but is occupied, print this message:
** ERROR: Sorry, seat XX was expected to be empty but is occupied by passenger NNN.
**
** If the seat is supposed to be occupied but is empty, print this message:
** ERROR: Sorry, seat XX was expected to be occupied but is empty.
**
** Returns the seat index (0 to NUM_SEATS - 1) if the user entered a valid seat,
** otherwise returns INVALID_SEAT.
**
** STUDENTS: Notice how this function and many others in the program are insulated from
**           having to understand the geometry (rows, letters) of the plane, and can simply
**           deal with the seat index as a plain integer.
**
** TODO:
**   - Simplify and flatten out this function by using early return
**   - Consolidate redundant code.
**   - Apply const where possible.
**
** OPTIONAL: For bonus points...
**   - Move the seat occupied validation logic into the two wrapper functions that call this one.
**   - This function consolidates the error message: ERROR: Sorry, that seat is not valid.
**     whenever GetSeatInput returns INVALID_SEAT.
*/
int GetSeatFromUser(const int isOccupied)
{
    int inputSeat = GetSeatInput(); /*get reserve seat in 0 base index*/

    if (IsValidSeatIndex(inputSeat))
    {
        if (isOccupied != 0 && g_reservations[inputSeat] == 0)
        {
            printf("ERROR: Sorry, seat ");
            PrintSeatName(inputSeat);
            printf(" was expected to be occupied but is empty.\n");
            inputSeat = INVALID_SEAT;
        }
        else if (isOccupied == 0 && g_reservations[inputSeat] != 0)
        {
            printf("ERROR: Sorry, seat ");
            PrintSeatName(inputSeat);
            printf(" was expected to be empty but is occupied by passenger %d.\n", g_reservations[inputSeat]);
            inputSeat = INVALID_SEAT;
        }
    }
    else
    {
        printf("ERROR: Sorry, that seat is not valid.\n");
        return INVALID_SEAT;
    }

    return inputSeat;
}

/*
** Wrapper function to improve readability of calling code.
** STUDENTS: Do not modify this function, unless you are doing the bonus points above.
*/
int GetOccupiedSeatFromUser(void)
{
    return GetSeatFromUser(/* isOccupied */ 1);
}

/*
** Wrapper function to improve readability of calling code.
** STUDENTS: Do not modify this function, unless you are doing the bonus points above.
** Notes:
** isOccupied = 0, seat is available
** isOccupied = 1, seat is not available
* 
*/
int GetEmptySeatFromUser(void)
{
    return GetSeatFromUser(/* isOccupied */ 0); /* 0 = find available seat*/
}

/*
** Ask the user to enter a passenger ID.
**   Use this exact prompt: Enter passenger ID between 1 and 999:
** Each time an invalid ID is entered, print this exact error message:
** ERROR: ID must be an integer between 1 and 999.
** 
** Ask repeatedly until a valid answer is given.
** Returns the valid passenger ID entered by the user.
*/
int GetPassengerIdFromUser(void)
{
    char id[5];
    unsigned int itemsRead;
    unsigned int index;
    unsigned int pID = 0;
    unsigned int minID = 0;
    unsigned int maxID = 999;
    int isBreak; /*flag break out of while loop*/
    for (;;)
    {
        isBreak = 0; /*initialize to false*/
        printf("Enter passenger ID between 1 and 999: ");
        itemsRead = scanf("%4s[^\n]", id);
        if (itemsRead == 1)
        {
            pID = 0;
            index = 0;
            unsigned int zero = 48;
            while (id[index] != '\0')
            {
                if (index == 0) /*1st entered character can't be less than equals to 0 or non-digit*/
                {
                    if (id[index] <= zero || !isdigit(id[index]))
                    {
                        printf("ERROR: ID must be an integer between 1 and 999 \n");
                        ClearInputBuffer();
                        isBreak = 1;
                        break;
                    }
                    pID += (id[index] - zero); /*keep running number of passenger ID*/

                }
                else
                {
                    if (index > 2) /*entered passenger ID greater than 3 characters*/
                    {
                        printf("ERROR: ID must be an integer between 1 and 999 \n");
                        ClearInputBuffer();
                        isBreak = 1;
                        break;
                    }
                    else if (!isdigit(id[index])) /*non-digit entered*/
                    {
                        printf("ERROR: ID must be an integer between 1 and 999 \n");
                        ClearInputBuffer();
                        isBreak = 1;
                        break;
                    }
                    pID *= 10; /*shift current entered number to the right by 10 */
                    pID += (id[index] - zero); /*keep running number of passenger ID*/
                }

                index++;
            }

        }
        else /* invalid/blank passenger ID*/
        {
            printf("ERROR: ID must be an integer between 1 and 999 \n");
            ClearInputBuffer();
        }
        if (!isBreak) /*while loop exited*/
        {
            if (pID <= minID || pID > maxID) /*validate passenger ID greater equals to 1 and less than 99*/
            {
                printf("ERROR: ID must be an integer between 1 and 999 \n");
                ClearInputBuffer();
            }
            break; /*valid passenger ID, break out of infinit loop*/
        }

    }
    return pID; /*return valid passener ID*/
}

/*
** Finds and returns the seat index (0 to NUM_SEATS - 1) with the given passenger ID.
** If the passenger ID is not found in any seat, returns INVALID_SEAT.
*/
int FindSeatWithPassenger(const int passengerId)
{
    /* TODO: Delete this line.  It supresses the warning about an unused argument.  */
    passengerId;

    /* TODO: Implement this function. */
    return INVALID_SEAT;
}

/*
** Ask the user which seat (row and letter) to reserve.  The seat must be empty.
**   - Print this exact prompt: Enter a seat to reserve:
**   - Call GetEmptySeatFromUser().
** If the seat is occupied
**   - GetEmptySeatFromUser will print an error and return INVALID_SEAT.
**   - Return back to the main menu.  (You do not have to repeat asking).
** If the seat is empty, ask for a passenger ID by calling GetPassengerIdFromUser().
**   - If the ID is valid, but that passenger already has another seat reserved, then:
**       - Print this exact message: ERROR: Passenger NNN is already at seat XX.
**       - Return back to the main menu.  (You do not have to repeat asking).
**   - Otherwise the seat is assigned to that passenger, with the message:
**     Seat XX is now occupied by passenger NNN.
*/
void ReserveSeat(void)
{
    
    PrintReserveSeatExplanation(); /* Explanation of seating arrangement*/
    printf("Enter a seat to reserve: ");
    int inputSeat = GetEmptySeatFromUser(); /* wrapper function*/
    if (inputSeat == 0)
    {
        printf("Failed to reserve your seat \n");
    }
    else
    {
        int pID = GetPassengerIdFromUser();
        PrintSeatName(inputSeat);
        printf("%d\n", pID); /*include passenger ID in print message Seat XX is now occupied by passenger*/
        g_reservations[inputSeat] = pID; /*reserve passenger ID on specify seat index*/
    } 
}

/*
** Ask the user for an occupied seat whose reservation they wish to be cancelled.
**   - Print this exact prompt: Enter a seat to cancel:
**   - Call GetOccupiedSeatFromUser().
** If it is occupied, then the passenger ID in that seat is reset to 0.
**   - Print this exact message: Seat XX is now empty and no longer occupied by passenger NNN.
** If it is empty:
**   - GetOccupiedSeatFromUser will print an error message and return INVALID_SEAT.
**   - Return to the main menu.
*/
void CancelReservation(void)
{
    // TODO: Implement this function.
    

}

/*
** TODO: Flatten out this function using early-return.
**       Do not change the behavior of the function.
*/
void MoveSeat(void)
{
    int fromSeat;
    printf("FROM which seat to move: ");
    fromSeat = GetOccupiedSeatFromUser();

    if (IsValidSeatIndex(fromSeat))
    {
        int toSeat;
        printf("TO which seat to move: ");
        toSeat = GetEmptySeatFromUser();

        if (IsValidSeatIndex(toSeat))
        {
            g_reservations[toSeat] = g_reservations[fromSeat];
            g_reservations[fromSeat] = 0;

            printf("Moved passenger %d from seat ", g_reservations[toSeat]);
            PrintSeatName(fromSeat);
            printf(" to seat ");
            PrintSeatName(toSeat);
            printf(".\n");
        }
    }
}

/*
** Print a neatly formatted display of the current seating reservations
** as shown in this example.
**   - Seat row numbers and passenger IDs are right justified as shown.
**   - Seat letters are centered as shown.
**   - Only non-zero passenger IDs are printed.
**
**     ------------------------------
**      Current Seating Reservations
**     ------------------------------
**          |  A  |  B  |  C  |  D  |
**     -----+-----+-----+-----+-----+
**        1 | 123 |     |     |     |
**        2 |     |     |     |     |
**        3 |     |     |   2 |     |
**        4 |     |     |     |     |
**        5 |     |  64 |     |     |
**        6 | 345 |     |     |     |
**        7 |     |     |     |     |
**        8 |     |   7 |     |     |
**        9 |     |     |     |     |
**       10 |     |     |     | 678 |
**       11 |     |     |     |     |
**       12 |     |     |     |     |
**
** OPTIONAL (Not graded.  No credit given). Improve the code below...
**   - If NUM_LETTERS was bigger than 4...
**       - Have the correct overall width.
**       - Have the correct number of columns.
**   - Line up columns whether each seat is empty or occupied.
**   - Right align row numbers and seat names.
**   - (OK for title to be fixed width and left justified)
**   - I do not recommend creating helper functions.
**     My solution is pretty tight without them.
*/
void DisplaySeating(void)
{
    int row, letter;

    /****** Title ******/
    printf("\n------------------------------");
    printf("\n Current Seating Reservations");
    printf("\n------------------------------");

    /****** Column Header ******/
    printf("\n     |  A  |  B  |  C  |  D  |");
    printf("\n-----+-----+-----+-----+-----+");
    printf("\n");

    /****** Rows ******/
    for (row = 0; row < NUM_ROWS; ++row)
    {
        const int rowNumber = row + 1;
        printf("%4d |", rowNumber);
        for (letter = 0; letter < NUM_LETTERS; ++letter)
        {
            int seat = row * NUM_LETTERS + letter;
            int id = g_reservations[seat];

            if (id == 0) printf("     |");
            else printf(" %d |", id);
        }
        printf("\n");
    }
}

/*
** Display the title and main menu of the program.
**
** STUDENTS: Do not modify this function.
*/
void DisplayMenu(void)
{
    printf("\n");
    printf("---------------------------\n");
    printf("--- CheapSkate Air Menu ---\n");
    printf("---------------------------\n");
    printf("  (0) Exit the Program\n");
    printf("  (1) Reserve a seat\n");
    printf("  (2) Cancel Reservation\n");
    printf("  (3) Move Seat Reservation\n");
    printf("  (4) Display Current Seating\n");
}

/*
** Prompts the user to enter a valid menu choice.
**   - Call DisplayMenu().
**   - Prompt the user with: Please choose:
** Repeats if the menu choice is not valid.
** Otherwise, returns the valid menu choice.
**
** STUDENTS: Do not modify this function.
*/
int GetMenuChoice(void)
{
    /* STUDENTS: for (;;) is an infinite loop, by design.
    **           This avoids a compiler warning from while(1).
    */
    for (;;)
    {
        int input;
        DisplayMenu();
        printf("\nPlease choose: ");
        if (scanf("%d", &input) < 1)
        {
            printf("ERROR: Invalid input, exiting program.\n");
            return 0;
        }
        if (input >= 0 && input <= 4) return input;
        printf("ERROR: %d is invalid.  Please choose again.\n", input);
    }
}


/*
** TODO: Convert the if/else code into a switch.
**       Do not change the behavior of the function.
*/
int main(void)
{
    int choice = 0;
    ClearReservations();
    do /*display the menu at least once*/
    {
        choice = GetMenuChoice();
        switch (choice)
        {
            case 1: 
                ReserveSeat();
                break;
            case 2: 
                CancelReservation();
                break;
            case 3: 
                MoveSeat();
                break;
            case 4:
                DisplaySeating();
                break;
            default:  /*when choice is == 0*/
                break;
        }
    } while (choice != 0); /*evaluate after the body of the loop has executed*/


    return 0;
}
