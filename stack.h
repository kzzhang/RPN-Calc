//basic stack data structure implemented for apstrings

//guard statement
#ifndef STACK_H
#define STACK_H
#include "apstring.h"

//prototype class and class methods
class stack{
	protected:
		apstring list[20];
		int top;
	public:
		stack();
		void push(apstring);
		apstring pop();
		apstring getIndex(int);
		void setIndex(int, apstring);
		void setTop(int);
		int getTop();
		~stack();
};
#endif
