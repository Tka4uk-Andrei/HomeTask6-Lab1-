#pragma once

#include <iostream>
#include "dyn_arr.h"
#include <fstream>
#include <string>
#include "fileNames.h"

using namespace std;

/// <summary>
/// ������ �������� ������ ����������� ���-�� �
/// �������� ������������� ��������� �������
/// </summary>
/// <param name="input">����� �����</param>
/// <returns>
/// ��������� ���������� ���������� � ����� � ��������� ��������� �������
/// </returns>
inline dynCharArr readCharStream(istream& input)
{
	dynCharArr arr;

	arr.arr = new char[100];

	if (!(input >> arr.arr))
		throw string( "char array read error\n" );

	arr.len = strlen(arr.arr);

	return arr;
}

/// <summary>
/// ������ �� ����� � �������� ������, �������
/// ����� �������� ���-�� � �������� ������������� ��������� �������
/// </summary>
/// <param name="fileName">��� ����� ��� ����������</param>
/// <returns>
/// ���������� ��������� ���������� ������ �� 
/// ����������� ������ � ���������� ��������� � ��
/// </returns>
inline dynCharArrPair fileReadChar(string fileName)
{
	dynCharArrPair arrPair;
	ifstream input( fileName );

	if (!input.is_open())
		throw string( "File \"" + fileName + "\" doesn't exist\n" );

	try
	{
		arrPair.arr1 = readCharStream( input );
		arrPair.arr2 = readCharStream( input );
	}
	catch (string errStr)
	{
		cout << "File \"" << fileName << "\" is currupted\n";
		throw errStr;
	}

	input.close();

	return arrPair;
}

/// <summary>
/// ������ �� ����� � ��������������� �������� �������� ����� �����.
/// ���������� �� ���������� �������: 
/// ���-�� ���������, ����� �������� ��������
/// </summary>
/// <returns>
/// ��������� ���������� ������ �� 
/// ����������� �������� ������ � ���������� ��������� � ��
/// </returns>
dynCharArrPair readCharArr()
{
	auto pref = filePrefix();
	dynCharArrPair arr = fileReadChar( to_string( pref ) + INPUT_SECOND_FILE_NAME);
	return arr;
}