#pragma once

#include <iostream>
#include "dyn_arr.h"
#include "readCharStream.h"

using namespace std;

inline dynCharArrPair* consoleReadChar(int pairCount)
{
	dynCharArrPair* dynArr = new dynCharArrPair[pairCount];

	for (int j = 0; j < pairCount; ++j)
	{
		cout << "Enter array len, then values ";
		dynArr[j].arr1 = readCharStream(cin);
		cout << "Enter array len, then values ";
		dynArr[j].arr2 = readCharStream(cin);
	}

	return dynArr;
}

