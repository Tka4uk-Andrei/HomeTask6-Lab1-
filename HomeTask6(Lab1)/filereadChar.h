#pragma once
#include <fstream>
#include "readCharStream.h"
#include "dyn_arr.h"

using namespace std;

inline dynCharArr fileReadChar(string fileName, int count)
{
	ifstream input(fileName);
	return readCharStream(input, 1)[0];
}