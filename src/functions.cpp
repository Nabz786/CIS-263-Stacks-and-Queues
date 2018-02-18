#include "functions.h"
#include <iostream>
#include <string>
#include <stack>



bool balancedSymbols(std::string input){

	std::cout << "Checking to see if the string is balanced " << input << std::endl;
	//create a new empty stack 
	std::stack<char, std::deque<char> > checkSymbols; 

	for(auto iterator = input.begin(); iterator != input.end(); ++iterator){
		if(*iterator == '(' || *iterator == '[' || *iterator == '{'){
			std::cout << *iterator << std::endl;
			checkSymbols.push(*iterator);				
			std::cout << checkSymbols.size() << std::endl;
		}
		else{
			 if((*iterator == ')' && checkSymbols.size() == 0) || (*iterator == ']' && checkSymbols.size() == 0) ||  (*iterator == '}' && checkSymbols.size() == 0)){
				std::cout << checkSymbols.size() << std::endl;
				std::cout << *iterator << std::endl;	
				throw "Unmatched symbol expression here";
		 
			 }else{
				char currentSymbol = checkSymbols.top();

				if(*iterator == ')' && currentSymbol != '('){
					throw "umathched symbol expression 1";
				}
				else if(*iterator == ']' && currentSymbol != '['){
					throw "unmatched symbol expression 2";
				}	
				else if(*iterator == '}' && currentSymbol != '{'){
					throw "unmatched symbol expression 3";
	 			}
				else{
					checkSymbols.pop();
				}
			}
		}
	}

	if(checkSymbols.size() != 0){
		std::cout << "String was not balanced!" << std::endl;
		throw("Unmatched symbol expression here 5");
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
	}catch(char const* error){
		std::cout << error << std::endl;
	}
}
