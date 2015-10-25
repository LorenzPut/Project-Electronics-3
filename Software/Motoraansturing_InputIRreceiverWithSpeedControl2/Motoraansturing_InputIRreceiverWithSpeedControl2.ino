/*Dit programma moet de motor vooruit laten rijden*/
/*Hierbij zal gebruik gemaakt worden van functies
en het serialread commando om de input van de computer uit te kunnen lezen.*/
#include <IRremote.h>
// moeten PWM pinnen zijn
const int leftOne = 3;
const int leftTwo = 5;
const int rightOne = 6;
const int rightTwo = 9;

int speed1 = 85;


int IRpin = 11;
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
      if(results.value == 16738455)
      {
        speed1 -=10;
      }
      if(results.value == 16750695)
      {
        speed1 +=10;
      }     
    Serial.println(results.value, DEC);
      if(results.value == 16736925)
      {
        Forward(speed1);
      }
      if(results.value == 16712445)
      {
        Stop();
      }  
      if(results.value == 16720605)
      {
        TurnRight(speed1);
      }
      if(results.value == 16761405)
      {
        TurnLeft(speed1);
      }
      if(results.value == 16754775)
      {
        Backward(speed1);
      }
    
    irrecv.resume();
  }
  delay(333);
  
  
  
}
void Forward(int AdjustableSpeed)
{
    digitalWrite(leftOne, AdjustableSpeed);
    digitalWrite(leftTwo, 0);
    digitalWrite(rightOne, 0);
    digitalWrite(rightTwo, AdjustableSpeed);
}
void Backward(int AdjustableSpeed)
{
    digitalWrite(leftOne, LOW);
    digitalWrite(leftTwo, AdjustableSpeed);
    digitalWrite(rightOne, AdjustableSpeed);
    digitalWrite(rightTwo, LOW);
}
void TurnLeft(int AdjustableSpeed)
{
    digitalWrite(leftOne, AdjustableSpeed);
    digitalWrite(leftTwo, LOW);
    digitalWrite(rightOne, AdjustableSpeed);
    digitalWrite(rightTwo, LOW);
}
void TurnRight(int AdjustableSpeed)
{
    digitalWrite(leftOne, LOW);
    digitalWrite(leftTwo, AdjustableSpeed);
    digitalWrite(rightOne, LOW);
    digitalWrite(rightTwo, AdjustableSpeed);
}
void Stop()
{
    digitalWrite(leftOne, HIGH);
    digitalWrite(leftTwo, HIGH);
    digitalWrite(rightOne, HIGH);
    digitalWrite(rightTwo, HIGH);
}
