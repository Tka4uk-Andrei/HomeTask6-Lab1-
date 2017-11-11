#include <iostream>
#include "Output.h"
#include "solution_algs.h"
#include "Input.h"
#include "dyn_arr.h"

using namespace std;

void printTaskNum(int num)
{
	cout << "------\n";
	cout << "Task " << num << "\n";
	cout << "------\n";
}

void executeTask1()
{
	printTaskNum(1);

	dynIntArr arr;
	arr = readIntArr();

	printArr(posAndNegArrOrg(arr));
	delete[] arr.arr;
}

void executeTask2()
{
	printTaskNum(2);

	auto arrCharPar = readCharArr();

	auto prom = stringUnite(arrCharPar.arr1, arrCharPar.arr2);
	printArr(prom);
	std::cout << "\n";

	delete[] prom.arr;
	delete[] arrCharPar.arr1.arr;
	delete[] arrCharPar.arr2.arr;
}