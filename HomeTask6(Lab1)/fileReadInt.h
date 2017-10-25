#pragma once

#include "readIntStream.h"
#include <fstream>

inline dynIntArr fileReadInt(string fileName)
{
	ifstream input(fileName);
	return readIntStream(input);
}