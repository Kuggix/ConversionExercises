#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

struct MathHelper 
	{
		//used for shorthand
		typedef unsigned int uint;
		std::string MapIntToHex(int numToConvert)
		{
			std::string hexMap = "0123456789ABCDEF";
			std::string s = "";
			s = s + hexMap[numToConvert];
			return s;
		}
		std::string ConvertToHex(int baseNum)
		{
			int result = baseNum / 16;
			int tempRemainder = baseNum % 16;
			//we get the hex conversion, and the easiest way to store it is by making a string of numbers.
			std::string remainders;
			remainders  = MapIntToHex(tempRemainder);

			while (result > 0)
			{ 
				remainders = remainders + MapIntToHex((result % 16));
				result = result / 16;
			}
			//our result is now 0, we should have all of our numbers! First, we should reverse the string however.
			std::reverse(remainders.begin(), remainders.end());
			return remainders;
		}
		std::string ConvertToOct(uint baseNum)
		{
			std::string remainders = "";
			while (baseNum > 0)
			{
				remainders = remainders + std::to_string(baseNum % 8);
				baseNum /= 8;
			}
			std::reverse(remainders.begin(), remainders.end());
			return remainders;
		}
	};

int main()
{
	MathHelper helper;
	//std::cout << helper.ConvertToHex(1128) << "\n";//pass 468 
	//std::cout << helper.ConvertToHex(256) << "\n"; //pass 100
	//std::cout << helper.ConvertToHex(921) << "\n"; //pass 399
	//std::cout << helper.ConvertToHex(188) << "\n"; //pass BC
	//std::cout << helper.ConvertToHex(100) << "\n"; //pass 64
	//std::cout << helper.ConvertToHex(590) << "\n"; //pass 24E
	std::cout << helper.ConvertToOct(1792) << "\n"; //pass 
	std::cout << helper.ConvertToOct(4321) << "\n"; //pass
	std::cout << helper.ConvertToHex(25) << "\n"; //fail
	std::cin.get();
    return 0;
}

