//declare includes
#include <iostream>
#include "button.h"
#include "apstring.h"
#include "calculator.h"
#include <stdlib.h>
#include <sstream>
#include <cmath>

#define PI 3.14159265

using namespace std;

//default initialization
button::button(){
	name = "none";
	type = "none";
}

//initialization with inputs
button::button(int a, int b, int c, int d, calculator* e, apstring f = "none", apstring g = "none"){
	output = e;
	name = f;
	type = g;
	xlower = a;
	xupper = b;
	ylower = c;
	yupper = d;
}

//function on button click
void button::press(){
	//declare string stream
	ostringstream ss;
	//if button is of type number
	if (type == "number"){
		//if current is blank
		if (output->getCurrent() == ""){ 
			if (output->getTop() > 0) output->pop(); //if top element of stack is empty, delete it
			//format and push 0 if decimal is pressed
			if (name == ".") {
				output->setCurrent("0" + name);
				output->push("0");
			}
			//push number pressed
			else {
				output->setCurrent(name);
				output->push(output->getCurrent().c_str());
			}
		}
		else {
			//if decimal pressed
			if (name == "."){
				//return error if there is already a decimal point
				if (output->getCurrent().find(".") != -1){
					cout << "Decimal already exists!" << endl;
				}
				//add decimal point to current otherwise
				else{
					output->setCurrent(output->getCurrent() + name);
				}
			}
			//if 0 pressed
			else if (output->getCurrent() == "0"){
				//no additional output if current is already 0
				output->setCurrent(name);
				output->pop();
				output->push(output->getCurrent().c_str());
			}
			else{
				//add number pressed to end of current number and push;
				output->setCurrent(output->getCurrent() + name);
				output->pop();
				output->push(output->getCurrent().c_str());
			}
		}
	}
	//if enter key
	else if (type == "enter"){
		//reset current working number, previous number has already been pushed
		if (output->getCurrent() != ""){
			output->setCurrent("");
			output->push("");
		}
	}
	
	//if button is a one off function 
	else if (type == "onex" && output->getCurrent() != ""){
		//pop top from stack
		output->setCurrent(output->pop());
		//changes sign of current
		if (name == "plusmin") {
			ss << (0 - atof(output->getCurrent().c_str()));
			string s(ss.str());
			output->setCurrent(s.c_str());
		}
		//square root function
		else if (name == "sqrt"){
			ss << pow(atof(output->getCurrent().c_str()), 0.5);
			string s(ss.str());
			output->setCurrent(s.c_str());
		}
		//sin function
		else if (name == "sin"){
			ss << sin(atof(output->getCurrent().c_str())*PI/180);
			string s(ss.str());
			output->setCurrent(s.c_str());
		}
		//cos function
		else if (name == "cos"){
			ss << cos(atof(output->getCurrent().c_str())*PI/180);
			string s(ss.str());
			output->setCurrent(s.c_str());
		}
		//tan function
		else if (name == "tan"){
			ss << tan(atof(output->getCurrent().c_str())*PI/180);
			string s(ss.str());
			output->setCurrent(s.c_str());
		}
		//backspace
		else if (name == "back"){
			output->setCurrent(output->getCurrent().substr(0, output->getCurrent().length()-1));
		}
		
		//push result back onto stack, formats if decimal at end
		if (output->getCurrent().find(".") == output->getCurrent().length()-1) 
			output->push(output->getCurrent().substr(0, output->getCurrent().length()-1));
		else output->push(output->getCurrent());
	}
	
	//pi button
	else if (type == "pi"){
		if (output->getCurrent() == "" && output->getTop() > 0) output->pop(); //if empty element at top of stack, delete it
		//push pi to stack
		ss << PI;
		string s(ss.str());
		output->setCurrent(s.c_str());
		output->push(output->getCurrent());
	}
	
	//exponent
	else if (type == "exp"){
		if (output->getCurrent() == "" && output->getTop() > 0) output->pop(); //if empty element at top of stack, delete it
		if (output->getTop() >= 1){ //if more than 2 elements in stack
			//pop elements, find exponent, and push back to stack
			float temp = atof(output->pop().c_str());
			ss << pow(atof(output->pop().c_str()), temp);
			string s(ss.str());
			output->push(s.c_str());
		}
		//reset current
		output->setCurrent("");
		output->push("");
	}
	
	//clears everything in the stack
	else if (type == "ac"){
		for (int i = 0; i<20; i++) output->setIndex(i, "");
		output->setCurrent("");
		output->setTop(-1);
	}
	
	//basic four functions
	else if (type == "func"){
		if (output->getCurrent() == "" && output->getTop() > 0) output->pop(); //if empty element at top of stack, delete it
		if (output->getTop() >= 1){ //if more than 2 elements in stack
			float temp = atof(output->pop().c_str()); //store top element
			//pops 2nd element, performs addition, and pushes to stack
			if (name == "add"){
				ss << atof(output->pop().c_str()) + temp;
				string s(ss.str());
				output->push(s.c_str());
			}
			//pops 2nd element, performs subtraction, and pushes to stack
			if (name == "minus"){
				ss << atof(output->pop().c_str()) - temp;
				string s(ss.str());
				output->push(s.c_str());
			}
			//pops 2nd element, performs multiplication, and pushes to stack
			if (name == "multiply"){
				ss << atof(output->pop().c_str()) * temp;
				string s(ss.str());
				output->push(s.c_str());
			}
			//pops 2nd element, performs division, and pushes to stack
			if (name == "divide"){
				ss << atof(output->pop().c_str()) / temp;
				string s(ss.str());
				output->push(s.c_str());
			}
		}
		//resets current
		output->setCurrent("");
		output->push("");
	}
}

//retrieve boundaries on button
int button::getxlow(){
	return xlower;
}
int button::getylow(){
	return ylower;
}
int button::getxhigh(){
	return xupper;
}
int button::getyhigh(){
	return yupper;
}

//empty deconstructor
button::~button(){
}

