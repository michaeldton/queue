/***************************
* Author: Michael Ton
* Date: 10/27/18
* Description: This header file contains the function prototypes of functions used to validate user input. It will be used for a variety of assignments in CS162 that require input validation. In its current form, it validates integer input, and contains functions to do and utilizes overloaded functions.
****************************/
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>

int getInteger(); //integer input validation without limitations (i.e. min/max range)
int getInteger(int, int); //takes in two parameters that set min/max bounds used to check the user input
bool isInRange(std::string); //check and handle errors involving bounds of integer variable type
bool isInRange(std::string, int, int); //check and handle errors involving bounds of the integer variable type, accounting for min/max bounds
bool isOnlyDigits(std::string); //returns true if string input contains only numeric characters (0-9)

#endif
