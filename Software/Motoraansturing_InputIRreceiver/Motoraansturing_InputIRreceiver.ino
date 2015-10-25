  #include <IRremote.h>

/*Dit programma moet de motor vooruit laten rijden*/
/*Hierbij zal gebruik gemaakt worden van functies
*/                                                            
const int leftOne = 4;
const int leftTwo = 6;
const int rightOne = 7;
const int rightTwo = 8;


int IRpin = 5;
IRrecv irrecv(IRpin);
decode_results results; // Kan zijn dat auto hierdoor helemaal niet rijdt, stop functie blijft geactiveerd.

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(leftOne, OUTPUT);
  pinMode(leftTwo, OUTPUT);
  pinMode(rightOne, OUTPUT);
  pinMode(rightTwo, OUTPUT);
}

void loop()
{
  if(irrecv.decode(&results))
  {
    Serial.println(results.value, DEC);
      if(results.value == 16736925)
      {
        Forward();
      }
      if(results.value == 16712445)
      {
        Stop();
      }  
      if(results.value == 16720605)
      {
        TurnRight();
      }
      if(results.value == 16761405)
      {
        TurnLeft();
      }
      if(results.value == 16754775)
      {
        BackWards();
      }
    
    irrecv.resume();
  }

  
}
void Forward()
{
    digitalWrite(leftOne, HIGH);
    digitalWrite(leftTwo, LOW);
    digitalWrite(rightOne, LOW);
    digitalWrite(rightTwo, HIGH);
}
void BackWards()
{
    digitalWrite(leftOne, LOW);
    digitalWrite(leftTwo, HIGH);
    digitalWrite(rightOne, HIGH);
    digitalWrite(rightTwo, LOW);
}
void TurnLeft()
{
    digitalWrite(leftOne, HIGH);
    digitalWrite(leftTwo, LOW);
    digitalWrite(rightOne, HIGH);
    digitalWrite(rightTwo, LOW);
}
void TurnRight()
{
    digitalWrite(leftOne, LOW);
    digitalWrite(leftTwo, HIGH);
    digitalWrite(rightOne, LOW);
    digitalWrite(rightTwo, HIGH);
}
void Stop()
{
    digitalWrite(leftOne, HIGH);
    digitalWrite(leftTwo, HIGH);
    digitalWrite(rightOne, HIGH);
    digitalWrite(rightTwo, HIGH);
}
