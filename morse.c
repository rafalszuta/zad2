#include "morse.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/**
 * @brief			Function copying one array to another
 * @param[in,out]	destination - pointer to destination array
 * @param[in]		source - pointer to source array
 * @param[in]		sourceSize - source array size
 */
static void morse_copyMorseChar(int * destination, const int * source, int sourceSize)
{
	memcpy(destination, source, sizeof(int) * sourceSize);
}

/**
 * @brief			Function convert char to morse signs array
 * @param[in]		sign - single char
 * @param[in,out]	p_morseCode = pointer to storage for morse code
 * @return			Number of signal in morse code
 */
static int morse_charToMorseCode(const char sign, int * p_morseCode)
{
	int morseCharSize = 0;

	switch(sign)
	{
		default:
			return 0;
			//morse_copyMorseChar(p_morseCode, (int []){}, morseCharSize);
		break;

		case 'A':
		case 'a':
			morseCharSize = 2;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, LONG },
				morseCharSize);
		break;

		case 'B':
		case 'b':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, SHORT, SHORT,
				SHORT }, morseCharSize);
		break;

		case 'C':
		case 'c':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, SHORT, LONG,
				SHORT }, morseCharSize);
		break;

		case 'D':
		case 'd':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, SHORT, SHORT },
				morseCharSize);
		break;

		case 'E':
		case 'e':
			morseCharSize = 1;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT }, morseCharSize);
		break;

		case 'F':
		case 'f':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, SHORT, LONG,
				SHORT}, morseCharSize);
		break;

		case 'G':
		case 'g':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, LONG, SHORT },
				morseCharSize);
		break;

		case 'H':
		case 'h':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, SHORT, SHORT,
				SHORT }, morseCharSize);
		break;

		case 'I':
		case 'i':
			morseCharSize = 2;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, SHORT },
				morseCharSize);
		break;

		case 'J':
		case 'j':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, LONG, LONG,
				LONG }, morseCharSize);
		break;

		case 'K':
		case 'k':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, SHORT, LONG },
				morseCharSize);
		break;

		case 'L':
		case 'l':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, LONG, SHORT,
				SHORT }, morseCharSize);
		break;

		case 'M':
		case 'm':
			morseCharSize = 2;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, LONG },
				morseCharSize);
		break;

		case 'N':
		case 'n':
			morseCharSize = 2;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, SHORT },
				morseCharSize);
		break;

		case 'O':
		case 'o':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, LONG, LONG },
				morseCharSize);
		break;

		case 'P':
		case 'p':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, LONG, LONG,
				SHORT }, morseCharSize);
		break;

		case 'Q':
		case 'q':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, LONG, SHORT,
				LONG }, morseCharSize);
		break;

		case 'R':
		case 'r':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, LONG, SHORT },
				morseCharSize);
		break;

		case 'S':
		case 's':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, SHORT, SHORT },
				morseCharSize);
		break;

		case 'T':
		case 't':
			morseCharSize = 1;
			morse_copyMorseChar(p_morseCode, (int []){ LONG }, morseCharSize);
		break;

		case 'U':
		case 'u':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, SHORT, LONG },
				morseCharSize);
		break;

		case 'V':
		case 'v':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, SHORT, SHORT,
				LONG }, morseCharSize);
		break;

		case 'W':
		case 'w':
			morseCharSize = 3;
			morse_copyMorseChar(p_morseCode, (int []){ SHORT, LONG, LONG },
				morseCharSize);
		break;


		case 'X':
		case 'x':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, SHORT, SHORT,
				LONG }, morseCharSize);
		break;

		case 'Y':
		case 'y':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, SHORT, LONG,
				LONG }, morseCharSize);
		break;

		case 'Z':
		case 'z':
			morseCharSize = 4;
			morse_copyMorseChar(p_morseCode, (int []){ LONG, LONG, SHORT,
				SHORT }, morseCharSize);
		break;
/*
		case '':
		case '':
			morseCharSize = ;
			morse_copyMorseChar(p_morseCode, (int []){}, morseCharSize);
		break;*/
	}

	return morseCharSize;
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief		Function convert name string to array with morse values
 * @param[in]	name - pointer to name
 * @param[in]	nameLength - lengthOfName
 * @return		Number of signals in morse name
 */
int morse_createNameInMorseCode(const char * p_name, const size_t nameLength, int * p_nameInMorseCode)
{
	int nameInMorseCounter = 0;

	for (int i = 0; i < nameLength; ++i)
	{
		int charInMorseCode[MORSE_SIGN_SIZE] = {0};
		int morseCharSize = morse_charToMorseCode(p_name[i], charInMorseCode);

		for (int j = 0; j < morseCharSize; ++j)
		{
			p_nameInMorseCode[nameInMorseCounter++] = charInMorseCode[j];
		}
	}

	return nameInMorseCounter;
}
