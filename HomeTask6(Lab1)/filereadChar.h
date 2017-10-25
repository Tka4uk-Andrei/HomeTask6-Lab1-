#include <fstream>
#include "dyn_arr.h"
#include "readCharStream.h"

using namespace std;

inline dynCharArrPair* fileReadChar(string fileName, int pairCount)
{
	ifstream input(fileName);

	dynCharArrPair* arr = new dynCharArrPair[pairCount];

	for (int j = 0; j < pairCount; ++j)
	{
		arr[j].arr1 = readCharStream(input);
		arr[j].arr2 = readCharStream(input);
	}

	return arr;
}