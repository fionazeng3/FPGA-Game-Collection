/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'nios2'
 * SOPC Builder design path: ../../nios2.sopcinfo
 *
 * Generated: Tue May 29 15:41:08 PDT 2018
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00020820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x12
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x12
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00020820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x12
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x12
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x21080
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x21080
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x21080
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios2"


/*
 * busInput configuration
 *
 */

#define ALT_MODULE_CLASS_busInput altera_avalon_pio
#define BUSINPUT_BASE 0x21050
#define BUSINPUT_BIT_CLEARING_EDGE_REGISTER 0
#define BUSINPUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUSINPUT_CAPTURE 0
#define BUSINPUT_DATA_WIDTH 8
#define BUSINPUT_DO_TEST_BENCH_WIRING 0
#define BUSINPUT_DRIVEN_SIM_VALUE 0
#define BUSINPUT_EDGE_TYPE "NONE"
#define BUSINPUT_FREQ 50000000
#define BUSINPUT_HAS_IN 1
#define BUSINPUT_HAS_OUT 0
#define BUSINPUT_HAS_TRI 0
#define BUSINPUT_IRQ -1
#define BUSINPUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUSINPUT_IRQ_TYPE "NONE"
#define BUSINPUT_NAME "/dev/busInput"
#define BUSINPUT_RESET_VALUE 0
#define BUSINPUT_SPAN 16
#define BUSINPUT_TYPE "altera_avalon_pio"


/*
 * busOuput configuration
 *
 */

#define ALT_MODULE_CLASS_busOuput altera_avalon_pio
#define BUSOUPUT_BASE 0x21040
#define BUSOUPUT_BIT_CLEARING_EDGE_REGISTER 0
#define BUSOUPUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUSOUPUT_CAPTURE 0
#define BUSOUPUT_DATA_WIDTH 8
#define BUSOUPUT_DO_TEST_BENCH_WIRING 0
#define BUSOUPUT_DRIVEN_SIM_VALUE 0
#define BUSOUPUT_EDGE_TYPE "NONE"
#define BUSOUPUT_FREQ 50000000
#define BUSOUPUT_HAS_IN 0
#define BUSOUPUT_HAS_OUT 1
#define BUSOUPUT_HAS_TRI 0
#define BUSOUPUT_IRQ -1
#define BUSOUPUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUSOUPUT_IRQ_TYPE "NONE"
#define BUSOUPUT_NAME "/dev/busOuput"
#define BUSOUPUT_RESET_VALUE 0
#define BUSOUPUT_SPAN 16
#define BUSOUPUT_TYPE "altera_avalon_pio"


/*
 * charRec configuration
 *
 */

#define ALT_MODULE_CLASS_charRec altera_avalon_pio
#define CHARREC_BASE 0x21000
#define CHARREC_BIT_CLEARING_EDGE_REGISTER 0
#define CHARREC_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHARREC_CAPTURE 0
#define CHARREC_DATA_WIDTH 1
#define CHARREC_DO_TEST_BENCH_WIRING 0
#define CHARREC_DRIVEN_SIM_VALUE 0
#define CHARREC_EDGE_TYPE "NONE"
#define CHARREC_FREQ 50000000
#define CHARREC_HAS_IN 1
#define CHARREC_HAS_OUT 0
#define CHARREC_HAS_TRI 0
#define CHARREC_IRQ -1
#define CHARREC_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHARREC_IRQ_TYPE "NONE"
#define CHARREC_NAME "/dev/charRec"
#define CHARREC_RESET_VALUE 0
#define CHARREC_SPAN 16
#define CHARREC_TYPE "altera_avalon_pio"


/*
 * charSent configuration
 *
 */

#define ALT_MODULE_CLASS_charSent altera_avalon_pio
#define CHARSENT_BASE 0x21010
#define CHARSENT_BIT_CLEARING_EDGE_REGISTER 0
#define CHARSENT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHARSENT_CAPTURE 0
#define CHARSENT_DATA_WIDTH 1
#define CHARSENT_DO_TEST_BENCH_WIRING 0
#define CHARSENT_DRIVEN_SIM_VALUE 0
#define CHARSENT_EDGE_TYPE "NONE"
#define CHARSENT_FREQ 50000000
#define CHARSENT_HAS_IN 1
#define CHARSENT_HAS_OUT 0
#define CHARSENT_HAS_TRI 0
#define CHARSENT_IRQ -1
#define CHARSENT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHARSENT_IRQ_TYPE "NONE"
#define CHARSENT_NAME "/dev/charSent"
#define CHARSENT_RESET_VALUE 0
#define CHARSENT_SPAN 16
#define CHARSENT_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x21080
#define JTAG_UART_IRQ 5
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * led_pio configuration
 *
 */

#define ALT_MODULE_CLASS_led_pio altera_avalon_pio
#define LED_PIO_BASE 0x21060
#define LED_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define LED_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_PIO_CAPTURE 0
#define LED_PIO_DATA_WIDTH 8
#define LED_PIO_DO_TEST_BENCH_WIRING 0
#define LED_PIO_DRIVEN_SIM_VALUE 0
#define LED_PIO_EDGE_TYPE "NONE"
#define LED_PIO_FREQ 50000000
#define LED_PIO_HAS_IN 0
#define LED_PIO_HAS_OUT 1
#define LED_PIO_HAS_TRI 0
#define LED_PIO_IRQ -1
#define LED_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_PIO_IRQ_TYPE "NONE"
#define LED_PIO_NAME "/dev/led_pio"
#define LED_PIO_RESET_VALUE 0
#define LED_PIO_SPAN 16
#define LED_PIO_TYPE "altera_avalon_pio"


/*
 * loadi configuration
 *
 */

#define ALT_MODULE_CLASS_loadi altera_avalon_pio
#define LOADI_BASE 0x21030
#define LOADI_BIT_CLEARING_EDGE_REGISTER 0
#define LOADI_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LOADI_CAPTURE 0
#define LOADI_DATA_WIDTH 1
#define LOADI_DO_TEST_BENCH_WIRING 0
#define LOADI_DRIVEN_SIM_VALUE 0
#define LOADI_EDGE_TYPE "NONE"
#define LOADI_FREQ 50000000
#define LOADI_HAS_IN 0
#define LOADI_HAS_OUT 1
#define LOADI_HAS_TRI 0
#define LOADI_IRQ -1
#define LOADI_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LOADI_IRQ_TYPE "NONE"
#define LOADI_NAME "/dev/loadi"
#define LOADI_RESET_VALUE 0
#define LOADI_SPAN 16
#define LOADI_TYPE "altera_avalon_pio"


/*
 * onchip_mem configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_mem altera_avalon_onchip_memory2
#define ONCHIP_MEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEM_BASE 0x0
#define ONCHIP_MEM_CONTENTS_INFO ""
#define ONCHIP_MEM_DUAL_PORT 0
#define ONCHIP_MEM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_INIT_CONTENTS_FILE "nios2_onchip_mem"
#define ONCHIP_MEM_INIT_MEM_CONTENT 1
#define ONCHIP_MEM_INSTANCE_ID "NONE"
#define ONCHIP_MEM_IRQ -1
#define ONCHIP_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEM_NAME "/dev/onchip_mem"
#define ONCHIP_MEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEM_SINGLE_CLOCK_OP 0
#define ONCHIP_MEM_SIZE_MULTIPLE 1
#define ONCHIP_MEM_SIZE_VALUE 100000
#define ONCHIP_MEM_SPAN 100000
#define ONCHIP_MEM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEM_WRITABLE 1


/*
 * switches07 configuration
 *
 */

#define ALT_MODULE_CLASS_switches07 altera_avalon_pio
#define SWITCHES07_BASE 0x21070
#define SWITCHES07_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES07_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES07_CAPTURE 0
#define SWITCHES07_DATA_WIDTH 8
#define SWITCHES07_DO_TEST_BENCH_WIRING 0
#define SWITCHES07_DRIVEN_SIM_VALUE 0
#define SWITCHES07_EDGE_TYPE "NONE"
#define SWITCHES07_FREQ 50000000
#define SWITCHES07_HAS_IN 1
#define SWITCHES07_HAS_OUT 0
#define SWITCHES07_HAS_TRI 0
#define SWITCHES07_IRQ -1
#define SWITCHES07_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCHES07_IRQ_TYPE "NONE"
#define SWITCHES07_NAME "/dev/switches07"
#define SWITCHES07_RESET_VALUE 0
#define SWITCHES07_SPAN 16
#define SWITCHES07_TYPE "altera_avalon_pio"


/*
 * transEn configuration
 *
 */

#define ALT_MODULE_CLASS_transEn altera_avalon_pio
#define TRANSEN_BASE 0x21020
#define TRANSEN_BIT_CLEARING_EDGE_REGISTER 0
#define TRANSEN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define TRANSEN_CAPTURE 0
#define TRANSEN_DATA_WIDTH 1
#define TRANSEN_DO_TEST_BENCH_WIRING 0
#define TRANSEN_DRIVEN_SIM_VALUE 0
#define TRANSEN_EDGE_TYPE "NONE"
#define TRANSEN_FREQ 50000000
#define TRANSEN_HAS_IN 0
#define TRANSEN_HAS_OUT 1
#define TRANSEN_HAS_TRI 0
#define TRANSEN_IRQ -1
#define TRANSEN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TRANSEN_IRQ_TYPE "NONE"
#define TRANSEN_NAME "/dev/transEn"
#define TRANSEN_RESET_VALUE 0
#define TRANSEN_SPAN 16
#define TRANSEN_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
