#pragma once
#include "dyn_arr.h"
#include "consoleReadChar.h"
#include "filereadChar.h"
#include "fileNames.h"
#include "readType.h"
#include "fileReadType.h"
#include "fileReadInt.h"
#include <string>

inline dynCharArrPair* readCharArr(int& count)
{
	switch (getReadType())
	{
	case console:
		count = 1;
		return consoleReadChar( count );

	case file:
		if (isStandartRead())
		{
			count = 1;
			auto arr = fileReadChar( INPUT_SECOND_FILE_NAME, 1 );

			return arr;
		}

		auto pref = filePrefixes();

		count = pref.len;
		auto arr = new dynCharArrPair[count];
		for (int i = 0; i < pref.len; ++i)
			arr[i] = fileReadChar( to_string( pref.arr[i] ) + INPUT_SECOND_FILE_NAME, 1 )[0];

		delete[] pref.arr;

		return arr;
	}
	return nullptr;
}
