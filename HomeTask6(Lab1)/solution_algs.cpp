#include "dyn_arr.h"
#include <algorithm>

/// <summary>
/// ������ ��� �������� ������� �������
/// </summary>
/// <param name="arr">������</param>
/// <param name="i">i - �������</param>
/// <param name="j">j - �������</param>
inline void swap(int arr[], int i, int j)
{
	int prom = arr[i];
	arr[i] = arr[j];
	arr[j] = prom;
}

/// <summary>
/// ���������� ������. ������� ������������� �����, ����� ��� ����������.
/// </summary>
/// <param name="arr"></param>
/// <returns>���������� �������������� �� ������� ������.</returns>
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
/// ��������� ������� �� ����� ������ ������ �������
/// </summary>
/// <param name="arr">������ ��������� ����������</param>
/// <param name="fullArr">������, ������� ��������� arr</param>
/// <param name="startPos">� ����� ������� ��������� � �������� �����������</param>
/// <returns>���������� ������</returns>
 dynCharArr fillEndOfArr(dynCharArr arr, dynCharArr fullArr, int startPos)
{
	for (int i = startPos; i < fullArr.len; ++i)
		arr.arr[startPos + i] = fullArr.arr[i];

	return arr;
}
 
 /// <summary>
 /// ��������� ������ ������ �� ��� ��� ���� 
 /// �� �������� ���� �� ���� ��������� �� �������
 /// a[0] b[0] a[1] b[1] ... a[A_LEN] b[A_LEN]
 /// </summary>
 /// <param name="arr">������ ��������� ����������</param>
 /// <param name="arrA">������ 1 � �������� ������������� �����������</param>
 /// <param name="arrB">������ 2 � �������� ������������� �����������</param>
 /// <returns>
 /// ���������� ����������� ������ arr
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
/// ���������� ��� char ������� � ���� �� ������� 
/// a[0] b[0] a[1] b[1] ... a[A_LEN] b[A_LEN] b[A_LEN + 1] ... b[B_LEN]
/// </summary>
/// <param name="arrA">�������� arrA</param>
/// <param name="arrB">�������� arrB</param>
/// <returns>
/// ���������� �������������� ������
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