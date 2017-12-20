// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#ifndef __ARIFMETIC_H__
#define __ARIFMETIC_H__
#include <string>
#include "iostream"
#include "stack.h"
#include <cstring>
using namespace std;
class Lexem {
private:
	bool OPER;
	double VAR;
	int priority;
	int type;
	string LStr;
public:
	int getype() { return type; };
	void setype(int k) { type = k; };
	double getVAR() { return VAR; };
	void setVAR(double k) { VAR = k; };
	void setLStr(string k) { LStr = k; };
	string getLStr() { return LStr; };
	void setpriority(int k) { priority = k; };
	int getpriority() { return priority;};
	Lexem& operator = (const Lexem &b);
};


class Arifmetic {
private:
	string Str;
	int lengthStr;
	Lexem * SimplyLexem;
	int q1;
	int v1;
	Lexem * PolishLexem;
	//Stack <Lexem> One;
	//Stack <Lexem> Two;

public: 
	Arifmetic(const string a) { Str = a; lengthStr = a.length(); };
	void GetArrLexOne();
    void PrintArrLex();
	void PrintArrLex2();
	void GetArrLexTwo();
	int Lala(); // определение параметров
	double Calculete();
};
int ChekString(const string a);
string DellProbel(const string a);

#endif