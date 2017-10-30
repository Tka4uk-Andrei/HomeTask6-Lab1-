#pragma once

#include "readIntStream.h"
#include <fstream>

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
