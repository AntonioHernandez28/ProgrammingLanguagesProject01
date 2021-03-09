#ifndef SCANNER_H
#define SCANNER_H
#include "Token.h"
#include <algorithm>
#include <vector> 
using namespace std; 

#define ERR 999

class Scanner {
    private:  
        int transitionMatrix[14][25] =  {
				/*	SUM, SUB, MUL, DIV		MOV		0,1,2,3,4,5,6,7,8,9		A,B,C,D		#		SPC		 \N		;*/
	/* q0 */	{			1,				2,				ERR,				ERR,	ERR,	ERR,	ERR,	13},
	/* q1 */	{			ERR,			ERR,			ERR,				ERR,	ERR,	3,		ERR,	ERR},
	/* q2 */	{			ERR,			ERR,			ERR,				ERR,	ERR,	4,		ERR,	ERR},
	/* q3 */	{			ERR,			ERR,			ERR,				ERR,	5,		ERR,	ERR,	ERR},
	/* q4 */	{			ERR,			ERR,			7,					ERR,	8,	ERR,	ERR,	ERR},
	/* q5 */	{			ERR,			ERR,			ERR,				6,		ERR,	ERR,	ERR,	ERR},
	/* q6 */	{			ERR,			ERR,			ERR,				ERR,	ERR,	10,		ERR,	ERR},
	/* q7 */	{			ERR,			ERR,			7,					ERR,	ERR,	10,		ERR,	ERR},
	/* q8 */	{			ERR,			ERR,			ERR,				9,		ERR,	ERR,	ERR,	ERR},
	/* q9 */	{			ERR,			ERR,			ERR,				ERR,	ERR,	10, 	ERR,	ERR},
	/* q10*/	{			ERR,			ERR,			ERR,				ERR,	11,		ERR,	ERR,	ERR},
	/* q11*/	{			ERR,			ERR,			ERR,				12,		ERR,	ERR,	ERR,	ERR},
	/* q12*/	{			ERR,			ERR,			ERR,				ERR,	ERR,	ERR,	ERR,	ERR}
    }; 
    public:
        Scanner(); 
        vector<Token> scan(string);
        int filter(char c);        
}; 

Scanner::Scanner(){
    
}

int Scanner::filter(char c){
    switch (c) {
	case '0':
		return 5;
	case '1':
		return 6;
	case '2':
		return 7;
	case '3':
		return 8;
	case '4':
		return 9;
	case '5':
		return 10;
	case '6':
		return 11;
	case '7':
		return 12;
	case '8':
		return 13;
	case '9':
		return 14;
	};
    return -1; 
}

vector<Token> Scanner::scan(string s){
    char c; 
    int state = 0, index = 0; 
    string value; 
    vector<Token> tokens; 
    while(index < s.length()){
        value = ""; 
        do {
            c = s[index++]; 
            state = transitionMatrix[state][filter(c)]; 
            if(state > 0) value += c; 
        } while(index < s.length() && state < 100);  
        //Checar el switch a ver si concuerda con los cambios que hicimos en la matrix que cambio el DFA ! 
        switch(state){
            case 0:
                return tokens; 
            break; 
            case 6:{
                if(value == "#A" || value == "#B" || value == "#C" || value == "#D"){
                    Token current("REGISTER", value); 
                    tokens.push_back(current); 
                }
                else cout << "LEXICAL ERROR THE STRING: " << value << " IS NO VALID ELEMENT IN THE LANGUAGE" << endl;
            }
            break; 
            case 1:{
                if(value == "SUM" || value == "SUB" || value == "MUL" || value == DIV){
                    Token current("OPERATION", value); 
                    tokens.push_back(current); 
                }
                else if(value == "MOV"){
                    Token current("ASSIGNMENT", value); 
                    tokens.push_back(current); 
                }
                else cout << "LEXICAL ERROR THE STRING: " << value << " IS NO VALID ELEMENT IN THE LANGUAGE" << endl;
            }
            break; 
            case 13:{
                Token current("EOF", value); 
                tokens.push_back(current); 
            }
            break; 
        }
        state = 0; 
    }
    return tokens; 
}



#endif