//declare includes
#include <iostream>
#include "stack.h"

using namespace std;

//initialise stack
stack::stack(){
	top = -1;
	for (int i = 0; i<20; i++) list[i] = "";
}

//push apstring to stack; checks for stack overflow
void stack::push(apstring m){
	if (top < 19){
		top++;
		list[top] = m;
	}
	else{
		cerr << "Stack overflow.";
	}
}

//pop apstring from stack; checks for empty stack
apstring stack::pop(){
	apstring temp = "";
	if (top >= 0) {
		temp = list[top];
		top--;
	}
	else {
		cerr << "Stack is empty.";
	}
	return temp;
}

//get the value of a certain stack element
apstring stack::getIndex(int temp){
	return list[temp];
}

//change the value of a certain member of the stack
void stack::setIndex(int temp, apstring m){
	list[temp] = m;
}

//change how large the stack is
void stack::setTop(int m){
	top = m;
}

//returns how large the stack is
int stack::getTop(){
	return top;
}

//empty deconstructor
stack::~stack(){
}
