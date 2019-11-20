/**
 * turtleprogram.h
 * Assignment 1: CSS 343
 * 
 * @author Sambhavi Pandey
 * @date 6 Oct 2019
 * 
 * This file is an interface (.h file) that contains 
 * declarations of the function and variables that exist 
 * in the turtleprogram.cpp file.
 */

//Header guards to prevent duplicate definitions
#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include <iostream>
#include <string>

using namespace std;

class TurtleProgram {
	friend ostream &operator<<(ostream &Out, const TurtleProgram &Tp);

public:
	//Constructors
	TurtleProgram();
	explicit TurtleProgram(const string &Command);
	TurtleProgram(const string &Command, const string &Times);
	TurtleProgram(const TurtleProgram &Tp);

	//Destructor 
	virtual ~TurtleProgram();

	//Getter functions
	int getLength() const;
	string getIndex(const int &I) const;

	//Setter function
	void setIndex(const int &I, const string &Str);

	//Overloading operators 
	bool operator==(const TurtleProgram &Rhs) const;
	bool operator!=(const TurtleProgram &Rhs) const;

	TurtleProgram &operator=(const TurtleProgram &Rhs);
	TurtleProgram operator+(const TurtleProgram &Tp) const;
	TurtleProgram &operator+=(const TurtleProgram &Tp);
	TurtleProgram operator*(const int &Times) const;
	TurtleProgram &operator*=(const int &Times);

private:
	//Declaring private variables 
	string *array = nullptr;
	int length = 0;
};
#endif 