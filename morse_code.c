/*
 ===============================================================================
 Name        : morse_code.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
 ===============================================================================
 */

#include <board_api.h>
#include <chip.h>
#include <gpio_8xx.h>
#include <lpc_types.h>
#include <stdint.h>

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>
#include "morse.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here



/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/


/**
 * @brief		Function display short signal(Green LED and "." on 7-segment display)
 */

void shortSignal() {
	Board_LED_Toggle(2);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 10, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 11, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 12, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 13, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 14, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 15, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 16, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 17, FALSE);
}

/**
 * @brief		Function display long signal(Blue LED and "-" on 7-segment display)
 */
void longSignal() {
	Board_LED_Toggle(2);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 10, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 11, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 12, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 13, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 14, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 15, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 16, FALSE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 17, TRUE);
}

/**
 * @brief		Function off display
 */
void off() {

	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 10, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 11, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 12, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 13, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 14, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 15, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 16, TRUE);
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 17, TRUE);
}

/**
 * @brief		Function delay
 * @param[in]	delay - delay time
 */
static void delay(uint32_t delay) {
	while (delay--) {
	}
}

int main(void) {

	SystemCoreClockUpdate();

#if defined (__USE_LPCOPEN)

#if !defined(NO_BOARD_LIB)
	// Set up and initialize all required blocks and
	// functions related to the board hardware
	Board_Init();

#endif
#endif

	// TODO: insert code here
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 10);  //a
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 11);    //b
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 12);   //c
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 13);   //d
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 14);  //e
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 15);    //f
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 16, FALSE);  //g
	Chip_GPIO_SetPinState(LPC_GPIO_PORT, 0, 17, FALSE);  //h

	off();


	char name[] = "Rafal";
	int nameInMorseCode[15];
	morse_createNameInMorseCode(name, 15, nameInMorseCode);




	// Force the counter to be placed into memory
	volatile static int i = 0;
	// Enter an infinite loop, just incrementing a counter
	while (1) {
		i++;


		for (int i = 0; i < 15; i++) {

			switch (nameInMorseCode[i]) {
			case SHORT:
				shortSignal();
				delay(1000000);
				off();
				delay(1000000);
				break;

			case LONG:
				longSignal();
				delay(3000000);
				off();
				delay(2000000);
				break;

			default:
				break;
			}

		}
		delay(5000000);  //end of name
	}
	return 0;
}
