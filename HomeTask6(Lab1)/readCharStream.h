#pragma once

#include <iostream>
#include "dyn_arr.h"

using namespace std;

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