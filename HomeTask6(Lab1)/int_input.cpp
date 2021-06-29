#pragma once

#include <iostream>
#include "dyn_arr.h"
#include <string>
#include <fstream>
#include "fileNames.h"

using namespace std;

/// <summary>
/// ������ ����� �� ���������� �������: 
/// ���-�� ��������� ����� �� ������������� ��������
/// </summary>
/// <param name="input">����� ��� ������</param>
/// <returns>
/// ��������� ���������� ������ �� 
/// ������ � ���������� ��������� � ��
/// </returns>
inline dynIntArr readIntStream(istream& input)
{
	dynIntArr arr;

	if (!(input >> arr.len))
		throw string("File is empty\n");

	if (!(arr.len > 0))
		throw string( "Value must be positive integer\n" );

	arr.arr = new int[arr.len];
	for (int i = 0; i < arr.len; ++i)
		if (!(input >> arr.arr[i]))
			throw string( "Values must be integers\n" );

	return arr;
}

/// <summary>
/// ������ �� ����� � �������� ������.
/// ���������� �� ���������� �������: 
/// ���-�� ��������� ����� �� ������������� ��������
/// </summary>
/// <param name="fileName">��� �����</param>
/// <returns>
/// ��������� ���������� ������ �� 
/// ����������� ������ � ���������� ��������� � ��
/// </returns>
inline dynIntArr fileReadInt(string fileName)
{
	ifstream input( fileName );

	if (!input.is_open())
		throw string( "couldn't find file \"" + fileName + "\"\n" );

	dynIntArr ans;

	try
	{
		ans = readIntStream( input );
	}
	catch (string errStr)
	{
		cout << errStr;
		throw string("File \"" + fileName + "\" maybe is corrupted\n");
	}

	input.close();

	return ans;
}

/// <summary>
/// ������ �� ����� � ��������������� �������� �������� ����� �����.
/// ���������� �� ���������� �������: 
/// ���-�� ��������� ����� �� ������������� ��������
/// </summary>
/// <returns>
/// ��������� ���������� ������ �� 
/// ����������� ������ ������� ������ � ���������� ��������� � ��
/// </returns>
dynIntArr readIntArr()
{
	dynIntArr arr;
	auto pref = filePrefix();
	arr = fileReadInt( to_string( pref ) + INPUT_FIRST_FILE_NAME );
	return arr;
}