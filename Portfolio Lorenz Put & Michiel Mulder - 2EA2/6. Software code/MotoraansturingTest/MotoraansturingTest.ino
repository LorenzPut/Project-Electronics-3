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
  pinMode(rightOne, OUTPUT);
  pinMode(rightTwo, OUTPUT);
}

//Dit programma zet 4 pinnen op hoog of op laag. 
//Dit werd gebruikt om de H-bruggen te testen.
void loop()
{
  digitalWrite(leftOne, LOW);
  digitalWrite(leftTwo, HIGH);
  digitalWrite(rightOne, LOW);
  digitalWrite(rightTwo, HIGH);
}
