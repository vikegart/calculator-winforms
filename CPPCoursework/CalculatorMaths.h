#pragma once
#include <iostream>
using namespace std;

class CalculatorMaths
{




public:
	CalculatorMaths();
	CalculatorMaths(bool radians);
	~CalculatorMaths();

	double angleToUse = 0.0;
	double degreeToRadian = pi / 180;
	double radianToDegrees = (180 / pi);
	double angleType; // Multiply angle results by this
	bool radians = true;
	

private:
	double result;
	const double pi = 3.141592653589;
	const double e = 2.718281828459;

public:
	double Add(double lhs, double rhs);
	double Subtract(double lhs, double rhs);
	double Divide(double lhs, double rhs);
	double Multiply(double lhs, double rhs);
	int Modulous(int lhs, int rhs);
	double SquareRoot(double x);
	double Exponential(double x);
	double CommonLog(double x);
	double NatLog(double x);
	int Factorial(int x);
	double RaiseToPower(double x, double byY);
	double Percent(double xPercent, double ofY);
	double Pi();
	double E();
	double Sin(double x);
	double Cos(double x);
	double Tan(double x);
	double ASin(double x);
	double ACos(double x);
	double ATan(double x);
	double Atan2(double x, double y);
};