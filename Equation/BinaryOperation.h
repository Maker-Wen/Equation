#pragma once
#include<iostream>
#include<string>
#include <cmath>
#include<vector>
#include<stack>
#include<fstream>
#include<algorithm>
using namespace std;

class BinaryOperation
{
public:
	BinaryOperation();
	BinaryOperation(string s);
	~BinaryOperation();
	
	virtual void replaceSpace(string& s);
	virtual bool checkIsLaw(string& s);
	virtual void printOperation();
	virtual const string& getOperation();
	virtual int getValue();
	virtual bool getLaw();
	virtual int calculate() = 0;
	virtual void createOperation(int n = MaxNums) = 0;

	//bool operator== (const BinaryOperation* p) const {
	//	return operation == p->operation;
	//}

	//size_t operator()(const BinaryOperation* p) const {
	//	return hash<string>() (p->operation);
	//}

	friend class Equation;
	static int MAXVALUE;
	static int MINVALUE;
	static vector<char> Ops;
	static int NumOps;
	static int MaxNums;
	static int MinNums;

protected: 
	string operation;
	int value;
	bool islaw = true;
};




