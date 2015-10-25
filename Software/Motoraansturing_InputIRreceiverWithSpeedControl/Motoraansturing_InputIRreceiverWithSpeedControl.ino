/*Dit programma moet de motor vooruit, achteruit, links en rechts laten rijden*/
/*Hierbij zal gebruik gemaakt worden van functies en de input van de receiver.*/

#include <IRremote.h>

const int leftOne = 3;
const int leftTwo = 9;
const int rightOne = 10;
const int rightTwo = 11;

const int speed1 = 200;
const int speed2 = 220;
const int speed3 = 250;

//int speedvalue = 255;

int IRpin = 5;
IRrecv irrecv(IRpin);
decode_results results; 

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
    /*if(results.value == 16738455)
    {
      speedvalue = speed1;
    }
    if(results.value == 16750695)
    {
      speedvalue = speed2;
    }
    if(results.value == 16756815)
    {
      speedvalue = speed3;
    }*/
    Serial.println(results.value, DEC);
    if(results.value == 16736925)
    {
      Forward();
    }
    if(results.value == 16712445)
    {
      Stop();
    }  
    if(results.value == 16761405)
    {
      TurnRight();
    }
    if(results.value == 16720605)
    {
      TurnLeft();
    }
    if(results.value == 16754775)
    {
      Backward();
    }

    irrecv.resume();
  }
  //delay(333);
}
void Forward()
{
  analogWrite(leftOne, 220);
  analogWrite(leftTwo, 0);
  analogWrite(rightOne, 0);
  analogWrite(rightTwo, 220);
}
void Backward()
{
  analogWrite(leftOne, 0);
  analogWrite(leftTwo, 220);
  analogWrite(rightOne, 220);
  analogWrite(rightTwo, 0);
}
void TurnLeft()
{
  analogWrite(leftTwo, 0);
  analogWrite(leftOne, 220);
  analogWrite(rightOne, 220);
  analogWrite(rightTwo, 0);
}
void TurnRight()
{
  analogWrite(leftOne, 0);
  analogWrite(leftTwo, 220);
  analogWrite(rightOne, 0);
  analogWrite(rightTwo, 220);
}
void Stop()
{
  analogWrite(leftOne, 255);
  analogWrite(leftTwo, 255);
  analogWrite(rightOne, 255);
  analogWrite(rightTwo, 255);
}

