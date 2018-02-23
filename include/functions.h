#ifndef __H_functions__
#define __H_functions__
#include <string>

/**********************************************************************
 *This class houses the method signatures for the assignment and 
 *additional helper method
 *@author Nabeel Vali
 *********************************************************************/

bool balancedSymbols(std::string input);
std::string iToP(std::string input);
int getPrecedence(char input);
std::string loadFile(std::string file);
#endif
