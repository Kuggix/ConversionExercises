#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

struct MathHelper 
	{
		//used for shorthand
		typedef unsigned int uint;
		std::string BaseMapper(int numToConvert)
		{
			std::string baseMap = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			std::string s = "";
			s += baseMap[numToConvert];
			return s;
		}

		std::string ConvertToBase(int baseNum, int baseType)
		{
			int result = baseNum / baseType;
			int tempRemainder = baseNum % baseType;
			//we get the hex conversion, and the easiest way to store it is by making a string of numbers.
			std::string remainders;
			remainders = BaseMapper(tempRemainder);

			while (result > 0)
			{
				remainders = remainders + BaseMapper((result % baseType));
				result = result / baseType;
			}
			//our result is now 0, we should have all of our numbers! First, we should reverse the string however.
			std::reverse(remainders.begin(), remainders.end());
			return remainders;
		}
	};

void printResult(std::string result)
{
	std::cout << result << std::endl;
}
int main()
{
	enum bases {binary = 2, oct = 8, hex = 16};
	MathHelper helper;

	/*
	hex test, all pass
	*/
	printResult(helper.ConvertToBase(1128, hex));
	printResult(helper.ConvertToBase(256, hex));
	printResult(helper.ConvertToBase(921, hex));
	printResult(helper.ConvertToBase(188, hex));
	printResult(helper.ConvertToBase(100, hex));
	printResult(helper.ConvertToBase(590, hex));

	/* 
	oct test, all pass
	*/
	printResult(helper.ConvertToBase(25, oct));
	printResult(helper.ConvertToBase(1090, oct));

	/*
	binary test, all pass
	*/
	printResult(helper.ConvertToBase(10, binary));
	printResult(helper.ConvertToBase(15, binary));

	std::cin.get();
    return 0;
}

