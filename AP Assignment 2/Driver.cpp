/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */
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
#include<iomanip>

using namespace std;

int main()
{
	// Initialsing values to store the input from the user
	string userCommand;
	// A vector to store the shapes
	// This is taken as a pointer to stop constant copying of the shapes
	vector <shape*> shapes; 
	// Vector of strings to hold all parameters from the user
	vector <string> parameters; 

	// While loop that will exit when the user types "exit" as a command
	while ("exit" != userCommand)
	{
		cout << "Enter the command: ";

		// Taking the input from the user and storing it in userCommand
		getline(cin, userCommand);

		// Taking a pointer of a character array to allow the portions to be made
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

		// Following if statements to check what the command is
		if ("addR" == command) {
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

		else if ("addS" == command) {
			if (parameters.size() >= 4) {
				int x, y, e;
				try {
					//
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
				square* s = new square(x, y, e);
				shapes.push_back(s);
				cout << *s;
			}
		}

		if ("addC" == command) {
			if (parameters.size() >= 4) {
				int x, y, r;
				try {
					//
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
				circle* c = new circle(x, y, r);
				shapes.push_back(c);
				cout << *c;
			}
		}

		else if ("scale" == command) {
			if (parameters.size() >= 4) {
				int shapeNo;
				float x, y;
				try {
					//
					shapeNo = parameters[1].c_str() != NULL ? stoi(parameters[1].c_str()) : 1;
					x = parameters[2].c_str() != NULL ? stof(parameters[2].c_str()) : 1.0;
					y = parameters[3].c_str() != NULL ? stof(parameters[3].c_str()) : 1.0;
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

					m->scale(x, y);
					circle* c = dynamic_cast<circle*>(m);
					if (c == nullptr)
					{
						cout << "not circle" << endl;
						rectangle* r = dynamic_cast<rectangle*>(m);
						if (r == nullptr) {
							cout << "not rectangle" << endl;
							square* s = dynamic_cast<square*>(m);
							cout << *s;
						}
						else { cout << *r; }
					}
					else { cout << *c; }
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
		else if ("move" == command) {
			if (parameters.size() >= 4) {
				int shapeNo, x, y;
				try {
					//
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

					m->move(x, y);
					circle* c = dynamic_cast<circle*>(m);
					if (c == nullptr)
					{
						rectangle* r = dynamic_cast<rectangle*>(m);
						if (r == nullptr) {
							square* s = dynamic_cast<square*>(m);
							cout << *s;
						}
						else { cout << *r; }
					}
					else { cout << *c; }
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
		else if ("display" == command)
		{
			for (int i = 0; i < shapes.size(); i++)
			{
				cout << "\nShape number " << i + 1 <<" is:" << endl;
				circle* c = dynamic_cast<circle*>(shapes[i]);
				if (c == nullptr)
				{
					rectangle* r = dynamic_cast<rectangle*>(shapes[i]);
					if (r == nullptr) {
						square* s = dynamic_cast<square*>(shapes[i]);
						cout << *s;
					}
					else {cout << *r;}
				}
				else { cout << *c; }
			}
		}
		
		cout << endl << endl;
		parameters.clear();
		delete[] cstr;
	}
	cout << "Press any key to continue...";
	std::getchar();
	// delete all shapes
	for (int i = shapes.size() - 1; i >= 0; i--)
	{
		delete[] shapes[i];
	}
	return 0;
}