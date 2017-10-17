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

	printArr(posAndNegArrOrg(readIntArr()));

	cout << "------\n";
	cout << "Task 2\n";
	cout << "------\n";

	printArr(stringUnite(readCharArr(1)[0], readCharArr(1)[0]));

	return 0;
}
