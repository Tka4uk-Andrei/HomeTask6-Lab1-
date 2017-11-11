#pragma once

#include <iostream>
#include "dyn_arr.h"
#include <fstream>
#include <string>
#include "fileNames.h"

using namespace std;

inline dynCharArr readCharStream(istream& input)
{
	dynCharArr arr;

	if (!(input >> arr.len) || !(arr.len > 0))
		throw string( "char array lenght read error\n" );

	arr.arr = new char[arr.len];
	for (int i = 0; i < arr.len; ++i)
		if (!(input >> arr.arr[i]))
			throw string( "char array read error\n" );

	return arr;
}

inline dynCharArrPair fileReadChar(string fileName)
{
	dynCharArrPair arrPair;
	ifstream input( fileName );

	if (!input.is_open())
		throw string( "File doesn't exist \"" + fileName + "\"\n" );

	try
	{
		arrPair.arr1 = readCharStream( input );
		arrPair.arr2 = readCharStream( input );
	}
	catch (string errStr)
	{
		cout << "File \"" << fileName << "\" is currupted\n";
		throw errStr;
	}

	input.close();

	return arrPair;
}

dynCharArrPair readCharArr()
{
	auto pref = filePrefix();
	dynCharArrPair arr = fileReadChar( to_string( pref ) + INPUT_SECOND_FILE_NAME);
	return arr;
}
