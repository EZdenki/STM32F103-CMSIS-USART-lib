# STM32F103-CMSIS-USART
USART library to provide serial IO functionality via a serial terminal.
<br>
### Hardware Setup:
+ Use a USB serial dongle. Connect the dongle's Rx wire to pin PA9 (Tx) on the STM32 / Blue Pill, and the dongle's Tx pin to pin PA10 (Rx). Connect the ground pin on the dongle to the ground pin on the STM32 /Blue Pill.
+ Find the COM port that the dongle is connected to, and open a serial terminal (such as PuTTY) to that COM port with a baud rate of 115,200.
### Install Library and Sample Program:
+ To download, type ```git clone https://github.com/sandynomike/STM32F103-CMSIS-USART.git```, then move to the newly created directory.
+ To upload and run program on Windows, type ```make clean && make```.
+ To run under non-Windows machines, makefile and the upload utilities must be modified accordingly.
### The following functionality implemented on the STM32F103 (Bluepill):
+ USART_init: Initialize USART1, USART2, or USART3 at 115,200 baud.
+ USART_putc: Output single character to serial port
+ USART_puts: Output string to serial port
+ USART_puti: Output integer in desired base to serial port
+ USART_puth: Output padded hex number to serial port
+ USART_getc: Get single character from serial port
+ USART_gets: Get string from serial port
+ USART_pollc: Poll serial port for input
