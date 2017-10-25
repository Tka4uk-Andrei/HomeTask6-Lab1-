#pragma once
#include <iostream>

enum readTypes {console, file};

using namespace std;

inline int getReadType()
{
	while (true)
	{
		cout << "Enter \'1\' if you want to print into console\n";
		cout << "Enter \'2\' if you want to get info from file\n";

		char a;
		cin >> a;

		if (int(a - '1') == console || int(a - '1') == file)
			return int(a - '1');

		cout << "Value isn't correct. Re-enter values\n\n";
	}
}