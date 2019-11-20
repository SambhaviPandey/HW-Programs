/**
 * turtleprogram.cpp
 * Assignment 1: CSS 343
 *
 * @author Sambhavi Pandey
 * @date 6 Oct 2019
 *
 * The purpose of the code in this file is to
 * emulate a turtle program that follows directions
 * directing the on-screen turtle to draw graphics.
 *
 * This file includes various constructors (such as
 * the default constructor, a constructor that takes in
 * one parameter of type string, a constructor that takes
 * in two parameters of type string, and a constructor that
 * takes in one parameter of type TurtleProgram). This file also
 * includes a destructor and operator overloading. Additionally,
 * this file contains getter functions and a setter function.
 */

#include "turtleprogram.h"
#include <cassert>
 /*
  * This is an empty default constructor used for initializing
  * the string array. 
  * @param: This constructor does not take in any parameters
  * @return: Does not return anything
  */
TurtleProgram::TurtleProgram() = default;

/*
 * The purpose of this constructor is to initialize
 * the string array to int length 1. Additionally, 
 * int length is incremented in order to account for 
 * the length of the string array.
 * @param: One string parameter that takes in a reference
 * @return: Does not return anything 
 */
TurtleProgram::TurtleProgram(const string &Command) {
	array = new string[1];
	*array = Command;
	length++;
}

/*
 * The purpose of this constructor is to initialize the
 * string array to int length 2. Additionally,
 * int length is incremented in order to
 * account for the string array length.
 * @param: Two string parameters that take in a reference
*  @return: Does not return anything
 */
TurtleProgram::TurtleProgram(const string &Command, const string &Times) {
	array = new string[2];
	*array = Command;
	//Pointer moves up by one
	*(array + 1) = Times;
	length += 2;
}

/*
 * The purpose of this constructor is to be a copy constructor
 * that initializes the string array.
 * @param: A TurtleProgram object parameter that takes in a reference
 * @return: Does not return anything 
 */
TurtleProgram::TurtleProgram(const TurtleProgram &Tp) {
	//Array is resized
	length = Tp.getLength();
	//A new string array is created
	array = new string[Tp.getLength()];

	//The newly created string array takes in the values
	//in the old array
	for (int I = 0; I < Tp.getLength(); I++) {
		array[I] = Tp.array[I];
	}
}

/*
 * This function gets the length of the array.
 * @param: Does not take in any parameters
 * @return: An int corresponding to the
 * length of the string array.
 */
int TurtleProgram::getLength() const {
	return length;
}

/*
 * The purpose of this function is to take in an index 
 * for a position in the array. 
 * @param: One int parameter that takes in a reference
 * @return: A string corresponding to the string in that
 * position in the array.
 */
string TurtleProgram::getIndex(const int &I) const {
	//Checks if index is valid 
	if (I >= length || I < 0) {
		//Returns false 
		return nullptr;
	}
	string Position = array[I];
	return Position;
}

/*
 * The purpose of this function is to set 
 * the index of the array. 
 * @param: One int parameter that takes in a 
 * reference and one string parameter
 * that takes in a reference.
 * @return: Is a void function, so does not 
 * return anything 
 */
void TurtleProgram::setIndex(const int &I, const string &Str) {
	//Checks if index is valid 
	if (I < getLength() && I >= 0) {
		//Sets index 
		array[I] = Str;
	}
	//If index is not valid 
	else {
		return;
	}
}

/*
 * This overloading operator implements the != comparison and
 * determines if the TurtleProgram objects are inequal.
 * @param: TurtleProgram object parameter that takes in a reference
 * @return: Boolean value corresponding to whether the objects are 
 * inequal or not. 
 */
bool TurtleProgram::operator!=(const TurtleProgram &Rhs) const {
	//Checks inequality for the TurtleProgram objects
	return !(*this == Rhs); 
}

/*
 * This overloading operator implements the == comparison
 * and determines if the TurtleProgram objects are equal. 
 * @param: TurtleProgram object parameter that takes in a
 * reference
 * @return: Boolean value corresponding to whether the objects
 * are equal or not.
 */
bool TurtleProgram::operator==(const TurtleProgram &Rhs) const {
	//IF length is not equal, it returns false 
	if (getLength() != Rhs.getLength()) {
		return false;
	}

	//Goes through each element 
	for (int I = 0; I < Rhs.getLength(); I++) {
		//If a string element is not equal 
		if (array[I] != Rhs.array[I]) {
			return false;
		}
	}

	//The TurtleProgram objects are equal
	return true;
}

/*
 * Overloads the addition operator. The purpose
 * of this function is to add a TurtleProgram object
 * to another TurtleProgram object. 
 * @param: TurtleProgram object parameter that takes in 
 * a reference
 * @return: TurtleProgram object that is a combination of
 * TurtleProgram objects. 
 */
TurtleProgram TurtleProgram::operator+(const TurtleProgram &Tp) const {
	//TurtleProgram object that will be returned 
	TurtleProgram Bigger;

	//Creates new string array
	Bigger.array = new string[getLength() + Tp.getLength()];
	//Resizes array 
	Bigger.length = getLength() + Tp.getLength();

	//Iterates through the TurtleProgram object 
	for (int I = 0; I < getLength(); I++) {
		Bigger.setIndex(I, getIndex(I));
	}
	for (int I = 0; I < Tp.getLength(); I++) {
		Bigger.setIndex(getLength() + I, Tp.getIndex(I));
	}

	//Returns the combination of TurtleProgram objects
	return Bigger;
}

/*
 * Overloads the += operator. The purpose
 * of this function is to add TurtleProgram objects
 * together. 
 * @param: TurtleProgram object parameter that takes in
 * a reference
 * @return: TurtleProgram object that is a combination of
 * TurtleProgram objects.
 */
TurtleProgram &TurtleProgram::operator+=(const TurtleProgram &Tp) {
	//Creates new temporary string array
	//Using auto because clang-tidy states that using auto when
	//initializing with new avoids duplicating the type name 
	auto *TemporaryArray = new string[length + Tp.getLength()];
	//Declares variable
	int J = 0;

	//Iterates through array 
	for (int I = 0; I < length; I++) {
		//Sets elements in temporaryArray to elements in array
		TemporaryArray[I] = array[I];
	}
	//Iterates through array 
	for (int I = length; I < (length + Tp.getLength()); I++) {
		TemporaryArray[I] = Tp.array[J++];
	}

	//Appends TurtleProgram objects 
	length += Tp.getLength();

	//Cleans up memory
	delete[] this->array;

	//this array is set to temporaryArray
	this->array = TemporaryArray;

	//Returns TurtleProgram object that is a combination of 
	//TurtleProgram objects
	return *this;
}

/*
 * Overloads the * operator. This function multiplies an int
 * with a TurtleProgram object.
 * @param: int parameter that takes in a reference
 * @return: A TurtleProgram object 
 */
TurtleProgram TurtleProgram::operator*(const int &Times) const {
	//Ensures that the number being multiplied is greater than 0
	assert(Times > 0);

	//TurtleProgram object that will be returned 
	TurtleProgram Bigger;

	//The value of *this is added to TurtleProgram object
	for (int I = 0; I < Times; I++) {
		Bigger += *this;
	}

	//Returns TurtleProgram object
	return Bigger;
}

/*
 * Overloads the *= operator. This function multiplies an int
 * with a TurtleProgram object.
 * @param: int parameter that takes in a reference
 * @return: Pointer to this TurtleProgram object
 */
TurtleProgram &TurtleProgram::operator*=(const int &Times) {
	//Ensures that the number being multiplied is greater than 0
	assert(Times > 0);

	//Creates new temporary string array
	auto* TemporaryArray = new string[length*Times];
	//Declares variable corresponding to index 
	int J = 0;;

	//Iterates through array 
	for (int I = 0; I < length*Times; I++) {
		if (J >= getLength()) {
			J = 0;
		}
		//Sets elements in temporaryArray to elements in array
		TemporaryArray[I] = array[J++];
	}

	//Multiplies the TurtleProgram object
	length *= Times;

	//Cleans up memory
	delete[] this->array;

	//this array is set to temporaryArray
	this->array = TemporaryArray;

	//Returns pointer to this TurtleProgram object 
	return *this;
}

/*
 * Overloads the = operator. The purpose is to 
 * set one TurtleProgram object equal to another with a 
 * deep copy of the object contents. 
 * @param: TurtleProgram parameter that takes in a reference
 * @return: Pointer to this TurtleProgram object 
 */
TurtleProgram &TurtleProgram::operator=(const TurtleProgram &Rhs) { 
	//Creates new temporary string array
	auto* TemporaryArray = new string[Rhs.getLength()];

	//Iterates through array 
	for (int I = 0; I < Rhs.getLength(); I++) {
		//Copies the contents
		TemporaryArray[I] = Rhs.array[I];
	}

	//Length is set equal to each other 
	length = Rhs.getLength();

	//Cleans up memory 
	delete[] this->array;

	//this array is set to temporary array 
	this->array = TemporaryArray;

	//Returns pointer to this TurtleProgram object
	return *this;
}

/*
 * The purpose of this destructor is to delete the
 * array in order to clean the memory and stack.
 * @param: Does not take in any parameters
 * @return: Does not return anything 
 */
TurtleProgram::~TurtleProgram() {
	delete[] array;
}
	
/*
 * Overloaded output operator for class Array. 
 * Prints TurtleProgram objects.
 * @param: ostream object that takes in a reference
 * and TurtleProgram object that takes in a reference
 * @return: Ostream object 
 */
ostream &operator<<(ostream &Out,
	                const TurtleProgram &Tp) {
	Out << "[";
	if (Tp.getLength() != 0) {
		for (int I = 0; I < Tp.getLength(); I++) {
			Out << Tp.getIndex(I);
			if (I != Tp.getLength() - 1) {
				Out << " ";
			}
		}

	}
	Out << "]";
	return Out;
}