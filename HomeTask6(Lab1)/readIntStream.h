#pragma once

#include <iostream>
#include "dyn_arr.h"

using namespace std;

inline dynIntArr readIntStream(istream &input)
{
	dynIntArr arr;

	if (!(input >> arr.len))
		throw new exception;

	arr.arr = new int[arr.len];
	for (int i = 0; i < arr.len; ++i)
		input >> arr.arr[i];

	return arr;
}