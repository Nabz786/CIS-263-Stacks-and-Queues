#ifndef __H_functions__
#define __H_functions__
#include <string>

/**********************************************************************
 *This class houses the method signatures for the assignment and 
 *additional helper methods
 *@author Nabeel Vali
 *********************************************************************/

/**********************************************************************
 *This method takes in a string and checks if the three basic
 *characters () [] {} are balanced
 *@param std::string - string to check
 *@returns boolean - true or false if the string was balanced or not
 *********************************************************************/
 bool balancedSymbols(std::string input);

/**********************************************************************
 *This method takes in an infix expression and returns it in postfix
 *form
 *@param std::string - string to convert
 *@returns std::string - postfix expression
 *********************************************************************/
 std::string iToP(std::string input);

/**********************************************************************
 *This method takes in a chararcter and returns its weighted value
 *@param char - character to weigh
 *@returns int - the weight of the character
 *********************************************************************/
 int getPrecedence(char input);

/**********************************************************************
 *This method loads an entire textfile into a string
 *@param std::string - file to load
 *@returns std::string - string with entire contents of file
 **********************************************************************/
 std::string loadFile(std::string file);
#endif
