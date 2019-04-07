#include <stdio.h>
#include "sys/alt_stdio.h"
#include "sys/unistd.h"
#include "altera_avalon_pio_regs.h"
#define LED (volatile char*) 0x21060
#define busInput (volatile char*) 0x21050
#define busOutput (volatile char*) 0x21040
#define load (volatile char*) 0x21030
#define transEn (volatile char*) 0x21020
#define charSent (volatile char*) 0x21010
#define charReceived (volatile char*) 0x21000


int main()
{
  alt_printf("please write\n");
  *(busOutput) = alt_getchar();;
  *(transEn) = 1;
  usleep(1000);
  *(load) = 1;
  while(!charReceived){}
  usleep(2000);
  *(load) = 0;
  *(transEn) = 0;
  char output = *(busInput);
  *(LED) = *(busInput);
  alt_printf("data is %c\n", output);
  return 0;
}
