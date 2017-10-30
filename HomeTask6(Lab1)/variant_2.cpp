#include <iostream>
#include "InOut.h"
#include "task1.h"
#include "task2.h"

using namespace std;

void printTaskNum(int num)
{
	cout << "------\n";
	cout << "Task " << num << "\n";
	cout << "------\n";
}

void executeTask1()
{
	int count;

	// array that contains arrays
	dynIntArr* arr;

	arr = readIntArr(count);

	for (int i = 0; i < count; ++i)
	{
		printArr(posAndNegArrOrg(arr[i]));
		delete[] arr[i].arr;
	}
}

void executeTask2()
{
	int count;

	auto arrCharPar = readCharArr(count);

	for (int i = 0; i < count; ++i)
	{
		auto prom = stringUnite(arrCharPar[i].arr1, arrCharPar[i].arr2);
		printArr(prom);

		delete[] prom.arr;
		delete[] arrCharPar[i].arr1.arr;
		delete[] arrCharPar[i].arr2.arr;

		cout << "\n";
	}

	delete[] arrCharPar;
}

int main()
{
	printTaskNum(1);

	try
	{
		executeTask1();
	}
	catch (string errStr)
	{
		cout << errStr << "\n";
		cout << "closing programm..." << endl;
		return 0;
	}
	
	printTaskNum(2);
	
	try
	{
		executeTask2();
	}
	catch (string errStr)
	{
		cout << errStr << "\n";
		cout << "closing programm..." << endl;
		return 0;
	}

	return 0;
}