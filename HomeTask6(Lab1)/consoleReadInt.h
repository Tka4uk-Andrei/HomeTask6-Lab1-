#pragma once

#include "readIntStream.h"
#include <string>

inline dynIntArr* consoleReadInt()
{
	auto arr = new dynIntArr[1];
	for (int i = 0; i < 1; ++i)
	{
		cout << "Enter array len, then values ";

		arr[i] = readIntStream( cin );
	}

	return arr;
}