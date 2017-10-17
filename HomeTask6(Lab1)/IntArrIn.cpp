#include <iostream>
#include <fstream>
#include "dyn_arr.h"
#include "Input.h"

using namespace std;

inline dynIntArr readIntStream(istream &input)
{
	dynIntArr arr;

	if (!(input >> arr.len))
		throw new exception;

	arr.arr = new int[arr.len];
	for (int i = 0; i < arr.len; ++i)
		input >> arr.arr[i];

	return arr;
}

inline dynIntArr fileReadInt(string fileName)
{
	ifstream input(fileName);
	return readIntStream(input);
}

inline dynIntArr consoleReadInt()
{
	cout << "Enter array len, then values ";
	return readIntStream(cin);
}

inline dynIntArr readIntArr()
{
	if (isConcoleRead())
		return consoleReadInt();

	return fileReadInt(FILE_NAME);
}
