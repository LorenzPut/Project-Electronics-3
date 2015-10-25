/*Dit programma moet de motor vooruit & achteruit laten rijden*/
const int leftOne = 2;
const int leftTwo = 3;
/*const int rightOne = 4;
const int rightTwo = 5;*/

void setup()
{
  Serial.begin(9600);
  pinMode(leftOne, OUTPUT);
  pinMode(leftTwo, OUTPUT);
  /*pinMode(rightOne, OUTPUT);
  pinMode(rightTwo, OUTPUT);*/
}

void loop()
{
  digitalWrite(leftOne, LOW);
  digitalWrite(leftTwo, HIGH);
  //digitalWrite(rightOne, LOW);
  //digitalWrite(rightTwo, HIGH);
}
