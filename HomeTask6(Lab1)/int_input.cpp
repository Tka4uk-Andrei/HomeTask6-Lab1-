#pragma once

#include <iostream>
#include "dyn_arr.h"
#include <string>
#include <fstream>
#include "fileNames.h"

using namespace std;

/// <summary>
/// Читает поток по следующему правилу: 
/// кол-во элементов затем их целочисленные значения
/// </summary>
/// <param name="input">Поток для чтения</param>
/// <returns>
/// Структуру содержащую ссылку на 
/// массив и количество элементов в нём
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
/// Чтение из файла с заданным именем.
/// Считывание по следующему правилу: 
/// кол-во элементов затем их целочисленные значения
/// </summary>
/// <param name="fileName">Имя файла</param>
/// <returns>
/// Структуру содержащую ссылку на 
/// заполненный массив и количество элементов в нём
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
/// Чтение из файла с предварительным запросом префикса имени файла.
/// Считывание по следующему правилу: 
/// кол-во элементов затем их целочисленные значения
/// </summary>
/// <returns>
/// Структуру содержащую ссылку на 
/// заполненный целыми числами массив и количество элементов в нём
/// </returns>
dynIntArr readIntArr()
{
	dynIntArr arr;
	auto pref = filePrefix();
	arr = fileReadInt( to_string( pref ) + INPUT_FIRST_FILE_NAME );
	return arr;
}