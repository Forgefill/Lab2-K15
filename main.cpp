#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include"functions.h"
;
int main()
{
	setlocale(LC_ALL, "rus");
	int pbl = 0, i = 0, swap, s = 0;
	char a = 0;
	char arr[200];
	std::fstream st;
	st.open("file2.txt");
	//
	while (!st.eof())
	{
		st >> arr;
		++pbl;
	}
	int* ascii = new int[pbl];
	char**pword = new char*[pbl];
	for (int j = 0; j < pbl; ++j)
	{
		*(pword + j) = new char[30];
	}
	st.close();
	//
	st.open("file2.txt");
	while (!st.eof())
	{
		st >> arr;
		Mstrcpy(pword[i], arr);
		ascii[i] = (int)arr[0];
		++i;
	}
	for (int i = 0; i < pbl; ++i)
	{
		std::cout << ascii[i] << "\t-\t" << pword[i] << "\n";
	}
	//
	for (int i = 0; i < pbl; ++i)
	{
		for (int j = 0; j < pbl; ++j)
		{
			if (ascii[i] > ascii[j])
			{
				s = 0;
				swap = ascii[j];
				ascii[j] = ascii[i];
				ascii[i] = swap;
				Mstrcpy(arr, pword[j]);
				Mstrcpy(pword[j], pword[i]);
				Mstrcpy(pword[i], arr);
			}
		}
	}
	st.close();
	//
	st.open("file2.txt");
	while (!st.eof())
	{
		st >> a;
		if (a == '.') s = INT_MAX;
	}
	if (s != INT_MAX)
	{
    std::cout << "We didn`t find point in text, Enter N";
	std::cin >> s;
    }
	//виведення в консоль і введення відсортованого тексту в файл
	std::cout << "\n";
	/*for (int i = 0; i < pbl; ++i)
	{
		std::cout << pword[i];
		if (i%s == 0)std::cout << '.';
		std::cout << '\t';
	}*/
	st.close();
	st.open("file2.txt");
		for (int i = 0; i < pbl; ++i)
		{
			st << pword[i];
			if (i%s == 0) st << '.'<<' ';
			st << '\t';
			if (i % 4 == 0) st << '\n';
		}
	st.close();
	//видалення динамічних масивів
	for (int i = 0; i < pbl; ++i)
	{
		delete[]pword[i];
	}
	delete[]pword;
	delete[]ascii;
	system("pause");
	return 0;
}