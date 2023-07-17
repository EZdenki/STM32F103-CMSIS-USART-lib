//  main.c
//  Sample Program to show the functionality of the STM32F103-CMSIS-USART library
//      Version 1.0   07/17/2023    Updated Comments and Core Files
//
//  Target Microcontroller: STM32F103 (Blue Pill)
//  Mike Shegedin, 07/2023  Started
//
//  Goals:  Implement routines to read and write from USART serial port.
//
//  ========================================================================================== 
//     ***  HARDWARE SETUP  ***          
//  Hook up serial dongle to Tx and Rx pins of the microcontroller.
//  On the STM32F103 (Bluepill):
//                 Tx    Rx
//        USART 1  PA9   PA10
//        USART 2  PA2   PA3 (Not 5V tolerant)
//        USART 3  PB10  PB11
//  ==========================================================================================

#include "stm32f103xb.h"                  // Primary CMSIS header file
#include "STM32F103-CMSIS-USART-lib.c"    // USART library

//  ========================================================================================== 
//  main 
//  ========================================================================================== 
int
main()
{
  char myInput;
  uint32_t myInputLen;

  USART_init( USART1 );   // Init USART1 and associate with USART routines

  //  Identify Currently Used USART
  USART_puts("\n\n\n\n*** USART Serial Port Test Program ***\n\nConnected to USART");
  if( USART_USART == USART1 )
    USART_putc( '1' );
  else if( USART_USART == USART2 )
    USART_putc( '2' );
  else if( USART_USART == USART3 )
    USART_putc( '3' );
  else
    USART_putc( '?' );
  USART_putc( '\n' );


  //  Single Character Input Menu
  USART_puts("\n    Menu\n");
  USART_puts(  "============\n");
  USART_puts(  "  1: Happy\n");
  USART_puts(  "  2: Sad\n");
  USART_puts(  "------------\n");
  USART_puts(  "Enter choice:");
  do
  {
    myInput = USART_getc();
    if( myInput == '1' ) USART_puts( "\n :-)\n");
    else if( myInput == '2' ) USART_puts( "\n :-(\n");
    else
    {
      USART_puts( "\nBad input (code: " );
      USART_puti( myInput, 10 );
      USART_puts( "). Try again!\n" );
    }
  } while (myInput != '1' && myInput != '2' );

  // String Input Test  
  USART_puts( "\n\nString Input Test\nEnter a string: ");

  #define aStringLen 20
  char aString[ aStringLen ];
  myInputLen = USART_gets( aString, aStringLen );
  USART_puts( "\n\nThe string you entered was: " );
  USART_puts( aString );
  USART_puts( "\nThis string is " );
  USART_puti( myInputLen, 10 );
  USART_puts( " characters long.\n\n\n" );

  // Polling Character Input Test
  USART_puts( "Polling Character Test\nHit any key to advance counter to 5.\n" );
  for( int8_t x = 1; x<=5; x++ ) // Cycle from -5 to 5 for output digit
  {
    do
    {
      USART_puti( x, 10 );              // Output digit
      for(uint32_t t=0; t<667e3; t++);  // Pause for approx. 1 second (12 cycles/iteration)
      myInput = USART_pollc();          // Poll serial port for input
    } while ( !myInput );               // Repeat same character if no input
    USART_puts( " (You hit " );         // Otherwise, if got a character, display its
    USART_putc( myInput );              // ASCII code.
    USART_puts( ")\n");
  }
  
  USART_puts( "\nGoodbye!\n");  // End test program

  return 1;
}
