#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

class MathHelper 
	{
	public:
		int ConvertFromHex(char digit)
		{
			switch (digit)
			{
			case 'A': return 10;
			case 'B': return 11;
			case 'C': return 12;
			case 'D': return 13;
			case 'E': return 14;
			case 'F': return 15;
			}
		}
		std::string ConvertToHex(int baseNum)
		{
			int result = baseNum / 16;
			//we get the hex conversion, and the easiest way to store it is by making a string of numbers.
			std::string remainders;
			int tempRemainder = baseNum % 16;
			if (tempRemainder > 9)
			switch (tempRemainder)
			{
				case 10: remainders = remainders + 'A'; break;
				case 11: remainders = remainders + 'B'; break;
				case 12: remainders = remainders + 'C'; break;
				case 13: remainders = remainders + 'D'; break;
				case 14: remainders = remainders + 'E'; break;
				case 15: remainders = remainders + 'F'; break;
					//Our num doesn't need to be changed since 1-9 are the same in dec to hex
			    default: break;
			}
			else
				remainders = std::to_string(baseNum % 16);

			while (result > 0)
			{ 
				remainders = remainders + std::to_string(result % 16);
				result = result / 16;
				
			}
			//our result is now 0, we should have all of our numbers! First, we should reverse the string however.
			std::reverse(remainders.begin(), remainders.end());
			return remainders;
		}
	};

int main()
{
	MathHelper helper;
	std::cout << helper.ConvertToHex(1128) << "\n" << helper.ConvertToHex(256); //pass
	std::cout << helper.ConvertToHex(921) << "\n"; //pass
	std::cout << helper.ConvertToHex(188) << "\n"; //fail, should output BC
	std::cout << helper.ConvertToHex(100) << "\n"; //pass
	std::cout << helper.ConvertToHex(590) << "\n"; //pass
	std::cin.get();
    return 0;
}

