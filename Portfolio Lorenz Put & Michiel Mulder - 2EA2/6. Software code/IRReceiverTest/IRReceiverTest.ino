/*
Dit programma wordt de gebruikt om de IR receiver te testen
+ het uitlezen van codes per speciefieke toets
 
 Pin 1 naar Vout (pin 11 van Arduino)
 Pin 2 naar GND
 Pin 3 naar Vcc (+5v van Arduino)

*/

#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value, DEC); // Print the Serial 'results.value'
      irrecv.resume();   // Receive the next value
    }
  
  
}
