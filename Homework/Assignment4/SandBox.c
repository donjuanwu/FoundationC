/*

Notes:
1. ctype.h
	- provide functions primarily operate on it values representing characters, typically for classification or conversion of character data.
2. Scanf() format specifier:
   1. %[^\n] is a character set format specifier, means capture everything except the new line


*/

#define _CRT_SECURE_NO_WARNINGS /*suppress Visual Studio scanf warnings*/
#include <stdio.h>
#include <ctype.h> /*provide a set of functions for testing and manipulating characters*/

const int INVALID_SEATS = -1;

//int GetUserSeatInput(void)
//{
//	/*
//	Char	Value	
//	1		49
//	2		50
//	3		51
//	4		52
//	5		53
//	6		54
//	7		55
//	8		56
//	9		57
//	10		58
//	11		59
//	12		60
//	A		65
//	B		66
//	C		67
//	D		68
//	
//	*/
//	
//	char seat[4];
//	unsigned int itemsRead;
//	printf("Enter a seat to reserve: ");
//	itemsRead = scanf("%3[^\n]", seat); /*limit the input to just 3 characters to prevent buffer overflow*/
//	unsigned int index = 0;
//	unsigned int convertSeatCharToInt = 0;
//	
//	if (itemsRead != 1)
//	{
//		char ch;
//		if (scanf(" %c", &ch) < 1);
//		printf("No seat reserve \n");
//		return INVALID_SEATS;
//	}
//	else
//	{
//		
//		printf("Your reserve seat number is \n ");
//		while (seat[index] != '\0')
//		{
//			if (!isalnum(seat[index])) /*validate is alpha numeric*/
//			{
//				printf("invalid character not alphanumeric: %c", seat[index]);
//				return INVALID_SEATS;
//			}
//			else
//			{
//				if (index == 0) /*1st character entered*/
//				{
//					if (toupper(seat[index]) < 49 || toupper(seat[index] > 57)) /*1st character is either less than 0 and greater than 9*/
//					{
//						printf("1st character is not valid: %c", seat[index]);
//						return INVALID_SEATS;
//					}
//					/*1st character is in between of 1 - 9 inclusive*/
//					convertSeatCharToInt += toupper(seat[index]); /*keep running total of seat choice in number format*/
//				}
//				else if (index == 1) /* 2nd character entered*/
//				{
//					/*check first character seat choice, entered number is greater than 1 (49)*/
//					if (convertSeatCharToInt > 49) /*seat entered from 2 - 9*/
//					{
//						/*validate 2nd entered character must be A || B || C || D*/
//						if (toupper(seat[index]) < 65 || toupper(seat[index]) > 68)
//						{
//							printf("2nd character is not valid: %c", toupper(seat[index]));
//							return INVALID_SEATS;
//						}
//						convertSeatCharToInt += toupper(seat[index]); /*add 1st digit with 2nd letter (A - B)*/
//
//					}
//					else /*1st entered number is 1 */
//					{
//						/* only allow follow up character numbers (0 - 2) or letters (A - D) */
//						switch (toupper(seat[index]))
//						{
//							case 48: /* 0 */
//								convertSeatCharToInt += toupper(seat[index]);
//								break;
//							case 49: /* 1 */
//								convertSeatCharToInt += toupper(seat[index]);
//								break;
//							case 50: /* 2 */
//								convertSeatCharToInt += toupper(seat[index]);
//								break;
//							case 65: /* A */
//								convertSeatCharToInt += toupper(seat[index]);
//								break;
//							case 66: /* B */
//								convertSeatCharToInt += toupper(seat[index]);
//								break;
//							case 67: /* C */
//								convertSeatCharToInt += toupper(seat[index]);
//								break;
//							case 68: /* D */
//								convertSeatCharToInt += toupper(seat[index]);
//								break;
//							default:
//								printf("2nd character is not valid: %c", toupper(seat[index]));
//								return INVALID_SEATS;
//
//
//						}
//
//					}
//				}
//				else /* 3rd character entered*/
//				{
//					/*validate previous two entered characters least is one number followed by a letter, like 1A = (49 + 65)*/
//					if (convertSeatCharToInt >= 114)
//					{
//						unsigned int numSeat = (convertSeatCharToInt % 65) - 48; /*calc numeric value*/
//						char ch = 'A';
//						printf("3rd character is not valid: %c", toupper(seat[index]));
//						return INVALID_SEATS;
//						
//					}
//					else /*previous two characters entered are two numbers that is less than equals to 12*/
//					{
//						/*validate 3rd character is from A - D*/
//						if (toupper(seat[index]) < 65 || toupper(seat[index]) > 68) /* follow chacters is outside of letters from A - D*/
//						{
//							printf("3rd character is not valid: %c", toupper(seat[index]));
//							return INVALID_SEATS;
//						}
//						convertSeatCharToInt += toupper(seat[index]); /*keep running seat choice in number format*/
//
//					}
//					
//				}
//			}
//			index++; /*increment index*/
//		} 
//		/*validate reserve seat has number (1 - 12) followed by a letter character*/
//		/*1A = 114 (49 + 65), 12D = */
//		if (convertSeatCharToInt < 114 || convertSeatCharToInt > 167)
//		{
//			printf("not valid, contains no letters");
//			return INVALID_SEATS;
//		}
//	}
//	
//		printf("seat choice is valid, it number format value is: %d", convertSeatCharToInt);
//		return 0;
//		
//}

void ClearInputBuffer(void)
{
	int ch;
	while ((ch = getchar()) != '\n' && (ch != EOF)); /*flush input buffer*/
}

int convertSeatNumToSeatIndex2(unsigned int row, char seatLetter)
{
	unsigned int rowLow = 1;
	unsigned int rowHigh = 12;
	unsigned int letterLow = 0;
	unsigned int letterHigh = 3;
	
	if (row < rowLow || row > rowHigh)
	{
		return INVALID_SEATS;
	}
	/*convert seat letter to offset index (A = 0, B = 1, C = 2, D = 3*/
	unsigned int letterOffSet = toupper(seatLetter) - 'A';
	if (letterOffSet < letterLow || letterOffSet > letterHigh)
	{
		return INVALID_SEATS;
	}
	{
		unsigned int column = 4;
		unsigned int index = (row - 1) * column + letterOffSet;
		return index;
	}

}

int GetUserInput2(void)
{
	char seat[4]; /*hold seat input 3 characters and null terminator */
	unsigned int row = 0; /*seat row 1 - 12*/
	char letter = '\0'; /*hold seat letter A - D*/

	unsigned int itemsRead;
	printf("Enter a seat to reserve: ");
	itemsRead = scanf("%3[^\n]", seat); /*limit the input to just 3 characters to prevent buffer overflow*/
	if (itemsRead != 1)
	{
		printf("Invalid - no input \n");
		/*char ch;
		if (scanf(" %c", &ch) != 1);*/
		return INVALID_SEATS;
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
					return INVALID_SEATS;
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
					return INVALID_SEATS;
				}
			}
			else /*3rd character*/
			{
				if (isdigit(seat[index])) /*validate 3rd character can't be 0 - 9*/
				{
					printf("Invalid input - 3rd character: %c", seat[index]);
					return INVALID_SEATS;
				}
				else if (toupper(seat[index - 1]) >= 'A') /*validate 3rd chacter can't be another letter*/
				{
					printf("Invalid input - 3rd character: %c", seat[index]);
					return INVALID_SEATS;
				}
				else
				{
					letter = seat[index];
				}
			}
			index++;
		}
	}

 	int seatIndex = convertSeatNumToSeatIndex2(row, letter);
 	printf("Converted seat to 0 base index: %d", seatIndex);
	return 0;
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
int GetPassengerIdFromUser2(void)
{
	char id[4];
	unsigned int itemsRead;
	unsigned int index;
	unsigned int pID = 0;
	unsigned int minID = 0;
	unsigned int maxID = 999;
	for (;;)
	{
		printf("Enter passenger ID between 1 and 999: ");
		itemsRead = scanf("%3s[^\n]", id);
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
						break;
					}
					pID += (id[index] - zero); /*keep running number of passenger ID*/

				}
				else if (index == 1) /*2nd character*/
				{
					if (!isdigit(id[index])) /*not a digit character*/
					{
						printf("ERROR: ID must be an integer between 1 and 999 \n");
						ClearInputBuffer();
						break;
					}
					pID *= 10; /*shift the current digit to the right by 10, prep to add the jext digit*/
					pID += (id[index] - zero); /*keep running number of passenger ID*/

				}
				else /*3rd character*/
				{
					if (!isdigit(id[index])) /*not a digit character*/
					{
						printf("ERROR: ID must be an integer between 1 and 999 \n");
						ClearInputBuffer();
						break;
					}
					pID *= 10; /*shift the current digit to the right by 10, prep to add the next digit*/
					pID += (id[index] - zero); /*keep running number of passenger ID*/
				}
				index++;
			}
			
		}
		else /* invalid/blank passenger ID*/
		{
			/*char ch;
			scanf(" %c", &ch);*/
			printf("ERROR: ID must be an integer between 1 and 999 \n");
			ClearInputBuffer();
		}

		if (pID <= minID || pID > maxID)
		{
			printf("ERROR: ID must be an integer between 1 and 999 \n");
			ClearInputBuffer();
		}
		break; /*break out of infinit loop*/
	}
	return pID;
}


int GetPassengerIdFromUser3(void)
{
	unsigned int itemsRead;
	unsigned int pID; 
	unsigned int idLow = 1;
	unsigned int idHigh = 999;
	unsigned int minID = 0;
	unsigned int maxID = 999;
	for (;;)
	{
		printf("Enter passenger ID between %d and %d: ", idLow, idHigh);
		itemsRead = scanf("%d", &pID);
		if (itemsRead == 1 && pID > minID && pID <= maxID)
		{
			return pID;
		}
		else /* invalid or blank input */
		{
			if (itemsRead == 0)
			{
				printf("ERROR: ID must be an integer between 1 and 999 \n");
				ClearInputBuffer();
			}
			else
			{
				printf("ERROR: ID must be an integer between 1 and 999 \n");
				ClearInputBuffer();
			}
			
		}
	}
	return pID;
}








int main(void)
{
	//int index = GetUserInput2();
	int passID = GetPassengerIdFromUser2();
	printf("Passenger ID: %d", passID);
	return 0;
 }