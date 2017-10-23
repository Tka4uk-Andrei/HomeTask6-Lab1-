#pragma once
#include <iostream>

enum readTypes {console, file, random};

using namespace std;

inline int getReadType()
{
	while (true)
	{
		cout << "Enter \'1\' if you want to print into console\n";
		cout << "Enter \'2\' if you want to get info from file\n";
		cout << "Enter \'3\' if you want to generate randome values\n";

		int a;

		if(!(cin >> a))


		if (a == console || a == file || a == random)
			return a;

		cout << "Value isn't correct. Re-enter values\n\n";
	}
}