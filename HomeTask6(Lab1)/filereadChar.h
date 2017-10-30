#include <fstream>
#include <string>
#include "dyn_arr.h"
#include "readCharStream.h"

using namespace std;

inline dynCharArrPair* fileReadChar(string fileName, int pairCount)
{
	ifstream input(fileName);

	if (!input.is_open())
		throw string("File doesn't exist \"" + fileName + "\"\n");

	dynCharArrPair* arr = new dynCharArrPair[pairCount];

	for (int j = 0; j < pairCount; ++j)
	{
		try
		{
			arr[j].arr1 = readCharStream(input);
			arr[j].arr2 = readCharStream(input);
		}
		catch (string errStr)
		{
			cout << "File \"" << fileName << "\" is currupted\n";
			throw errStr;
		}
	}

	input.close();

	return arr;
}