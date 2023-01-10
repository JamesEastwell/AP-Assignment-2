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

using namespace std;

int main()
{
	string userCommand;
	vector <shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands

	while ("exit" != userCommand)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s
		char d[] = " ";
		char* portion = strtok(cstr, d);
		while (portion != NULL)
		{
			parameters.push_back(portion);
			portion = strtok(NULL, d);
		}

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		if (parameters.size() == 0)
		{
			parameters.push_back(" ");
		}
		string command = parameters[0];

		if ("addR" == command) {
			if (parameters.size() >= 5) {
				int x, y, h, w;
				try {
					//
					x = parameters[1].c_str() != NULL ? stoi(parameters[1].c_str()) : 1;
					y = parameters[2].c_str() != NULL ? stoi(parameters[2].c_str()) : 1;
					h = parameters[3].c_str() != NULL ? stoi(parameters[3].c_str()) : 1;
					w = parameters[4].c_str() != NULL ? stoi(parameters[4].c_str()) : 1;
				}
				catch (...) {
					std::cout << "Not given proper input. Setting default values." << endl;
					x = 1;
					y = 1;
					h = 1;
					w = 1;
				}
				rectangle* r = new rectangle(x, y, h, w);
				shapes.push_back(r);
				std::cout << r->toString();
			}
		}

		else if ("addS" == command) {
			int x = stoi(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
			int y = stoi(parameters[2].c_str());
			int e = stoi(parameters[3].c_str());

			square* s = new square(x, y, e);
			shapes.push_back(s);
			cout << s->toString();
		}

		if ("addC" == command) {
			int x = stoi(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
			int y = stoi(parameters[2].c_str());
			int r = stoi(parameters[3].c_str());

			circle* c = new circle(x, y, r);
			shapes.push_back(c);
			cout << c->toString();

		}

		else if ("scale" == command) {
			// scale object at index... the scaling needs to be isotropic in case of circle and square 
			// you may want to check if the index exists or not!

			// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
			// As a result all your derived classes have scale functions... 
			// You may need to use type casting wisely to use polymorphic functionality!
			int shapeNo; // read from parameters
			shapeNo = stof(parameters[1]);
			float x = stof(parameters[2]);
			float y = stof(parameters[3]);
			// you may want to check if the index exists or not!
			if (shapeNo <= shapes.size())
			{
				movable* m = dynamic_cast<movable*>(shapes[shapeNo - 1]);

				m->scale(x, y);
				cout << shapes[shapeNo - 1]->toString();
			}
			else {
				cout << "Index does not exist." << endl;
			}
		}
		else if ("move" == command) {
			// move object at index
			int shapeNo; // read from parameters
			shapeNo = stoi(parameters[1]);
			int x = stoi(parameters[2]);
			int y = stoi(parameters[3]);
			// you may want to check if the index exists or not!
			if (shapeNo <= shapes.size())
			{
				// Study the following code. A Shape object is not Movable, but all derived classes are...
				// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
				movable* m = dynamic_cast<movable*>(shapes[shapeNo - 1]);

				m->move(x, y);
				// scale should work similarly...

				// note that here you should see the corresponding toString output for the derived classes...
				// if toString is not a virtual function, you may see the base class functionality :(
				cout << shapes[shapeNo - 1]->toString();
			}
			else {
				cout << "Index does not exist." << endl;
			}
		}
		else if ("display" == command)
		{
			// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
			for (int i = 0; i < shapes.size(); i++)
			{
				cout << "Shape number " << i + 1 <<" is:" << endl;
				cout << shapes[i]->toString() << endl;
			}
		}
		
		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing...
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