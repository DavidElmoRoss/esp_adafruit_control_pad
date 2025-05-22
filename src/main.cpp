/*
    Title:  Takes input from the CONTROL PAD and says which KEY WAS PRESSED/RELEASED
    Author: Dave Ross
    Date:   May 21st, 2025
    Description:  There are 8 keys on the control pad app.
                  
                  In numerical order these keys are given by:

                  1, 2, 3, 4, UParrow, DOWNarrow, LEFTarrow, RIGHTarrow
                                (5)      (6)         (7)        (8)
                  Each of these keys is pressed then has to be released
                  When the UParrow key is pressed it generates   !B51  (1 is pressed)
                  When the UParrow key is released it generates  !B50  (0 is released)
*/

#include "arduino.h"                // include the arduino library
#include <HardwareSerial.h>         // need hardware serial library to talk to bluefruit uart

HardwareSerial SerialPort(2);       // use UART2 for connecting to Bluefruit Uart LE
#define RX_PIN 32                   // connect RX of Bluefruit to pin 32
#define TX_PIN 33                   // connect TX of BLuefruit to pin 33
int bnum=0;                         // set bnumn # to zero
int bnum1=0;                        // set bnum1 # to zero
void setup() 
{
  Serial.begin(115200);             // initialize default UART0 port to 115200                                    // This way we can send chars to PC screen if necessary
                                    // set Bluetooth port to 115200, 8 bits no parity and
                                    // assign the RX and TX pin connections for ESP32
  SerialPort.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN); 
}
void loop()
{    
  if (SerialPort.available())                // if char available from BLUEFRUIT UART FRIEND
  {
    delay(20);                               // wait 20ms
    if(SerialPort.read() =='!')              // check to see if it is the '!' character
    {
      delay(20);                             // if it is delay 20 ms then 
        if(SerialPort.read() == 'B')         // if it is a 'B' then
         { 
          delay(20);                         // delay 20ms
             bnum=SerialPort.read();         // set bnum to next char
             delay(20);                      // wait 20ms
                bnum1=SerialPort.read();     // put next char into bnum1
                if ((bnum>='1')&&(bnum<='8')) //is a number button 1..8 (not really necessary)
                {
                    switch(bnum)             // switch on key pressed then on whether it was
                    {                        // pressed (1) or released (0)
                        case '1':   switch(bnum1)
                                    {
                                      case '1':Serial.println("1 Key pressed   !B11");
                                               break;
                                      case '0':Serial.println("1 Key released  !B10");
                                               break;
                                    }
                                    
                                    break;
                        case '2':  switch(bnum1)
                                    {
                                      case '1':Serial.println("2 Key pressed   !B21");
                                               break;
                                      case '0':Serial.println("2 Key released  !B20");
                                               break;
                                    } 
                                    break;
                        case '3':   switch(bnum1)
                                    {
                                      case '1':Serial.println("3 Key pressed   !B31");
                                               break;
                                      case '0':Serial.println("3 Key released  !B30");
                                               break;
                                    } 
                                    break;
                        case '4':   switch(bnum1)
                                    {
                                      case '1':Serial.println("4 Key pressed   !B41");
                                               break;
                                      case '0':Serial.println("4 Key released  !B40");
                                               break;
                                    } 
                                    break;
                        case '5':   switch(bnum1)      // THIS IS THE UPARROW
                                    {
                                      case '1':Serial.println("UpArrow Key pressed  !B51");
                                               break;
                                      case '0':Serial.println("UpArrow Key released !B50");
                                               break;
                                    } 
                                    break;
                        case '6':   switch(bnum1)      // THIS IS THE DOWNARROW
                                    {
                                      case '1':Serial.println("DownArrow Key pressed  !B61");
                                               break;
                                      case '0':Serial.println("DownArrow Key released !B60");
                                               break;
                                    } 
                                    break;
                        case '7':   switch(bnum1)      // THIS IS THE LEFT ARROW
                                    {
                                      case '1':Serial.println("Left Arrow Key pressed  !B71");
                                               break;
                                      case '0':Serial.println("Left Arrow Key released !B70");
                                               break;
                                    } 
                                    break;
                        case '8':   switch(bnum1)       // THIS IS THE RIGHT ARROW
                                    {
                                      case '1':Serial.println("Right Arrow Key pressed  !B81");
                                               break;
                                      case '0':Serial.println("Right Arrow Key released !B80");
                                               break;
                                    } 
                                    break;
                        default:    break;
                    }
                }
        }
      
    }
  }
}