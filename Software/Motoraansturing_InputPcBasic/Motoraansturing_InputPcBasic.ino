/*De auto beweegt als reactie op een letter die wordt ingegeven op de serial read terminal*/
char incomingletter;
const int leftOne = 2;
const int leftTwo = 3;
const int rightOne = 4;
const int rightTwo = 5;

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
  incomingletter = Serial.read();
  Serial.println(incomingletter);
  delay(1000);
  
 if(incomingletter == 'v')
  {
    digitalWrite(leftOne, HIGH);
    digitalWrite(leftTwo, LOW);
    digitalWrite(rightOne, HIGH);
    digitalWrite(rightTwo, LOW);
  }
   else if(incomingletter == 'a')
  {
    digitalWrite(leftOne, LOW);
    digitalWrite(leftTwo, HIGH);
    digitalWrite(rightOne, LOW);
    digitalWrite(rightTwo, HIGH);
  }
  
}
