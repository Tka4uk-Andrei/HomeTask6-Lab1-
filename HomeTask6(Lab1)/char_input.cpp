#pragma once

#include <iostream>
#include "dyn_arr.h"
#include <fstream>
#include <string>
#include "fileNames.h"

using namespace std;

/// <summary>
/// Чтение входного потока содержащего кол-во и
/// значения целочисленных элементов массива
/// </summary>
/// <param name="input">Поток ввода</param>
/// <returns>
/// Стурктуру содержащую информацию о длине и значениях элементов массива
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
/// Чтение из файла с заданным именем, который
/// также содержит кол-во и значения целочисленных элементов массива
/// </summary>
/// <param name="fileName">Имя файла для считывания</param>
/// <returns>
/// Возвращает структуру содержащую ссылку на 
/// заполненный массив и количество элементов в нём
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
/// Чтение из файла с предварительным запросом префикса имени файла.
/// Считывание по следующему правилу: 
/// кол-во элементов, затем значения символов
/// </summary>
/// <returns>
/// Структуру содержащую ссылку на 
/// заполненный сиволами массив и количество элементов в нём
/// </returns>
dynCharArrPair readCharArr()
{
	auto pref = filePrefix();
	dynCharArrPair arr = fileReadChar( to_string( pref ) + INPUT_SECOND_FILE_NAME);
	return arr;
}