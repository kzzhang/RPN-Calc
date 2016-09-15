//declare includes
#include "calculator.h"
#include "apstring.h"
#include "apstring.cpp"

using namespace std;

//initialization
calculator::calculator(){
	top = -1;
	current = "";
}

//returns current number
apstring calculator::getCurrent(){
	return current;
}

//sets current number
void calculator::setCurrent(apstring c){
	current = c;
}
