/*Dit programma moet de motor vooruit laten rijden*/
/*Hierbij zal gebruik gemaakt worden van functies
en het serialread commando om de input van de computer uit te kunnen lezen.*/
const int leftOne = 3;
const int leftTwo = 9;
const int rightOne = 10;
const int rightTwo = 11;

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
