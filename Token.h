#ifndef TOKEN_H
#define TOKEN_H
#include <iostream> 
using namespace std; 


class Token {
    private:
        string type; 
        string value; 
    
    public:
        Token();
        Token(string type, string value); 
        string getType(); 
        string getValue(); 
        bool equalToken(Token token); 
        string toString(); 
};

Token::Token(){
    this->type = "Not Initialized yet"; 
    this->value = "Not Initialized yet"; 
}

Token::Token(string type, string value){
    this->type = type; 
    this->value = value; 
}

string Token::getType(){
    return type; 
}

string Token::getValue(){
    return value;
}

bool compare(string s1, string s2){
    if(s1.length() != s2.length()) return false; 
    for(int i = 0; i < s1.length(); i++) if(toupper(s1[i]) != toupper(s2[i])) return false; 
    return true; 
}

bool Token::equalToken(Token token){
    if(token.value.length() > 0) return type == token.type && compare(value, token.value); 
    else return type == token.type;    
}

string Token::toString(){
    string s = ""; 
    s += '<'; 
    s += type; 
    s += ", ";  
    s += value; 
    s += '>'; 
    return s; 
}

#endif