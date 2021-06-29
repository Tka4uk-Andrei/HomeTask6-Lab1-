#pragma once

template<class T>

/// <summary>
/// Вывод данных массива в структуре через консоль
/// </summary>
/// <param name="dynArr">
/// Структура содержащая поля длины и 
/// ссылки на первый элемент массива
/// </param>
void printArr(T dynArr)
{
	for (int i = 0; i < dynArr.len; ++i)
		std::cout << dynArr.arr[i] << " ";

	std::cout << "\n";
}