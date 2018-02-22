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
							std::cout << "Unmatched Symbol Expression!" << std::endl;
						else
							checkSymbols.pop();
						break;
					case ']':
						if(checkSymbols.top()!= '[')
							std::cout << "Unmatched Symbol Expression!" << std::endl;
						else
							checkSymbols.pop();
						break;
					case '}':
						if(checkSymbols.top()!= '{')
							std::cout << "Unmatched Symbol Expression!" << std::endl;
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
			std::cout << *iterator << std::endl;
			outputString.push_back(*iterator);
			outputString.append(" ");
		//	std::cout << *iterator << std::endl;	
		}else{			
			if(operatorStack.empty()){
				std::cout << *iterator << std::endl;
				operatorStack.push(*iterator);
				std::cout << "here1" << std::endl;
			}else if(*iterator == ')'){
				while(operatorStack.top() != '(' && !operatorStack.empty()){
					outputString.push_back(operatorStack.top());
					operatorStack.pop();
				}
				operatorStack.pop();
				std::cout << "here2" << std::endl;
			}else{
				std::cout << "here4" << std::endl;
				if(getPrecedence(operatorStack.top()) >= getPrecedence(*iterator)){
					if(getPrecedence(*iterator) == 99){
						operatorStack.push(*iterator);
					}else{
					std::cout << "here5" << std::endl;
					std::cout << "stack size " << operatorStack.size() << std::endl;
					std::cout << "top " << getPrecedence(operatorStack.top()) << " iterator " << getPrecedence(*iterator) << std::endl;
					int currentIterator = getPrecedence(*iterator);
					int currentTop = getPrecedence(operatorStack.top());
					while(currentTop >= currentIterator){
						if(!operatorStack.empty()){
						std::cout << "here6" << std::endl;
						outputString.push_back(operatorStack.top());
						std::cout << "here7" << std::endl;
						outputString.append(" ");	
						std::cout << "here8" << std::endl;
						operatorStack.pop();
						if(!operatorStack.empty()){
							currentTop = getPrecedence(operatorStack.top());
						}

							std::cout << "here9" << std::endl;
						}
					}
					std::cout << "end loop" << std::endl;	
					}
				//	operatorStack.push(*iterator);
				}else{
					operatorStack.push(*iterator);			
				}
				std::cout << "here3" << std::endl;
			}	
		}
	}

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
			precedenceVal = 99;
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

	//std::cout << iToP("1 + 2 * 3 + ( 4 * 5 + 6) * 7") << std::endl;
	std::cout << iToP("1-(7+6)") << std::endl;
//	std::cout << getPrecedence('+') << std::endl;
}
