#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
/*Dit bestand geeft een template weer van welke variabelen de ccp file zal bevatten */
class Motor
{
	public:
		// De constructor
		Motor(int leftOne, int leftTwo, int rightOne, int rightTwo);
		//de functie forward, turnleft, turnright, achterruit en stop.
		void Forward();
		void TurnLeft();
		void TurnRight();
		void BackWards();
		void Stop();
	private:
		// de private variabelen _leftOne _leftTwo,  _rightOne,  _rightTwo;
		int _leftOne;
		int _leftTwo;
		int _rightOne;
		int _rightTwo;

};
#endif