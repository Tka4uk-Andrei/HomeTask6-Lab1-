#pragma once

struct dynIntArr
{
	int len;
	int* arr;
};

struct dynCharArr
{
	int len;
	char* arr;
};

struct dynCharArrPair
{
	dynCharArr arr1;
	dynCharArr arr2;
};