#include "Arduino.h"
#include "Motor.h"
/*De constructor van de motor.
Hier worden de pinnen gedifinieerd*/
Motor::Motor(int leftOne, int leftTwo, int rightOne, int rightTwo)
{
	pinMode(leftOne,OUTPUT);
	pinMode(leftTwo,OUTPUT);
	pinMode(rightOne,OUTPUT);
	pinMode(rightTwo,OUTPUT);
	/*de pinnummers worden door gegeven aan private variabelen*/
	_leftOne = leftOne;
	_leftTwo = leftTwo;
	_rightOne = rightOne;
	_rightTwo = rightTwo;
}
/*de pinnen worden zo aan gestuurd dat de auto voorruit rijdt.*/
void Motor::Forward()
{
	digitalWrite(_leftOne, HIGH);
	digitalWrite(_leftTwo, LOW);
	digitalWrite(_rightOne, LOW);
	digitalWrite(_rightTwo, HIGH);
}
/*de pinnen worden zo aan gestuurd dat de auto naar links rijdt.*/
void Motor::TurnLeft()
{
	digitalWrite(_leftOne, HIGH);
	digitalWrite(_leftTwo, LOW);
	digitalWrite(_rightOne, HIGH);
	digitalWrite(_rightTwo, LOW);
}
/*de pinnen worden zo aan gestuurd dat de auto naar rechts rijdt.*/
void Motor::TurnRight()
{
	digitalWrite(_leftOne, LOW);
	digitalWrite(_leftTwo, HIGH);
	digitalWrite(_rightOne, LOW);
	digitalWrite(_rightTwo, HIGH);
}
/*de pinnen worden zo aan gestuurd dat de auto achteruit rijdt.*/
void Motor::BackWards()
{
	digitalWrite(_leftOne, LOW);
	digitalWrite(_leftTwo, HIGH);
	digitalWrite(_rightOne, HIGH);
	digitalWrite(_rightTwo, LOW);
}
/*de pinnen worden zo aan gestuurd dat de auto stopt.*/
void Motor::Stop()
{
	digitalWrite(_leftOne, HIGH);
	digitalWrite(_leftTwo, HIGH);
	digitalWrite(_rightOne, HIGH);
	digitalWrite(_rightTwo, HIGH);
}