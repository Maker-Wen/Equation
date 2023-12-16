#pragma once
#include "BinaryOperation.h"
#include "AdditionOperation.h"
#include "SubtractOperation.h"
#include "MutiplicationOperation.h"
#include "DivisionOperation.h"
#include "MixtureOperation.h"
#include "MixedOperationWithBracket.h"
#include "Equation.h"
#include <unordered_map>
#include <unordered_set>

class Equation
{
public:
	Equation();
	~Equation();
	void createEquation(int mode);
	void createBracketEquation(int n = BinaryOperation::MaxNums);
	void createSumEquation(int n, int m, int mode);
	void printEquation();
	//void loadEquationToFile(const string& filename);
	//void readEquationFromFile(const string& filename);

	static unordered_map<string, int> equation;


private:
};


