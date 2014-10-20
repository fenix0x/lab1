#include "stdafx.h"
#include "stdlib.h"

// calculates sum of the digits of i 

double StringToDouble(const char * str, bool & err) 
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

int SumDigits(int i) {
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0  
	while (i != 0) 
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(int argc, char * argv[]) 
{
	if (argc < 2)
	{
		printf("Usage: fib.exe N\n");
		printf("	N - \n");
		return 0;
	}

	bool err;
	double n = StringToDouble(argv[1], err);
	if (err) 
	{
		printf("Argument is not a number.\n");
		return 1;
	}
	if (n < 1) 
	{
		printf("Argument should be greater then 0.\n");
		return 2;
	}

	double a1 = 1;
	double a2 = 1;
	bool firstNumber = true;
	for (int i = 1; (a2 < n) && (a1 <= a2); ++i)
	{
		if (!firstNumber) 
			printf(", ");
		else
			firstNumber = false;
		printf("%g", a2);
		if ((i % 5) == 0)
		{
			printf(",\n");
			firstNumber = true;
		}
		double t = a1 + a2;
		a1 = a2;
		a2 = t;
	}

	return 0;
}
