#pragma once
#include "consoleReadInt.h"
#include "fileReadInt.h"
#include <string>

inline dynIntArr* readIntArr(int& count)
{
	switch (getReadType())
	{
	case console:
		count = 1;
		return consoleReadInt();
	case file:
		if (isStandartRead())
		{
			count = 1;
			auto arr = new dynIntArr[count];
			arr[0] = fileReadInt( INPUT_FIRST_FILE_NAME );

			return arr;
		}

		auto pref = filePrefixes();
		count = pref.len;
		auto arr = new dynIntArr[count];

		for (int i = 0; i < pref.len; ++i)
			arr[i] = fileReadInt( to_string( pref.arr[i] ) + INPUT_FIRST_FILE_NAME );

		delete[] pref.arr;

		return arr;
	}
	return nullptr;
}
