#include "functions.h"
#include "iostream"
#include "string"

/**********************************************************************
 *Main class to run both methods
 *
 *@author Nabeel Vali
 *********************************************************************/
int main(int argc, char** argv){
	
	
	//check balance test, just replace contents between () with
	//your file name
	std::string inputString = loadFile("file");
	balancedSymbols(inputString);

	//iToP tests
	std::cout << iToP("1+2*3+6") << std::endl;
	std::cout << iToP("2+8*3+(7+6*6)*5+(6*3-2)/7") << std::endl;
	std::cout << iToP("(5*2)*((7-5*2)*(5+3))") << std::endl;
}
