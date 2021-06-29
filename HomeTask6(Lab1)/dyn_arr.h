#pragma once

/// <summary>
/// ��������� ���������� ����� � ������
/// �� ������ ������� �������������� �������
/// </summary>
struct dynIntArr
{
	int len;
	int* arr;
};

/// <summary>
/// ��������� ���������� ����� � ������
/// �� ������ ������� ����������� �������
/// </summary>
struct dynCharArr
{
	int len;
	char* arr;
};

/// <summary>
/// ��������� ���������� ��� dynCharArr
/// </summary>
struct dynCharArrPair
{
	dynCharArr arr1;
	dynCharArr arr2;
};