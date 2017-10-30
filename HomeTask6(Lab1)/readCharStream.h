#pragma once

#include <iostream>
#include "dyn_arr.h"

using namespace std;

inline dynCharArr readCharStream(istream &input)
{
	dynCharArr arr;

	if (!(input >> arr.len))
		throw "char array lenght read error\n";

	arr.arr = new char[arr.len];
	for (int i = 0; i < arr.len; ++i)
		if(!(input >> arr.arr[i]))
			throw "char array read error\n";

	return  arr;
}