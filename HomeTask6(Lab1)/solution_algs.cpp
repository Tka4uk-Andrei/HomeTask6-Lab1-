#include "dyn_arr.h"
#include <algorithm>

/// <summary>
/// Меняет два элемента массива местами
/// </summary>
/// <param name="arr">массив</param>
/// <param name="i">i - элемент</param>
/// <param name="j">j - элемент</param>
inline void swap(int arr[], int i, int j)
{
	int prom = arr[i];
	arr[i] = arr[j];
	arr[j] = prom;
}

/// <summary>
/// Организует массив. Сначала отрицательные числа, потом все оставшиеся.
/// </summary>
/// <param name="arr"></param>
/// <returns>Возварщает сформированный по правилу массив.</returns>
dynIntArr posAndNegArrOrg(dynIntArr arr)
{
	int l = 0;
	int r = arr.len - 1;
	while (l < r)
	{
		for (; l < r && arr.arr[l] < 0; ++l) {}

		for (; l < r && arr.arr[r] >= 0; --r) {}

		if (arr.arr[l] >= 0 && arr.arr[r] < 0)
		{
			swap(arr.arr, l, r);
			l++;
			r--;
		}
	}

	return arr;
}

/// <summary>
/// Заполняет массива до конца другой частью массива
/// </summary>
/// <param name="arr">массив требующий заполнения</param>
/// <param name="fullArr">массив, который заполняет arr</param>
/// <param name="startPos">с какой позиции заполнять и начинать копирование</param>
/// <returns>заполненый массив</returns>
 dynCharArr fillEndOfArr(dynCharArr arr, dynCharArr fullArr, int startPos)
{
	for (int i = startPos; i < fullArr.len; ++i)
		arr.arr[startPos + i] = fullArr.arr[i];

	return arr;
}
 
 /// <summary>
 /// Заполняет первый массив до тех пор пока 
 /// не кончится один из двух следующих по правилу
 /// a[0] b[0] a[1] b[1] ... a[A_LEN] b[A_LEN]
 /// </summary>
 /// <param name="arr">Массив требующий заполнения</param>
 /// <param name="arrA">Массив 1 с которого производиться копирование</param>
 /// <param name="arrB">Массив 2 с которого производиться копирование</param>
 /// <returns>
 /// Возвращает заполненный массив arr
 /// </returns>
inline dynCharArr fillEqualLenPart(dynCharArr arr, dynCharArr arrA, dynCharArr arrB)
{
	int i = 0;
	int iRes = 0;
	while (i < std::min(arrA.len, arrB.len))
	{
		arr.arr[iRes] = arrA.arr[i];
		iRes++;
		arr.arr[iRes] = arrB.arr[i];
		iRes++;
		i++;
	}

	return arr;
}

/// <summary>
/// Объединяет два char массива в один по правилу 
/// a[0] b[0] a[1] b[1] ... a[A_LEN] b[A_LEN] b[A_LEN + 1] ... b[B_LEN]
/// </summary>
/// <param name="arrA">описание arrA</param>
/// <param name="arrB">описание arrB</param>
/// <returns>
/// Возвращает сформированный массив
/// </returns>
dynCharArr stringUnite(dynCharArr arrA, dynCharArr arrB)
{
	dynCharArr resArr;
	
	resArr.len = arrA.len + arrB.len;
	resArr.arr = new char[resArr.len + 1];

	resArr = fillEqualLenPart(resArr, arrA, arrB);

	if (arrA.len > arrB.len)
		resArr = fillEndOfArr(resArr, arrA, arrA.len);
	else
		resArr = fillEndOfArr(resArr, arrB, arrA.len);

	resArr.arr[resArr.len] = '\0';

	return resArr;
}