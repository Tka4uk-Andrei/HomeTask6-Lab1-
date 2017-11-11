#include <iostream>

int filePrefix()
{
	std::cout << "Enter file prefix\n";

	int pref;
	if (!(std::cin >> pref))
		throw std::string("File prefix must be integer");

	return pref;
}