#include <iostream>
#include <string>
#include "task_execution.h"

using namespace std;

int main()
{
	try
	{
		executeTask1();
		executeTask2();
	}
	catch (string errStr)
	{
		cout << errStr << '\n';
		cout << "Program is closing." << endl;
		return 0;
	}

	return 0;
}