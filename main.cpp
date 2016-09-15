/***************************************
*			RPN Calculator             *
*    Graphic RPN calculator utility    *
*  For Mr. Creelman's ICS4U Course     *
*          By Kevin Zhang              *
*          April 8, 2016               *
***************************************/

//declare header files
#include <allegro.h>
#include <iostream>
#include "stack.h"
#include <stdlib.h>
#include "calculator.h"
#include "button.h"
#include <apvector.h>

using namespace std;

//prototype function
int mouseDown();

int main(int argc, char *argv[]){
	
	//initialize allegro
	allegro_init(); 
    install_keyboard();
    install_mouse();
    set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    set_window_title("RPN Calculator");
    
    //load calculator screen
    BITMAP *background = load_bitmap("screen.bmp", NULL);
    
    //declare calculator and vector of associated buttons
    calculator RPN;
    apvector<button> buttons;
    
    //create calculator buttons
    button one(279, 360, 154, 211, &RPN, "1", "number");
    button two(369, 451, 154, 211, &RPN, "2", "number");
    button three(457, 539, 154, 211, &RPN, "3", "number");
    button four(279, 360, 218, 276, &RPN, "4", "number");
    button five(369, 451, 218, 276, &RPN, "5", "number");
    button six(457, 539, 218, 276, &RPN, "6", "number");
    button seven(279, 360, 285, 342, &RPN, "7", "number");
    button eight(369, 451, 285, 342, &RPN, "8", "number");
    button nine(457, 539, 285, 342, &RPN, "9", "number");
    button zero(369, 451, 350, 408, &RPN, "0", "number");
    button dot(279, 360, 350, 408, &RPN, ".", "number");
    button enter(282, 628, 413, 470, &RPN, "enter", "enter");
    button plusmin(457, 539, 350, 408, &RPN, "plusmin", "onex");
    button sqrt(369, 451, 10, 69, &RPN, "sqrt", "onex");
    button sin(279, 360, 75, 133, &RPN, "sin", "onex");
    button cos(369, 451, 75, 133, &RPN, "cos", "onex");
    button tan(457, 539, 75, 133, &RPN, "tan", "onex");
    button back(547, 629, 75, 133, &RPN, "back", "onex");
    button pi(457, 539, 10, 69, &RPN, "pi", "pi");
    button exp(279, 360, 10, 69, &RPN, "exp", "exp");
    button ac(547, 629, 10, 69, &RPN, "ac", "ac");
    button add(544, 626, 285, 342, &RPN, "add", "func");
    button minus(544, 626, 350, 408, &RPN, "minus", "func");
    button multiply(544, 626, 218, 276, &RPN, "multiply", "func");
    button divide(544, 626, 154, 211, &RPN, "divide", "func");
    
    //populate vector with buttons
    buttons.push_back(one);
    buttons.push_back(two);
    buttons.push_back(three);
    buttons.push_back(four);
    buttons.push_back(five);
    buttons.push_back(six);
    buttons.push_back(seven);
    buttons.push_back(eight);
    buttons.push_back(nine);
    buttons.push_back(zero);
    buttons.push_back(dot);
    buttons.push_back(enter);
    buttons.push_back(plusmin);
    buttons.push_back(sqrt);
    buttons.push_back(sin);
    buttons.push_back(cos);
    buttons.push_back(tan);
    buttons.push_back(back);
    buttons.push_back(pi);
    buttons.push_back(exp);
    buttons.push_back(ac);
    buttons.push_back(add);
    buttons.push_back(minus);
    buttons.push_back(multiply);
    buttons.push_back(divide);
    
    int mouse = 1; //represents status of mouse
    
    while(!key[KEY_ESC]) {
    	show_mouse(background); //displays mouse
    	
    	//if mouse is clicked over a button, run the function associated with the button
    	if (mouseDown() && mouse == 1){
    		for (int i = 0; i < buttons.size(); i++){
    			//check if, and which, button has been clicked
    			if (mouse_x >= buttons[i].getxlow() && mouse_x <= buttons[i].getxhigh()) {
    				if (mouse_y >= buttons[i].getylow() && mouse_y <= buttons[i].getyhigh()){
    					buttons[i].press();
    					break;
    				}
    			}
    		}
    		mouse = 0; //mouse has been clicked
    	}
    	//after a mouseclick
    	if (!mouseDown() && mouse == 0) {
			mouse = 1; //reset mouse status
			//load blank calculator screen and print out any data in the calculator
			background = load_bitmap("screen.bmp", NULL);
    		textprintf_ex(background, font, 13, 446, makecol(255, 255, 255), -1, RPN.getCurrent().c_str());
    		for (int i = 0; i < RPN.getTop(); i++){
    			textprintf_ex(background, font, 13, (425 - (RPN.getTop()-i)*20), makecol(255, 255, 255), -1, RPN.getIndex(i).c_str());
    		}
    	}
     	blit(background, screen, 0,0,0,0,640,480); //blit updated bitmap to screen  
	}   
	//clean up allegro
	show_mouse(NULL);
    destroy_bitmap(background);
	return 0;
}

END_OF_MAIN();

//checks if any mouse button is clicked
int mouseDown(){
	if (mouse_b & 0 || mouse_b & 1 || mouse_b & 2) return 1;
	else return 0;
}

