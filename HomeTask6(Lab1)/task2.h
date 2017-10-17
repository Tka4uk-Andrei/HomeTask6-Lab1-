#pragma once
#include "dyn_arr.h"

inline dynCharArr stringUnite(dynCharArr arrA, dynCharArr arrB)
{
	dynCharArr resArr;
	resArr.len = arrA.len + arrB.len;
	resArr.arr = new char[resArr.len];

	int iA = 0;
	int iB = 0;
	int iRes = 0;
	while (iA < arrA.len || iB <arrB.len)
	{
		if (iA < arrA.len)
		{
			resArr.arr[iRes] = arrA.arr[iA];
			iRes++;
			iA++;
		}

		if (iB < arrB.len)
		{
			resArr.arr[iRes] = arrB.arr[iB];
			iRes++;
			iB++;
		}
	}

	return resArr;
}