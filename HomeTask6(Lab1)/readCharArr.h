#pragma once
#include "dyn_arr.h"
#include "consoleReadChar.h"
#include "filereadChar.h"
#include "fileNames.h"
#include "readType.h"

inline dynCharArr* readCharArr(int count)
{
	dynCharArr *arr = new dynCharArr[count];

	switch (getReadType())
	{
		case console:
		break;

		case file:
		break;

		case random:
		break;
	}

	for (int i = 0; i < count; ++i)
		arr[i] = consoleReadChar();

	for (int i = 0; i < count; ++i)
		arr[i] = fileReadChar(INPUT_FILE_NAME, count); // dosen't work
		
	return arr;
}