#include <iostream>
#include "dyn_arr.h"


inline void printArr(dynIntArr dynArr)
{
	for (int i = 0; i < dynArr.len; ++i)
		cout << dynArr.arr[i] << " ";

	cout << "\n";
}

inline void printArr(dynCharArr dynArr)
{
	for (int i = 0; i < dynArr.len; ++i)
		cout << dynArr.arr[i] << " ";

	cout << "\n";
}
