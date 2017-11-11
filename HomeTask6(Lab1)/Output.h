template<class T>
void printArr(T dynArr)
{
	for (int i = 0; i < dynArr.len; ++i)
		std::cout << dynArr.arr[i] << " ";

	std::cout << "\n";
}