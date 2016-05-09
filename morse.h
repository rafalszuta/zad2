#ifndef _MORSE_H
#define _MORSE_H

#include <stdlib.h>

#define LONG 1500 /*Long signal*/
#define LONG_DELAY 1000 /*Pause after long signal*/
#define MORSE_SIGN_SIZE 5 /*Morse char code max size*/
#define SHORT 500 /*Short signal*/
#define SHORT_DELAY 500 /*Pause after short signal*/

#define NONNULL(...) __attribute__((nonnull(__VA_ARGS__)))

NONNULL(1,3) int morse_createNameInMorseCode(const char *, const size_t, int *);

#endif //_MORSE_H
