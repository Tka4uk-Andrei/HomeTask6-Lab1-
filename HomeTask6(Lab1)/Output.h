#pragma once

template<class T>

/// <summary>
/// ����� ������ ������� � ��������� ����� �������
/// </summary>
/// <param name="dynArr">
/// ��������� ���������� ���� ����� � 
/// ������ �� ������ ������� �������
/// </param>
void printArr(T dynArr)
{
	for (int i = 0; i < dynArr.len; ++i)
		std::cout << dynArr.arr[i] << " ";

	std::cout << "\n";
}