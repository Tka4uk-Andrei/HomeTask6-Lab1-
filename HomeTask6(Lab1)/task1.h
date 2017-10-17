#include "dyn_arr.h"

inline void swap(int arr[], int i, int j)
{
	int prom = arr[i];
	arr[i] = arr[j];
	arr[j] = prom;
}

inline dynIntArr posAndNegArrOrg(dynIntArr arr)
{
	int l = 0;
	int r = arr.len - 1;
	while (l < r)
	{
		for (;l < r && arr.arr[l] < 0; ++l)

		for (;l < r && arr.arr[r] >= 0; --r)

		if (arr.arr[l] >= 0 && arr.arr[r] < 0)
		{
			swap(arr.arr, l, r);
			l++;
			r--;
		}
	}

	return arr;
}