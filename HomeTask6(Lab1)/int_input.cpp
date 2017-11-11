#pragma once

#include <iostream>
#include "dyn_arr.h"
#include <string>
#include <fstream>
#include "fileNames.h"

using namespace std;

inline dynIntArr readIntStream(istream& input)
{
	dynIntArr arr;

	if (!(input >> arr.len) || !(arr.len > 0))
		throw string( "Value must be positive integer\n" );

	arr.arr = new int[arr.len];
	for (int i = 0; i < arr.len; ++i)
		if (!(input >> arr.arr[i]))
			throw string( "Values must be integers\n" );

	return arr;
}

inline dynIntArr fileReadInt(string fileName)
{
	ifstream input( fileName );

	if (!input.is_open())
		throw string( "couldn't find file \"" + fileName + "\"\n" );

	dynIntArr ans;

	try
	{
		ans = readIntStream( input );
	}
	catch (string errStr)
	{
		cout << "File \"" << fileName << "\" is currupted\n";
		throw errStr;
	}

	input.close();

	return ans;
}

dynIntArr readIntArr()
{
	dynIntArr arr;
	auto pref = filePrefix();
	arr = fileReadInt( to_string( pref ) + INPUT_FIRST_FILE_NAME );
	return arr;
}
