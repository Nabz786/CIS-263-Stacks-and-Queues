#include "functions.h"
#include "iostream"
#include "string"
int main(int argc, char** argv){
	
		//test class is in a textfile called test
		//balancedSymbols(loadFile("test"));
	
		std::string inputString = loadFile("file");
		balancedSymbols(inputString);
		std::cout << iToP("1+2*3+6") << std::endl;
		std::cout << iToP("2+8*3+(7+6*6)*5+(6*3-2)/7") << std::endl;
		std::cout << iToP("(5*2)*((7-5*2)*(5+3))") << std::endl;
	}
