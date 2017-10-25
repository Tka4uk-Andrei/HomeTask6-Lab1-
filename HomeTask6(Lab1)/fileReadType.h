#include <iostream>
#include "consoleReadInt.h"

inline bool isStandartRead()
{
	while (true)
	{
		char a;

		std::cout << "Enter do you want to read one file (y/n)?\n";
		std::cin >> a;

		if (a == 'y' || a == 'Y')
			return true;
		if (a == 'n' || a == 'N')
			return false;

		std::cout << "Value isn't correct. Re-enter values\n\n";
	}

}

inline dynIntArr filePrefixes()
{
	cout << "Enter parametrs for file prefixes\n";
	
	dynIntArr arr;
	
	cout << "Enter array len, then values ";
	arr = readIntStream(cin);
	
	return arr;

}