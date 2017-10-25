#include <iostream>
#include "InOut.h"
#include "task1.h"
#include "task2.h"

using namespace std;

int main()
{
	cout << "------\n";
	cout << "Task 1\n";
	cout << "------\n";

	int count;

	auto arr = readIntArr(count);
	for (int i = 0; i < count; ++i)
	{
		try
		{
			printArr(posAndNegArrOrg(arr[i]));
		}
		catch (string errStr)
		{
			cout << errStr;
			return 0;
		}
		delete[] arr[i].arr;
	}
	
	cout << "------\n";
	cout << "Task 2\n";
	cout << "------\n";

	auto arrChar = readCharArr(count);

	for (int i = 0; i < count; ++i)
	{
		auto prom = stringUnite(arrChar[i].arr1, arrChar[i].arr2);
		printArr(prom);

		delete[] prom.arr;
	 	delete[] arrChar[i].arr1.arr;
		delete[] arrChar[i].arr2.arr;

		cout << "\n";
	}

	delete[] arrChar;

	return 0;
}