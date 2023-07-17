# STM32F103-CMSIS-USART-lib
USART library to provide serial IO functionality via a serial terminal and sample program to show off the functionality of the library.
<br>
### Hardware Setup:
+ Use a USB serial dongle. Connect the dongle's ground pin to the STM32 (Blue Pill) ground, and connect the dongle's Tx and Rx wires as follows:

| USART  |  Tx  |  Rx  |
| :---:    | :---: | :---:  |
| USART1 | PA9  | PA10 |
| USART2 | PA2  | PA3  |
| USART3 | PB10 | PB11 |
+ Find the COM port on the PC that the dongle is connected to by using Device Manager under Winodws, or ```dir /dev``` under Linux.
  Open a serial terminal (such as PuTTY under Windows or minCom under Linux) and point the terminal program to the relevant COM port.
  The COM port baud rate is 115,200.
### Install Library and Sample Program:
+ To download, type ```git clone https://github.com/sandynomike/STM32F103-CMSIS-USART.git```, then move to the newly created directory.
+ Type ```make clean && make``` to build and upload the program to the Blue Pill.
### The following functionality implemented on the STM32F103 (Bluepill):
+ USART_init: Initialize USART1, USART2, or USART3 at 115,200 baud.
+ USART_putc: Output single character to serial port
+ USART_puts: Output string to serial port
+ USART_puti: Output integer in desired base to serial port
+ USART_puth: Output padded hex number to serial port
+ USART_getc: Get single character from serial port
+ USART_gets: Get string from serial port
+ USART_pollc: Poll serial port for input
