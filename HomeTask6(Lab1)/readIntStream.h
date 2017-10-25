#pragma once

#include <iostream>
#include "dyn_arr.h"

using namespace std;

inline dynIntArr readIntStream(istream &input)
{
	dynIntArr arr;

	if (!(input >> arr.len) && !arr.len > 0)
		throw "Value must be positive integer";

	arr.arr = new int[arr.len];
	for (int i = 0; i < arr.len; ++i)
		if (!(input >> arr.arr[i]))
			throw "Values must be integers";

	return arr;
}