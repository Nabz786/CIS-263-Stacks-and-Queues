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

	//loop through each char only adding the three basic chars
	for(auto iterator = input.begin(); iterator != input.end(); ++iterator){
		if(*iterator == '(' || *iterator == '[' || *iterator == '{'){
			checkSymbols.push(*iterator);				
		}else{	
			//closing tag and stack is empty throw error
			 if((*iterator == ')' && checkSymbols.empty())
			  || (*iterator == ']' && checkSymbols.empty())
		          ||  (*iterator == '}' && checkSymbols.empty())
			  ){	
				std::cout << "Unmatched Symbol Expression!" << std::endl; 
				return false;
			 }else{
				//check the stack for the opening char
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

/**********************************************************************
 *This method takes in an infix expression and returns a postfix 
 *expression
 *param- std::string - infix expression
 *returns std::string - postfix expression
 *********************************************************************/

std::string iToP(std::string input){

	std::cout << "Parsing: " << input << std::endl;
	
	std::string outputString = "";
	
	std::stack<char, std::deque<char> > operatorStack;

	//begin by looping through each char
	for(auto iterator = input.begin(); iterator != input.end(); ++iterator){
		//only numbers and variables get passed immediately to the postfix
		if(*iterator != '('
		 && *iterator != ')'
		 && *iterator != '+'
		 && *iterator != '-'
		 && *iterator != '*'
		 && *iterator != '/'
		 ){
			outputString.push_back(*iterator);
		//	outputString.append(" ");
		//if we find an operator we check what type it is
		}else{	
		    if(*iterator != ')'){
			//if the char is a opening parenthese we push to the stack
		        if(*iterator == '('){
		            operatorStack.push(*iterator);
		        }else if(operatorStack.empty()){
					operatorStack.push(*iterator);
			//if the iterator value is greater than the top value
			//we push to the stack
			}else if(getPrecedence(*iterator) >
						 getPrecedence(operatorStack.top())){
					operatorStack.push(*iterator);
			}else{
				//if we get an operator of lower precedence we must
				//remove everything of greater and the same precedence
				while(!operatorStack.empty() && (getPrecedence(*iterator)
					 <= getPrecedence(operatorStack.top()))){
					outputString.push_back(operatorStack.top());
		//			outputString.append(" ");
					operatorStack.pop();
				}
					//we finally add the iterator after everything is popped
					operatorStack.push(*iterator);
			}
			//if we get a closing parenthese we must remove everything between both tags
		    }else{
		         if(*iterator == ')'){
			//loop and remove all items between both parentheses
		            while(operatorStack.top() != '(' && !operatorStack.empty()){
					outputString.push_back(operatorStack.top());
					operatorStack.pop();
				}
				//finally remove the opening parenthese
				operatorStack.pop();
		   	 }
		    
			}
		}	
	}
	
	//if the stack wasnt empty pop and append everything to the postfix exp
	if(!operatorStack.empty()){
		while(!operatorStack.empty()){
			outputString.push_back(operatorStack.top());
		//	outputString.append(" ");
			operatorStack.pop();
		}
	}
	//return the new postfix expression
	return outputString;
}

/**********************************************************************
 *This method takes in a operator character and returns a correct
 *weight/precedence value
 *@param char - character to be weighted
 *@return int - weight of character
 *********************************************************************/
int getPrecedence(char input){
	int precedenceVal = 0;

	switch(input){
		case '-':
			return 1;
			break;
		case '+':
			return 1;
			break;
		case '/':
			return 2;
			break;
		case '*':
			return 2;
			break;
		case '(':
			return -1;
			break;
	}
	return precedenceVal;
}

/***********************************************************************
 *This method loads a text file into a string from a specified file path
 *@param string-file to be tested
 *@returns the contents of the file in one string
 **********************************************************************/
//source for code on how to load file:
//https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
std::string loadFile(std::string file){
	std::ifstream t(file);
	std::string str((std::istreambuf_iterator<char>(t)),
	std::istreambuf_iterator<char>());
	return str;
}

