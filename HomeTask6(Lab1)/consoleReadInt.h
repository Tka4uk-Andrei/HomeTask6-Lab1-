#pragma once

#include "readIntStream.h"

inline dynIntArr consoleReadInt()
{
	cout << "Enter array len, then values ";
	return readIntStream(cin);
}