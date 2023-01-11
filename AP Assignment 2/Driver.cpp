#pragma warning (disable : 4996)
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	// Initialsing values to store the input from the user
	string userCommand;
	// A vector to store the shapes
	vector <shape*> shapes; 
	// Vector of strings to hold all parameters from the user
	vector <string> parameters; 
	cout << "Commands| Parameters"
		"\n-------------------------------------------"
		"\naddR \t|\tx \ty \th \tw"
		"\n-------------------------------------------"
		"\naddC \t|\tx \ty \tr"
		"\n-------------------------------------------"
		"\naddS \t|\tx \ty \te"
		"\n-------------------------------------------"
		"\nmove \t|\tshapeNo \tx \ty"
		"\n-------------------------------------------"
		"\nscale \t|\tshapeNo \tx \ty"
		"\n-------------------------------------------"
		"\ndisplay\t|"
		"\n-------------------------------------------"
		"\nclear\t|\tyes \tno"
		"\n-------------------------------------------"
		"\nexit \t|" << endl;
	while ("exit" != userCommand)
	{
		cout<<"Enter the command: ";		

		// Taking user input
		getline(cin, userCommand);

		// Store input as char array
		char* cstr = new char[userCommand.length() + 1];

		// 
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());
		// Setting the delimiter as a blank space
		// This is done so the portions will be determined by the spaces inbetween each input
		char d[] = " ";
		// The method that will split the str into tokens (sequence of characters separated by the delimiter (blank spaces)
		char* portion = strtok(cstr, d);
		// A while loop to go through the entire input until the portion that is returned is null
		while (portion != NULL)
		{
			// Adding the portion onto the parameters vector where all the commands are stored
			parameters.push_back(portion);
			portion = strtok(NULL, d);
		}
		
		// Making the loop code null safe.
		// If the size of parameters is null, then it will make the initial value of parameters = " "
		// this will then mean that there will always be a value of parameters[0]
		// meaning there will not be a vector subscript error
		if (parameters.size() == 0)
		{
			parameters.push_back(" ");
			cout << "Please enter a valid command" << endl;
		}
		// Making the command equal to parameters[0] 
		// etc. "addR", "move" or "exit"
		string command = parameters[0];

		if ("addR" == command) { // if statement to construct rectangle
			// if statement to make sure the user hasnt inputted too few parameters
			// if they have then they will not be allowed to progress and will be kicked back to making another command
			if (parameters.size() >= 5) {
				// Initialising the variables that will be used to construct the rectangle
				int x, y, h, w;
				// Error handling to make sure that the user has inputted integers for their parameters
				// if not, then it will be caught and they will be given default values and the shape will still be constructed
				try {
					// If all parameters that are inputted are integers then the variables will convert and store
					x = parameters[1].c_str() != NULL ? stoi(parameters[1].c_str()) : 1;
					y = parameters[2].c_str() != NULL ? stoi(parameters[2].c_str()) : 1;
					h = parameters[3].c_str() != NULL ? stoi(parameters[3].c_str()) : 1;
					w = parameters[4].c_str() != NULL ? stoi(parameters[4].c_str()) : 1;
				}
				catch (...) {
					// Error caught and default values given
					std::cout << "Not given proper input. Setting default values." << endl;
					x = 1;
					y = 1;
					h = 1;
					w = 1;
				}
				// The rectangle is created and the pointer is stored in r
				rectangle* r = new rectangle(x, y, h, w);
				// r is then added to the shapes vector
				shapes.push_back(r);
				// overloaded << to allow an output the rectangle r
				cout << *r;
			}
		}
		// This else if statement is the same as the last
		// Only difference is that it will create a square instead of rectangle
		else if ("addS" == command) { // if statement to construct a square
			if (parameters.size() >= 4) { // This takes four parameters instead of the 5 that addR did as there is only edge not height and width
				int x, y, e;
				try {
					x = parameters[1].c_str() != NULL ? stoi(parameters[1].c_str()) : 1;
					y = parameters[2].c_str() != NULL ? stoi(parameters[2].c_str()) : 1;
					e = parameters[3].c_str() != NULL ? stoi(parameters[3].c_str()) : 1;
				}
				catch (...) {
					cout << "Not given proper input. Setting default values." << endl;
					x = 1;
					y = 1;
					e = 1;
				}
				// Creating the square
				square* s = new square(x, y, e);
				// Storing in shapes
				shapes.push_back(s);
				// Overloaded << operator to output the details
				cout << *s;
			}
		}
		// if statement to create circle. This one is almost the same as the square just with radius insted of edge
		if ("addC" == command) {
			if (parameters.size() >= 4) {
				int x, y, r;
				try {
					// Assigning x,y, and r
					x = parameters[1].c_str() != NULL ? stoi(parameters[1].c_str()) : 1;
					y = parameters[2].c_str() != NULL ? stoi(parameters[2].c_str()) : 1;
					r = parameters[3].c_str() != NULL ? stoi(parameters[3].c_str()) : 1;
				}
				catch (...) {
					std::cout << "Not given proper input. Setting default values." << endl;
					x = 1;
					y = 1;
					r = 1;
				}
				// Creating circle
				circle* c = new circle(x, y, r);
				// Storing circle in shapes
				shapes.push_back(c);
				cout << *c;
			}
		}

		// if statement for scale command
		else if ("scale" == command) {
			if (parameters.size() >= 4) { // Takes 4 parameters as there is command, shapeNo, x, and y
				// shapeNo is used to hold the shape index that would like to be edited
				int shapeNo;
				// x and y are stored as floats as the scale 
				float x, y;
				try {
					//
					shapeNo = parameters[1].c_str() != NULL ? stoi(parameters[1].c_str()) : 1;
					x = parameters[2].c_str() != NULL ? stof(parameters[2].c_str()) : 1.0; // Using stof as x and y are floats rather than integers like shapeNo
					y = parameters[3].c_str() != NULL ? stof(parameters[3].c_str()) : 1.0;
				}
				catch (...) {
					std::cout << "Not given proper input. Setting default scaling values of 1 and 1. No changes will be made." << endl;
					shapeNo = 1;
					x = 1;
					y = 1;
				}
				// An if statement to check to see if the shapeNo that has been inputted is actually within the bounds of shapes
				if (shapeNo <= shapes.size())
				{
					// Dynamically casting the shape at shapeNo as a movable object so that it can be moved and scaled
					movable* m = dynamic_cast<movable*>(shapes[shapeNo - 1]);

					// Calling the scale function
					m->scale(x, y);
					// Now casting m back through each shape to find what shape it is so that the overloaded << operator can be used
					circle* c = dynamic_cast<circle*>(m);
					// When an object cannot be casted using dynamic casting, it will return a nulltptr, so the code will go through each shape until it finds out that will not return a nullptr
					if (c == nullptr)
					{
						// If a circle returns a nullptr then it will try a rectangle
						rectangle* r = dynamic_cast<rectangle*>(m);
						if (r == nullptr) {
							// If a rectangle returns a nullptr then it will not that the shape has to be a square
							square* s = dynamic_cast<square*>(m);
							cout << *s;
						}
						
						else { cout << *r; } // Since it does not return null, the shape will be a rectangle therefore it can be outputted
					}
					else { cout << *c; } // Since it does not return null, the shape will be a circle therefore it can be outputted here
				}
				else {
					// Else statement and a little output to let the user know that they have given the wrong index
					cout << "Index does not exist. Please enter a correct shape index." << endl;
				}
			}
			else
			{
				// Since the parameters are not less than 4, this means that there are not enough and will therefore ask the user for new command again
				cout << "Not given proper input. Please make sure you fill all parameters." << endl;
			}
		}
		// Pretty much the same as the scale command
		else if ("move" == command) {
			if (parameters.size() >= 4) {
				int shapeNo, x, y;
				try {
					shapeNo = parameters[1].c_str() != NULL ? stoi(parameters[1].c_str()) : 1;
					x = parameters[2].c_str() != NULL ? stoi(parameters[2].c_str()) : 1;
					y = parameters[3].c_str() != NULL ? stoi(parameters[3].c_str()) : 1;
				}
				catch (...) {
					std::cout << "Not given proper input. Setting default scaling values of 1 and 1. No changes will be made." << endl;
					shapeNo = 1;
					x = 1;
					y = 1;
				}
				if (shapeNo <= shapes.size())
				{
					movable* m = dynamic_cast<movable*>(shapes[shapeNo - 1]);

					// Only difference is that this will call the move function instead rather than calling scale like the previous if statement.
					// Otherwise, everything is the same
					m->move(x, y);
					circle* c = dynamic_cast<circle*>(m);
					if (c == nullptr)
					{
						rectangle* r = dynamic_cast<rectangle*>(m);
						if (r == nullptr) {
							square* s = dynamic_cast<square*>(m);
							cout << *s; // Square output
						}
						else { cout << *r; } // Rectangle output
					}
					else { cout << *c; } // Circle output
				}
				else {
					cout << "Index does not exist. Please enter a correct shape index." << endl;
				}
			}
			else
			{
				cout << "Not given proper input. Please make sure you fill all parameters." << endl;
			}
		}
		// Display function that will not require any sort of parameters.
		// Simply outputs the information of each shape using its own overloaded method
		else if ("display" == command)
		{
			// If statement to make sure that the user isnt causing an error by trying to display when they have not added any shapes
			if (shapes.size() != 0)
			{
				// for loop to iterate through all the shapes within the vector size.
				// for each shape, it will go through the if statements to find which sort of shape it is 
				// will then use the overloaded operator for that object to output the object info
				for (int i = 0; i < shapes.size(); i++)
				{
					circle* c = dynamic_cast<circle*>(shapes[i]);
					cout << "\nShape number " << i + 1 << " is:" << endl;
					if (c == nullptr)
					{
						rectangle* r = dynamic_cast<rectangle*>(shapes[i]);
						if (r == nullptr) {
							square* s = dynamic_cast<square*>(shapes[i]);
							cout << *s; // Output for square shape
						}
						else { cout << *r; } // Output for rectangle shape
					}
					else { cout << *c; } // Output for circle shape
				}
			}
			else
			{
				// Output for if there are no shapes in the list
				cout << "No shapes have been created, therefore there is nothing to display" << endl;
				cout << "Please add a shape first, then display. Now returning back to command entry: " << endl;
			}
			
		}
		// Clear function that will iterate through all elements in shape and delete them one by one since they are all created on the heap
		// Therefore the space needs to be cleared up
		else if ("clear" == command) 
		{
			// Adding a check to make sure the user doesn't accidentally clear all shapes
			string check;
			cout << "Are you sure that you'd like to clear all shapes from memory?" << endl;
			getline(cin, check);
			if (check == "yes") {
				// for loop to iterate through the shapes list
				for (int i = shapes.size() - 1; i >= 0; i--)
				{
					delete[] shapes[i];
				}
				// Resizing the vector otherwise it will maintain the same size as what it was previously
				// Without this, there would be a lot of blank space in the vector
				shapes.resize(0);
			}
			else if (check == "no")
			{
				// Output for if they didn't mean to clear all shapes
				cout << "Not clearing all shapes from memory. Now returing back to command entry:" << endl;
			}
			else {
				// If they enter anything else then it will simply take them back to the command entry
				cout << "Wrong entry. Now returning back to command entry: " << endl;
			}
		}
		
		// Post processing that will clear cstr as it is allocated on the heap
		// also clearing all the parameters so that they do not overlap in anyway or cause any errors.
		cout << endl << endl;
		parameters.clear();
		delete[] cstr;
	}
	cout << "Press any key to continue...";
	std::getchar();
	// for loop to delete all shapes
	for (int i = shapes.size() - 1; i >= 0; i--)
	{
		delete[] shapes[i];
	}
	return 0;
}