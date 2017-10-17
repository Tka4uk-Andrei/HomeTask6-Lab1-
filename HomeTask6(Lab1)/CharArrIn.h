#include <string>
#include <iostream>
#include <fstream>
#include "dyn_arr.h"
#include "Input.h"

using namespace std;

// array count refactor

inline dynCharArr* readCharStream(istream &input, int count)
{
	dynCharArr* arr = new dynCharArr[count];

	for (int j = 0; j < count; ++j)
	{
		input >> arr[j].len;
		arr[j].arr = new char[arr[j].len];
		for (int i = 0; i < arr[j].len; ++i)
			input >> arr[j].arr[i];
	}
	return arr;
}

inline dynCharArr fileReadChar(string fileName, int count)
{
	ifstream input(fileName);
	return readCharStream(input, 1)[0];
}

inline dynCharArr consoleReadChar()
{
	cout << "Enter array len, then values";
	return readCharStream(cin, 1)[0];
}

inline dynCharArr* readCharArr(int count)
{
	dynCharArr *arr = new dynCharArr[count];

	if (isConcoleRead())
		for (int i = 0; i < count; ++i)
			arr[i] = consoleReadChar();
	else
		for (int i = 0; i < count; ++i)
			arr[i] = fileReadChar(FILE_NAME, count); // dosen't work

	return arr;
}