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

int convertSeatNumToSeatIndex(unsigned int num)
{
	unsigned int divisor = 12;
	unsigned seatIndex = num % divisor;
	printf("Your seat index: %d", seatIndex);
	return seatIndex;
}

int GetUserSeatInput(void)
{
	/*
	Char	Value	
	1		49
	2		50
	3		51
	4		52
	5		53
	6		54
	7		55
	8		56
	9		57
	10		58
	11		59
	12		60
	A		65
	B		66
	C		67
	D		68
	
	*/
	
	char seat[4];
	unsigned int itemsRead;
	printf("Enter a seat to reserve: ");
	itemsRead = scanf("%3[^\n]", seat); /*limit the input to just 3 characters to prevent buffer overflow*/
	unsigned int convertSeatCharToInt = 0;
	if (itemsRead != 1)
	{
		char ch;
		printf("No seat reserve \n");
		return INVALID_SEATS;
	}
	else
	{
		unsigned int index = 0;
		printf("Your reserve seat number is \n ");
		while (seat[index] != '\0')
		{
			if (!isalnum(seat[index])) /*validate is alpha numeric*/
			{
				printf("invalid character not alphanumeric: %c", seat[index]);
				return INVALID_SEATS;
			}
			else
			{
				if (index == 0) /*1st character entered*/
				{
					if (toupper(seat[index]) < 49 || toupper(seat[index] > 57)) /*1st character is either less than 0 and greater than 9*/
					{
						printf("1st character is not valid: %c", seat[index]);
						return INVALID_SEATS;
					}
					/*1st character is in between of 1 - 9 inclusive*/
					convertSeatCharToInt += toupper(seat[index]); /*keep running total of seat choice in number format*/
				}
				else if (index == 1) /* 2nd character entered*/
				{
					/*check first character seat choice, entered number is greater than 1 (49)*/
					if (convertSeatCharToInt > 49) /*seat entered from 2 - 9*/
					{
						/*validate 2nd entered character must be A || B || C || D*/
						if (toupper(seat[index]) < 65 || toupper(seat[index]) > 68)
						{
							printf("2nd character is not valid: %c", toupper(seat[index]));
							return INVALID_SEATS;
						}
						convertSeatCharToInt += toupper(seat[index]); /*add 1st digit with 2nd letter (A - B)*/

					}
					else /*1st entered number is 1 */
					{
						/* only allow follow up character numbers (0 - 2) or letters (A - D) */
						switch (toupper(seat[index]))
						{
							case 48: /* 0 */
								convertSeatCharToInt += toupper(seat[index]);
								break;
							case 49: /* 1 */
								convertSeatCharToInt += toupper(seat[index]);
								break;
							case 50: /* 2 */
								convertSeatCharToInt += toupper(seat[index]);
								break;
							case 65: /* A */
								convertSeatCharToInt += toupper(seat[index]);
								break;
							case 66: /* B */
								convertSeatCharToInt += toupper(seat[index]);
								break;
							case 67: /* C */
								convertSeatCharToInt += toupper(seat[index]);
								break;
							case 68: /* D */
								convertSeatCharToInt += toupper(seat[index]);
								break;
							default:
								printf("2nd character is not valid: %c", toupper(seat[index]));
								return INVALID_SEATS;


						}

					}
				}
				else /* 3rd character entered*/
				{
					/*validate previous two entered characters least is one number followed by a letter, like 1A = (49 + 65)*/
					if (convertSeatCharToInt >= 114)
					{
						unsigned int numSeat = (convertSeatCharToInt % 65) - 48; /*calc numeric value*/
						char ch = 'A';
						printf("3rd character is not valid: %c", toupper(seat[index]));
						return INVALID_SEATS;
						
					}
					else /*previous two characters entered are two numbers that is less than equals to 12*/
					{
						/*validate 3rd character is from A - D*/
						if (toupper(seat[index]) < 65 || toupper(seat[index]) > 68) /* follow chacters is outside of letters from A - D*/
						{
							printf("3rd character is not valid: %c", toupper(seat[index]));
							return INVALID_SEATS;
						}
						convertSeatCharToInt += toupper(seat[index]); /*keep running seat choice in number format*/

					}
					
				}
			}
			index++; /*increment index*/
		} 
		/*validate reserve seat has number (1 - 12) followed by a letter character*/
		/*1A = 114 (49 + 65), 12D = */
		if (convertSeatCharToInt < 114 || convertSeatCharToInt > 167)
		{
			printf("not valid, contains no letters");
			return INVALID_SEATS;
		}
	}
	
		printf("seat choice is valid, it number format value is: %d", convertSeatCharToInt);
		unsigned int seatIndex = convertSeatNumToSeatIndex(convertSeatCharToInt); /*seat choice in number format*/
		
}



int main(void)
{
	GetUserSeatInput();
	return 0;
 }