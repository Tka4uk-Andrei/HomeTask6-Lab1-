#pragma once

template<class T>

/// <summary>
/// ¬ывод данных массива в структуре через консоль
/// </summary>
/// <param name="dynArr">
/// —труктура содержаща€ пол€ длины и 
/// ссылки на первый элемент массива
/// </param>
void printArr(T dynArr)
{
	for (int i = 0; i < dynArr.len; ++i)
		std::cout << dynArr.arr[i] << " ";

	std::cout << "\n";
}