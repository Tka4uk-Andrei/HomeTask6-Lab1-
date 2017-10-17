#include <iostream>

using namespace std;

const string FILE_NAME = "input.txt";

inline bool isConcoleRead()
{
	bool correctInputFlag = false;

	char c;
	while (!correctInputFlag)
	{
		std::cout << "Do you want to read from console (y/n)? ";
		cin >> c;

		if (c == 'y' || c == 'n')
			correctInputFlag = true;
		else
			cout << "Incorrect input\n";
	}

	return c == 'y';
}