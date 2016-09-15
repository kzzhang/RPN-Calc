//button class for buttons on the RPN calculator

//guard statement, declare includes
#ifndef BUTTON_H
#define BUTTON_H
#include "apstring.h"
#include "calculator.h"
#include <sstream>

//prototype class and class methods
class button{
	private:
		apstring name;
		apstring type;
		calculator *output;
		int xlower;
		int xupper;
		int ylower;
		int yupper;
	public:
		button();
		button(int, int, int, int, calculator*, apstring, apstring);
		void press();
		int getxlow();
		int getxhigh();
		int getylow();
		int getyhigh();
		~button();
};
#endif
