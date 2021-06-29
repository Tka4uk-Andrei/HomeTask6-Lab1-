#include <iostream>

/// <summary>
/// Считывание целого числа - префикса файла
/// </summary>
/// <returns>
/// Префикс файла
/// </returns>
int filePrefix()
{
	std::cout << "Enter file prefix\n";

	int pref;
	if (!(std::cin >> pref))
		throw std::string("File prefix must be integer\n");

	return pref;
}