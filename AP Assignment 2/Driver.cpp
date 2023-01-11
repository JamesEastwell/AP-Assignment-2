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
	vector <shape*> shapes;     
	vector <string> parameters; 

	while ("exit" != userCommand)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		char d[] = " ";
		char* portion = strtok(cstr, d);
		while (portion != NULL)
		{
			parameters.push_back(portion);
			portion = strtok(NULL, d);
		}

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