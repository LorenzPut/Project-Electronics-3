/*Dit programma is een uitbreiding op motoraansturing_IputPcFull*/
/*Dit programma moet de motor vooruit laten rijden*/
/*Hierbij zal gebruik gemaakt worden van functies
en het serialread commando om de input van de computer uit te kunnen lezen.*/

const int leftOne = 3;
const int leftTwo = 9;
const int rightOne = 10;
const int rightTwo = 11;

// De motor zal om te beginnen niets doen omdat de stop functie geactiveerd is.
char Inputkey = 's';

void setup()
{
  Serial.begin(9600);
  pinMode(leftOne, OUTPUT);
  pinMode(leftTwo, OUTPUT);
  pinMode(rightOne, OUTPUT);
  pinMode(rightTwo, OUTPUT);
  
}

void loop()
{
  //A.d.h.v. de letter die hier ingelezen wordt uit 
  //de seriële monitor zal het programma een bepaalde functie uitvoeren.
  Inputkey = Serial.read();
  
  if(Inputkey == 'f')
  {
    Forward();
  }
  if(Inputkey == 's')
  {
    Stop();
  }  
  if(Inputkey == 'l')
  {
    TurnLeft();
  }
  if(Inputkey == 'r')
  {
    TurnRight();
  }
  if(Inputkey == 'b')
  {
    Backward();
  }
  
  
}
//Dit zijn de verschillende methoden die in de loop aangeroepen worden
void Forward()
{
    digitalWrite(leftOne, HIGH);
    digitalWrite(leftTwo, LOW);
    digitalWrite(rightOne, LOW);
    digitalWrite(rightTwo, HIGH);
}
void Backward()
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
