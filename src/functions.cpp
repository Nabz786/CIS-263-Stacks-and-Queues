#include "functions.h"
#include <iostream>
#include <string>
#include <stack>

/**********************************************************************
 *Stacked and queuse, these two methods support different
 *implementations of stacka and queues and how they can be used to 
 *solve problems.
 *
 *@author Nabeel Vali
 ********************************************************************/

public:


/**
 *This method takes in a string and checks to see if three basic 
 *symbols are balanced
 *@param string - input string to check 
 *returns boolean - true or false if the characters are balanced
 **/ 
bool balancedSymbols(std::string input){

	std::cout << "Checking to see if the string is balanced " << input << std::endl;
	//create a new empty stack 
	std::stack<char, std::deque<char> > checkSymbols; 

	for(auto iterator = input.begin(); iterator != input.end(); ++iterator){
		if(*iterator == '(' || *iterator == '[' || *iterator == '{'){
			checkSymbols.push(*iterator);				
		}else{
			 if((*iterator == ')' && checkSymbols.size() == 0) || (*iterator == ']' && checkSymbols.size() == 0) || 
				 (*iterator == '}' && checkSymbols.size() == 0)){	
					std::cout << "Unmatched Symbol Expression!" << std::endl; 
					return false;
			 }else{
				if(*iterator == ')' && checkSymbols.top() != '('){
					std::cout << "Unmatched Symbol Expression!" << std::endl;
					return false;
				}else if(*iterator == ']' && checkSymbols.top() != '['){
					std::cout << "Unmatched Symbol Expression!" << std::endl;
					return false;
				}else if(*iterator == '}' && checkSymbols.top() != '{'){
					std::cout << "Umatched Symbol Expression!" << std::endl;
					return false; 
				}else
					checkSymbols.pop();
			}
		}
	}

	if(checkSymbols.size() != 0){
		std::cout << "String was not balanced!" << std::endl;
		return false;
	}else{
		std::cout << "String was balanced!" << std::endl;
		return true;
	}
}

std::string iToP(std::string input){



}

int main(int argc, char** argv){
	try{
		balancedSymbols("()"); //TRUE
		balancedSymbols("((()))"); //TRUE
		balancedSymbols("{(((([]))))}"); //TRUE
		balancedSymbols("([)]"); //False
		balancedSymbols("(((()()(()"); //FALSE
		balancedSymbols("{{(((([][]))))}"); //FALSE
		balancedSymbols("{"); //FALSE
		balancedSymbols("}"); //FALSE
	}catch(char const* error){
		std::cout << error << std::endl;
	}
}
