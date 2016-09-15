//Calculator class inherited from stack class

//guard statement and includes
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"
#include "apstring.h"

//prototype class and class methods
class calculator: public stack{
	protected:
		apstring current;
	public:
		calculator();
		apstring getCurrent();
		void setCurrent(apstring);
};
#endif
