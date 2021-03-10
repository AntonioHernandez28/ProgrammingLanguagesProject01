#ifndef PARSER_H
#define PARSER_H
#include <iostream> 
#include <vector> 
#include "Token.h"

// Clase Parser 
class Parser{
    public: 
        Parser(); 
        void parseS(vector<Token>); 
        void parse(vector<Token>); 
        bool match(vector<Token>, Token); 
}; 

Parser::Parser(){

}

void Parser::parse(vector<Token> tokens){
    parseS(tokens); 
    cout << "Input has compiled successfully" << endl; 
}

void Parser::parseS(vector<Token> tokens){
    if(tokens.empty()){
        cout << "Token expected" << endl; 
    }
    if(tokens[0].getType() == "EOF"){
        Token current("EOF", ";"); 
        match(tokens, current);
        return;  
    }
}


#endif