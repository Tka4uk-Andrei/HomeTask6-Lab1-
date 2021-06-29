#pragma once

/// <summary>
/// Структура содержащая длину и ссылку
/// на первый элемент целочисленного массива
/// </summary>
struct dynIntArr
{
	int len;
	int* arr;
};

/// <summary>
/// Структура содержащая длину и ссылку
/// на первый элемент символьного массива
/// </summary>
struct dynCharArr
{
	int len;
	char* arr;
};

/// <summary>
/// Структура содержащяя два dynCharArr
/// </summary>
struct dynCharArrPair
{
	dynCharArr arr1;
	dynCharArr arr2;
};