#include <Windows.h>
#include "convert.h"
#include <iostream>


std::string Utf8_to_cp1251(const char* str)
{
	std::string res;
	int result_u, result_c;

	result_u = MultiByteToWideChar(CP_UTF8, 0, str, -1, 0, 0);

	if (!result_u) { std::cerr << "Cannot convert to utf-16\n"; abort(); }

	wchar_t* ures = new wchar_t[result_u];

	if (!MultiByteToWideChar(CP_UTF8, 0, str, -1, ures, result_u))
	{
		delete[] ures;
		return 0;
	}


	result_c = WideCharToMultiByte(1251, 0, ures, -1, 0, 0, 0, 0);

	if (!result_c)
	{
		delete[] ures;
		return 0;
	}

	char* cres = new char[result_c];

	if (!WideCharToMultiByte(1251, 0, ures, -1, cres, result_c, 0, 0))
	{
		delete[] cres;
		return 0;
	}

	delete[] ures;
	res.append(cres);

	delete[] cres;
	return res;
}

std::string Cp1251_to_utf8(const char* str)
{
	std::string res;
	int result_u, result_c;

	result_u = MultiByteToWideChar(1251, 0, str, -1, 0, 0);

	if (!result_u) { std::cerr << "Cannot convert to utf-16\n"; abort(); }

	wchar_t* ures = new wchar_t[result_u];

	if (!MultiByteToWideChar(1251, 0, str, -1, ures, result_u))
	{
		delete[] ures;
		return 0;
	}


	result_c = WideCharToMultiByte(CP_UTF8, 0, ures, -1, 0, 0, 0, 0);

	if (!result_c)
	{
		delete[] ures;
		return 0;
	}

	char* cres = new char[result_c];

	if (!WideCharToMultiByte(CP_UTF8, 0, ures, -1, cres, result_c, 0, 0))
	{
		delete[] cres;
		return 0;
	}

	delete[] ures;
	res.append(cres);

	delete[] cres;
	return res;
}