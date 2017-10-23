#pragma once

#include <iostream>
#include "dyn_arr.h"
#include "readCharStream.h"

using namespace std;

inline dynCharArr* consoleReadChar(int count)
{
	dynCharArr* dynArr = new dynCharArr[count];

	for (int i = 0; i < count; ++i) {
		cout << "Enter array len, then values";
		dynArr[i] = readCharStream(cin, 1)[0];
	}

	return dynArr;
}

