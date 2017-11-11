#include "dyn_arr.h"
#include <algorithm>

inline void swap(int arr[], int i, int j)
{
	int prom = arr[i];
	arr[i] = arr[j];
	arr[j] = prom;
}

dynIntArr posAndNegArrOrg(dynIntArr arr)
{
	int l = 0;
	int r = arr.len - 1;
	while (l < r)
	{
		for (; l < r && arr.arr[l] < 0; ++l) {}

		for (; l < r && arr.arr[r] >= 0; --r) {}

		if (arr.arr[l] >= 0 && arr.arr[r] < 0)
		{
			swap(arr.arr, l, r);
			l++;
			r--;
		}
	}

	return arr;
}

inline dynCharArr fillEndOfArr(dynCharArr arr, dynCharArr fullArr, int startPos)
{
	for (int i = startPos; i < fullArr.len; ++i)
		arr.arr[startPos + i] = fullArr.arr[i];

	return arr;
}
 
inline dynCharArr fillEqualLenPart(dynCharArr arr, dynCharArr arrA, dynCharArr arrB)
{
	int i = 0;
	int iRes = 0;
	while (i < std::min(arrA.len, arrB.len))
	{
		arr.arr[iRes] = arrA.arr[i];
		iRes++;
		arr.arr[iRes] = arrB.arr[i];
		iRes++;
		i++;
	}

	return arr;
}

dynCharArr stringUnite(dynCharArr arrA, dynCharArr arrB)
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