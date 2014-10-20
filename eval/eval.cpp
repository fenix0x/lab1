#include "stdafx.h"
#include "stdlib.h"

const int GetOperator(const char * str)
{
	if (*str == '+')
		return 1;
	if (*str == '-')
		return 2;
	if (*str == '*')
		return 3;
	if (*str == '/')
		return 4;

	return 0;
}

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates expression of command line arguments. \n");
		return 0;
	}
	if (argc < 3) 
	{
		printf("Programm accept at least 3 command line arguments.\n");
		return 4;
	}
	if ((argc % 2) == 1) 
	{
		printf("Programm accept only odd number of command line arguments.\n");
		return 1;
	}
	double sum = 0.0;
	int exprOperator = 1;
	double param = 0.0;
	for (int i = 1; i < argc; ++i)
	{
		bool err;
		if ((i % 2) == 0) 
		{
			exprOperator = GetOperator(argv[i]);
			if (exprOperator == 0) {
				printf("Argument #%d should be + - * or /.\n", i);
				return 2;
			}
			printf(" %s", argv[i]);
		} else
		{
			param = StringToDouble(argv[i], err);
			if (err)
			{
				printf("Argument #%d is not a number.\n", i);
				return 3;
			}
			switch (exprOperator)
			{
			case 1: sum = sum + param;
				break;
			case 2: sum = sum - param;
				break;
			case 3: sum = sum * param;
				break;
			case 4: if (param == 0)
					{
						printf("Division by zero\n", i);
						return 5;
					}
					sum = sum / param;
					break;
			}
			printf(" %6.3f", param);
		}

	}
	printf(" = %6.3f\n", sum);
	return 0;
}

