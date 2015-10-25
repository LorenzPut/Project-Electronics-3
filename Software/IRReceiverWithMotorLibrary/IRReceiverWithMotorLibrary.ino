#include <Motor.h>

#include <IRremote.h>

/*Dit programma moet de motor vooruit laten rijden
Hierbij zal gebruik gemaakt worden van functies*/                                                            

Motor motor(4,6,7,8);

int IRpin = 5;
IRrecv irrecv(IRpin);
decode_results results; // Kan zijn dat auto hierdoor helemaal niet rijdt, stop functie blijft geactiveerd.

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();  
}

void loop()
{
  if(irrecv.decode(&results))
  {
    Serial.println(results.value, DEC);
      if(results.value == 16736925)
      {
        motor.Forward();
      }
      if(results.value == 16712445)
      {
        motor.Stop();
      }  
      if(results.value == 16720605)
      {
        motor.TurnLeft();
      }
      if(results.value == 16761405)
      {
        motor.TurnRight();
      }
      if(results.value == 16754775)
      {
        motor.BackWards();
      }    
    irrecv.resume();
  }  
}


