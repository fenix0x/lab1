#include "stdafx.h"
#define _USE_MATH_DEFINES 
#include <cmath>
#include "math.h"
#include <string>
#include <iostream>
using namespace std;

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

double CalculateDistance(double v, double angle) 
{
	if (v < 0.0)
		return 0.0;
	else
		return pow(v,2)*sin(M_PI*angle/90)/9.8;
}

double EnterValue(string message, bool & finish, bool & err) 
{
	string i;
	string ex = "exit";
	finish = false;
	cout << message;
	cin >> i;
	if (i.compare(ex)==0) 
	{ 
		finish = true;
		return 0;
	}
	return StringToDouble(i.c_str(), err);
}


int main(int argc, char * argv[]) 
{
	/*
	printf("%g\n", CalculateDistance(3,30));
	printf("%g\n", CalculateDistance(3,45));
	printf("%g\n", CalculateDistance(3,90));
	printf("%g\n", CalculateDistance(3,60));
	printf("%g\n", CalculateDistance(-10,30));
	printf("%g\n", CalculateDistance(10,-30));
*/
	bool finish = false;
	bool err = false;

	do
	{
		double v = EnterValue("Enter v0 (or type 'exit') > ", finish, err);
		double a;
		if (!(finish || err))
			a = EnterValue("Enter a0 (or type 'exit') > ", finish, err);
		if (!(finish || err))
			cout << "Distance is: " << CalculateDistance(v, a) << "\n";
	} while (!(finish || err));

	if (err)
		cout << "You entered incorrect value\n";
	else
		cout << "Goodbye\n";
	return 0;
}

