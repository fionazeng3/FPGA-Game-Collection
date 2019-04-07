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

#include <stdio.h>
#include <stdlib.h>
#include "sys/alt_stdio.h"
#include "sys/unistd.h"
#include "altera_avalon_pio_regs.h"
#include <string.h>
#define LED (volatile char*) 0x21060
#define PLAYERIN (volatile char*) 0x21050
#define PLAYEROUT (volatile char*) 0x21040
#define load (volatile char*) 0x21030
#define transmit (volatile char*) 0x21020
#define charSent (volatile char*) 0x21010
#define charRec (volatile char*) 0x21000


char buffer[20];

char stupid() {
    char c1 = alt_getchar();
    alt_getchar();
    char c2 = alt_getchar();
    alt_getchar();
    int big = c1 - '0';
    int small = c2 - '0';
    int result = big * 10 + small;
    char value = (char) result;
    return value;

}
void receive() {
	char result = '0';
	while((*(charRec) & 0x1) != 0x1) {}
	result = *(PLAYERIN);
	result -= '0';
	int trans = (int) result;
	itoa(trans, buffer, 10);
	alt_printf("received grid is %s\n", buffer);
	return;
}

void send() {
	alt_putstr("Which grid do you want to choose? \n");
    alt_putstr("Now please enter the grid \n");
	char result = stupid();
	*(PLAYEROUT) = (char) result;
	result -= '0';
	int trans = (int) result;
	if(trans == 2) alt_printf("yes\n");
	//itoa(trans, buffer, 10);
	//alt_printf("sending char %s\n",buffer);
	*(transmit) = 0x1;
	usleep(1000);
	*(load) = 0x1;
	while(!charRec){}
	usleep(2000);
	*(transmit) = 0x0;
	*(load) = 0x0;
	alt_printf("sent \n");
	return;
}
int main()
{
	while(1) {
		printf("send or receive?");
		char choice = alt_getchar();
		if (choice == 'r') {
			receive();
		} else {
			send();
		}
	}

}


