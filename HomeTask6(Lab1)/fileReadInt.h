#pragma once

#include "readIntStream.h"

inline dynIntArr fileReadInt(string fileName)
{
	ifstream input(fileName);
	return readIntStream(input);
}