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
		printf("Upper reserve seat number: ");
		while (seat[index] != '\0')
		{
			if (!isalnum(seat[index])) /*validate is alpha numeric*/
			{
				printf("Seat number is not valid: %c", seat[index]);
				return INVALID_SEATS;
			}
			else
			{
				if (index == 0) /*1st character entered*/
				{
					if (toupper(seat[index]) < 49 || toupper(seat[index] > 57))
					{
						printf("1st character, seat number is not valid: %c", seat[index]);
						return INVALID_SEATS;
					}
					convertSeatCharToInt += toupper(seat[index]); /*keep running total of character value*/
				}
				else if (index == 1) /* 2nd character entered*/
				{
					/*validate first entered number is greater than 1 */
					if (convertSeatCharToInt > 49) /*guest entered from 2 - 9*/
					{
						/*validate 2nd entered character must be A || B || C || D*/
						if (toupper(seat[index]) < 65 || toupper(seat[index]) > 68)
						{
							printf("2nd character, seat number is not valid: %c", toupper(seat[index]));
							return INVALID_SEATS;
						}
						convertSeatCharToInt += toupper(seat[index]); /*add 1st digit with 2nd letter (A - B)*/

					}
					else /*1st entered number is 1 */
					{
						/* only allow numbers (0 - 2) or letters (A - D) */
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
								printf("2nd character, seat number is not valid: %c", toupper(seat[index]));
								return INVALID_SEATS;


						}

					}
				}
				else /* 3rd character entered*/
				{

				}
			}
			





			///*exclude less than equals 0, greater than letter D */
			//else if (toupper(seat[index]) < 49 || toupper(seat[index] > 68))
			//{
			//	printf("Seat number is not valid: %c", seat[index]);
			//	return INVALID_SEATS;
			//}
			//else if (toupper(seat[index]) > 60 && toupper(seat[index]) < 65) /*exclude number 13 - 16 */
			//{
			//	printf("Seat number is not valid: %c", seat[index]);
			//	return INVALID_SEATS;
			//}

			//if (!isalnum(seat[index])) /*validate is alpha numeric*/
			//{
			//	printf("Seat number is not valid: %c", seat[index]);
			//	return INVALID_SEATS;
			//}
			//else if (toupper(seat[index]) <= 48 || toupper(seat[index]) > 68) /*validate no zero, negative or letters beyond D*/
			//{
			//	printf("Seat number is not valid: %c", seat[index]);
			//	return INVALID_SEATS;
			//}
			//else if (toupper(seat[index]) > 60 && toupper(seat[index]) < 65) /*validate no numbers between 61 and 64 (inclusive) */
			//{
			//	printf("Seat number is not valid: %c", seat[index]);
			//	return INVALID_SEATS;
			//}

			printf("%c", toupper(seat[index]));
			index++;
		}
	}
	
	
		return 0;
}

int main(void)
{
	GetUserSeatInput();
	return 0;
 }