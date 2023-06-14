#include "Data.h"

void inFile(int* arr[], string infile)
{
	ifstream fin(infile);
	if (fin.is_open())
	{
		int i = 0;
		int num;
		while (fin >> num)
		{
			arr[i] = new int(num);
			i++;
		}
	}
	else
	{
		throw runtime_error("Could not open file: " + infile);
	}
}

bool search(int* arr[], int num, int& index)
{
	for (int i = 0; arr[i] != nullptr; i++)
	{
		if (*arr[i] == num)
		{
			index = i;
			return true;
		}
	}
	return false;
}

void set_index(int* arr[], int num, int index)
{
	*arr[index] = num;
}

void append(int* arr[], int num)
{
	int i = 0;
	while (arr[i] != nullptr)
	{
		i++;
	}
	arr[i] = new int(num);
}

void del(int* arr[], int index)
{
	for (int i = index; arr[i] != nullptr; i++)
	{
		*arr[i] = *arr[i + 1];
	}
}
