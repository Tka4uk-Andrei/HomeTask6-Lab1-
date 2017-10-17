#include "dyn_arr.h"
#include <algorithm>

inline dynCharArr fillEndOfArr(dynCharArr arr, dynCharArr fullArr,  int startPos)
{
	for (int i = startPos; i < arr.len; ++i)
		arr.arr[i] = fullArr.arr[i];

	return arr;
}

inline dynCharArr fillEqualLenPart(dynCharArr arr, dynCharArr arrA, dynCharArr arrB)
{
	int i = 0;
	int iRes = 0;
	while (i < min(arrA.len, arrB.len))
	{
		arr.arr[iRes] = arrA.arr[i];
		iRes++;
		arr.arr[iRes] = arrB.arr[i];
		iRes++;
		i++;
	}

	return arr;
}

inline dynCharArr stringUnite(dynCharArr arrA, dynCharArr arrB)
{
	dynCharArr resArr;
	resArr.len = arrA.len + arrB.len;
	resArr.arr = new char[resArr.len];

	resArr = fillEqualLenPart(resArr, arrA, arrB);

	if (arrA.len > arrB.len)
		resArr = fillEndOfArr(resArr, arrA, arrB.len);
	else
		resArr = fillEndOfArr(resArr, arrB, arrA.len);

	return resArr;
}