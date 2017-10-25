#pragma once

#include <iostream>
#include "dyn_arr.h"

using namespace std;

inline dynCharArr readCharStream(istream &input)
{
	dynCharArr arr;
	input >> arr.len;
	arr.arr = new char[arr.len];
	for (int i = 0; i < arr.len; ++i)
		input >> arr.arr[i];

	return  arr;
}