/*
	Antonio		A01382469
	Bernardo	A01194086
	Alejandro Myrick	A00819666
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

#define ERR	999

// Filas => Estados | Columnas => Transiciones 
const int transMat[14][25] = {
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

int filter(char c) {
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

	}
}

void matrixHandler(string s) {
	int index = 0; 
    string value = ""; 
    int state = 0; 
	while(index < s.length()){
        do {
            char c = s[index++]; 
            state = transMat[state][filter(c)]; 
            if(state != 0) value += c; 
        } while(index < s.length() && state < 100);
    } 
}

int main() {
	ifstream inputFile;
	string line;
    

	//Read from file
	while (!inputFile.eof()) {
		getline(inputFile, line);
		// DIV, MUL, SUB, SUM MOV 

	}

	return 0;
}