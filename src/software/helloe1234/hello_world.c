/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

// This c program is developed from smokeTest
// as we only added a while loop to read data
// repeatedly
#include <stdio.h>
#include <stdlib.h>
#include "sys/alt_stdio.h"
#include "sys/unistd.h"
#include "altera_avalon_pio_regs.h"
#include <string.h>
#define LED (volatile char*) 0x21060
#define busin (volatile char*) 0x21050
#define busout (volatile char*) 0x21040
#define load (volatile char*) 0x21030
#define transmit (volatile char*) 0x21020
#define charSent (volatile char*) 0x21010
#define charRec (volatile char*) 0x21000


int main()
{
	alt_putstr("Receive or Send? Please enter the initial letter of your choice \n");
	char choice = alt_getchar();
	alt_getchar();
	if(choice == 'r') {
		char result = '0';
		while((*(charRec) & 0x1) != 0x1) {}
		result = *(busin);
		alt_printf("received char %c\n", result);
		*LED = result;
	} else {
		while(1){
			alt_printf("please write\n");
			char data = alt_getchar();
			alt_getchar();
			*(busout) = data;
			*(transmit) = 1;
			usleep(1000);
			*(load) = 1;
			while(!charRec){}
			usleep(2000);
			*(load) = 0;
			*(transmit) = 0;

			// input is connected to our own output for test purpose
			char output = *(busin);
			*(LED) = *(busin);
			alt_printf("data is %c\n", output);
		}
	}

	return 0;
}
