#include "functions.h"
#include <iostream>
#include <string>
#include <stack>
#include <fstream> 
#include <streambuf>

/**********************************************************************
 *Stacks and queues, these two methods support different
 *implementations of stacka and queues and how they can be used to 
 *solve problems.
 *@author Nabeel Vali
 ********************************************************************/




/**********************************************************************
 *This method takes in a string and checks to see if three basic 
 *symbols are balanced
 *@param string - input string to check 
 *returns boolean - true or false if the characters are balanced
 **********************************************************************/ 

bool balancedSymbols(std::string input){

	std::cout << "Parsing Code" <<  std::endl;

	//create and initialize a new stack 
	std::stack<char, std::deque<char> > checkSymbols; 

	//loop through all chars in the string, only push specific chars
	//if the stack is empty and we find a closing char we highlight an error
	//if not previous case, validate that each char has a corresponding char
	for(auto iterator = input.begin(); iterator != input.end(); ++iterator){
		if(*iterator == '(' || *iterator == '[' || *iterator == '{'){
			checkSymbols.push(*iterator);				
		}else{	
			 if((*iterator == ')' && checkSymbols.empty())
			  || (*iterator == ']' && checkSymbols.empty())
		          ||  (*iterator == '}' && checkSymbols.empty())
			  ){	
				std::cout << "Unmatched Symbol Expression!" << std::endl; 
				return false;
			 }else{
				switch(*iterator){
					case ')':
						if(checkSymbols.top()!= '(')
							return false;
						else
							checkSymbols.pop();
						break;
					case ']':
						if(checkSymbols.top()!= '[')
							return false;
						else
							checkSymbols.pop();
						break;
					case '}':
						if(checkSymbols.top()!= '{')
							return false;
						else
							checkSymbols.pop();	
						break;
				}
			}
		}
	}

	//if the stack was not empty then a char was not balanced 
	if(!checkSymbols.empty()){
		std::cout << "String was not balanced!" << std::endl;
		return false;
	}else{
		std::cout << "String was balanced!" << std::endl;
		return true;
	}
}

std::string iToP(std::string input){

	std::cout << "Parsing: " << input << std::endl;
	
	std::string outputString = "";
	
	std::stack<char, std::deque<char> > operatorStack;

	for(auto iterator = input.begin(); iterator != input.end(); ++iterator){
		if(*iterator != '('
		 && *iterator != ')'
		 && *iterator != '+'
		 && *iterator != '-'
		 && *iterator != '*'
		 && *iterator != '/'
		 ){
			outputString.push_back(*iterator);
			outputString.append(" ");
		}else{	
			if(*iterator == ')'){
				while(operatorStack.top() != '(' && !operatorStack.empty()){
					outputString.push_back(operatorStack.top());
					operatorStack.pop();
				}
				operatorStack.pop();
			}else if(*iterator == '('){
				operatorStack.push(*iterator);
			}else{
				if(operatorStack.empty()){
					operatorStack.push(*iterator);
				}else if(getPrecedence(*iterator) > getPrecedence(operatorStack.top())){
					operatorStack.push(*iterator);
				}else{
					while((getPrecedence(*iterator) <= getPrecedence(operatorStack.top()))&& !operatorStack.empty()){
						outputString.push_back(operatorStack.top());
						outputString.append(" ");
						operatorStack.pop();
					}
					std::cout << "her2e" << std::endl;
					operatorStack.push(*iterator);
				}
			}
		}	
	}
	
	std::cout << "Please be here" << std::endl;
	if(!operatorStack.empty()){
		while(!operatorStack.empty()){
			outputString.push_back(operatorStack.top());
			outputString.append(" ");
			operatorStack.pop();
		}
	}
	return outputString;
}

int getPrecedence(char input){
	int precedenceVal = 0;

	switch(input){
		case '-':
			precedenceVal = 0;
			break;
		case '+':
			precedenceVal = 1;
			break;
		case '/':
			precedenceVal = 2;
			break;
		case '*':
			precedenceVal = 3;
			break;
		case '(':
			precedenceVal = -1;
			break;
	}
	return precedenceVal;
}

/**
 *This method loads a text file into a string from a specified file path
 **/
std::string loadFile(){
	std::ifstream t("test");
	std::string str((std::istreambuf_iterator<char>(t)),
	std::istreambuf_iterator<char>());
	return str;
}

int main(int argc, char** argv){
//	try{
//	
//		balancedSymbols(loadFile());
//	}catch(char const* error){
//		std::cout << error << std::endl;
//	}

	std::cout << iToP("1+2*3+6") << std::endl;
//	std::cout << iToP("2 + ( 7 + 6 * 6 ) * 5") << std::endl;
//	std::cout << getPrecedence('+') << std::endl;
//	std::cout << iToP("2+6+7+9+4+5+3+2+5+1+9") << std::endl;

}
