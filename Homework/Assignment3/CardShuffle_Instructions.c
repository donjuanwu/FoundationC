/*
** Copyright (C) September 2024 by Colby O'Donnell <colbster@uw.edu>
** Assignment 3, CardShuffle.c (OPTIONAL), INSTRUCTIONS
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
**   Developed: October 30, 2011
**   Updated:   September 27, 2020
**
** Student Solution
**   Author:    --- Enter your name here ---
**   Date:      --- Enter date here ---
**
** INSTRUCTIONS
**
** Write a program which shuffles a standard deck of 52 cards N times, where N is input by the user.
** Two variations of this shuffle are done, an "out" shuffle and an "in" shuffle.
** Both shuffle types (in and out) divide the deck exactly in half.
** Both shuffle types take 1 card from the bottom of each half, alternating between them, and place
** the card on the top of the new pile.
**
**   The "out" shuffle takes from the bottom of the LOWER half first.
**   The "in"  shuffle takes from the bottom of the UPPER half first.
**
** The user is asked how many times (N) to do the OUT shuffle.
** The program sorts the deck once, and then performs OutShuffleDeck() N times.
** The user is asked how many times (N) to do the IN shuffle.
** The program sorts the deck once, and then performs InShuffleDeck() N times.
**
** See example below.
**
** Do not use if statements in your solution.  You can solve this entirely
** with loops (while or for).
**
** TESTING
**
** Clearly demonstrate and describe in words each significant pattern that occurs when
** OutShuffleDeck and InShuffleDeck are called enough times.
** Copy and paste your test output to CardShuffle.txt.
**
** Below is an example of your program running when the user chooses 3 shuffles for each function.
** You will need to make your console 160 columns wide, and your code editor 162 columns wide.
**
** Enter the number of OUT shuffles: 3
**
** Doing 3 OUT shuffles:
**   Ac Ad Ah As 2c 2d 2h 2s 3c 3d 3h 3s 4c 4d 4h 4s 5c 5d 5h 5s 6c 6d 6h 6s 7c 7d 7h 7s 8c 8d 8h 8s 9c 9d 9h 9s Tc Td Th Ts Jc Jd Jh Js Qc Qd Qh Qs Kc Kd Kh Ks
**   Ac 7h Ad 7s Ah 8c As 8d 2c 8h 2d 8s 2h 9c 2s 9d 3c 9h 3d 9s 3h Tc 3s Td 4c Th 4d Ts 4h Jc 4s Jd 5c Jh 5d Js 5h Qc 5s Qd 6c Qh 6d Qs 6h Kc 6s Kd 7c Kh 7d Ks
**   Ac 4d 7h Ts Ad 4h 7s Jc Ah 4s 8c Jd As 5c 8d Jh 2c 5d 8h Js 2d 5h 8s Qc 2h 5s 9c Qd 2s 6c 9d Qh 3c 6d 9h Qs 3d 6h 9s Kc 3h 6s Tc Kd 3s 7c Td Kh 4c 7d Th Ks
**   Ac 9c 4d Qd 7h 2s Ts 6c Ad 9d 4h Qh 7s 3c Jc 6d Ah 9h 4s Qs 8c 3d Jd 6h As 9s 5c Kc 8d 3h Jh 6s 2c Tc 5d Kd 8h 3s Js 7c 2d Td 5h Kh 8s 4c Qc 7d 2h Th 5s Ks
**
** Enter the number of IN shuffles: 3
**
** Doing 3 IN shuffles:
**   Ac Ad Ah As 2c 2d 2h 2s 3c 3d 3h 3s 4c 4d 4h 4s 5c 5d 5h 5s 6c 6d 6h 6s 7c 7d 7h 7s 8c 8d 8h 8s 9c 9d 9h 9s Tc Td Th Ts Jc Jd Jh Js Qc Qd Qh Qs Kc Kd Kh Ks
**   7h Ac 7s Ad 8c Ah 8d As 8h 2c 8s 2d 9c 2h 9d 2s 9h 3c 9s 3d Tc 3h Td 3s Th 4c Ts 4d Jc 4h Jd 4s Jh 5c Js 5d Qc 5h Qd 5s Qh 6c Qs 6d Kc 6h Kd 6s Kh 7c Ks 7d
**   Ts 7h 4d Ac Jc 7s 4h Ad Jd 8c 4s Ah Jh 8d 5c As Js 8h 5d 2c Qc 8s 5h 2d Qd 9c 5s 2h Qh 9d 6c 2s Qs 9h 6d 3c Kc 9s 6h 3d Kd Tc 6s 3h Kh Td 7c 3s Ks Th 7d 4c
**   5s Ts 2h 7h Qh 4d 9d Ac 6c Jc 2s 7s Qs 4h 9h Ad 6d Jd 3c 8c Kc 4s 9s Ah 6h Jh 3d 8d Kd 5c Tc As 6s Js 3h 8h Kh 5d Td 2c 7c Qc 3s 8s Ks 5h Th 2d 7d Qd 4c 9c
*/

#include <stdio.h>

/*
** Normally const int variabled would be prefered, but array dimensions below must be a known
** constant at compile-time.  In ANSI-C, a const int variable is still a variable whose
** value is not known until runtime, but the const tells the compiler to treat it as read-only.
*/
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS (NUM_RANKS * NUM_SUITS)

/*
** Each card is stored as an int whose value is 0 to NUM_CARDS.  The only function
** that cares about what the value means is PrintDeck().
**
** Normally it would be better to avoid a global varaibles, but we have not yet
** introduced passing arrays to functions, as well as how to avoid copying data.
** So a global variable is the only tool we have at the moment, such as it is.
*/
int g_deck[NUM_CARDS];

/* Called once before OutShuffleDeck() and once more before InShuffleDeck(). */
void InitializeDeck(void)
{
    int index = 0;
    for (index = 0; index < NUM_CARDS; ++index)
    {
        /* Give each card a unique number */
        g_deck[index] = index;
    }
}

/*
** Prints the contents of the deck in one line.
** If called immediately after InitializeDeck(), it will print:
** Ac Ad Ah As 2c 2d 2h 2s 3c 3d 3h 3s 4c 4d 4h 4s 5c 5d 5h 5s 6c 6d 6h 6s 7c 7d 7h 7s 8c 8d 8h 8s 9c 9d 9h 9s Tc Td Th Ts Jc Jd Jh Js Qc Qd Qh Qs Kc Kd Kh Ks
*/
void PrintDeck(void)
{
    /* TODO: Implement this function */
}

/*
** Performs a single "out" shuffle of the deck.
** Divides the deck into two equally sized halves, a lower half and an upper half.
** Alternatively takes one card from the bottom of each half, starting with the LOWER
** half first, and places that card on top of the new pile.
*/
void OutShuffleDeck(void)
{
    /* TODO: Implement this function */
}

/*
** Performs a single "in" shuffle of the deck.
** Divides the deck into two equally sized halves, a lower half and an upper half.
** Alternatively takes one card from the bottom of each half, starting with the UPPER
** half first, and places that card on top of the new pile.
*/
void InShuffleDeck(void)
{
    /* TODO: Implement this function */
}

/* Do not modify this function */
//int main(void)
//{
//    int numShuffles = 0;
//    int counter = 0;
//
//    printf("\nEnter the number of OUT shuffles: ");
//    scanf("%d", &numShuffles);
//    printf("\nDoing %d OUT shuffles:\n", numShuffles);
//    InitializeDeck();
//    PrintDeck();
//    for (counter = 0; counter < numShuffles; ++counter)
//    {
//        OutShuffleDeck();
//        PrintDeck();
//    }
//
//    printf("\nEnter the number of IN shuffles: ");
//    scanf("%d", &numShuffles);
//    printf("\nDoing %d IN shuffles:\n", numShuffles);
//    InitializeDeck();
//    PrintDeck();
//    for (counter = 0; counter < numShuffles; ++counter)
//    {
//        InShuffleDeck();
//        PrintDeck();
//    }
//
//    return 0;
//}
