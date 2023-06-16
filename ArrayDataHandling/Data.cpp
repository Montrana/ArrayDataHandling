#include "Data.h"

/// <summary>
/// Reads in the file with the integers that will become the array
/// </summary>
/// <param name="arr">The array the integers will be pushed into</param>
/// <param name="infile">the file name that the integers are in</param>
/// <param name="count">the count of integers that are in the array</param>
void inFile(int* arr[], string infile, int& count)
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
			count++;
		}
	}
	else
	{
		throw runtime_error("Could not open file: " + infile);
	}
	fin.close();
}

/// <summary>
/// Searches the array for a number, returns if it was found, and if found, the index as well
/// </summary>
/// <param name="arr">the array to search through</param>
/// <param name="num">the number to search for</param>
/// <param name="index">the index of the number if it was found</param>
/// <returns>if the number was found or not</returns>
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

/// <summary>
/// replaces one value with a different value
/// </summary>
/// <param name="arr">the array that gets altered</param>
/// <param name="num">the new number</param>
/// <param name="index">the index that gets replaced</param>
void replace(int* arr[], int num, int index)
{
	*arr[index] = num;
}

/// <summary>
/// appends a number to the end of the array
/// </summary>
/// <param name="arr">the array to alter</param>
/// <param name="num">the number that will be appended</param>
void append(int* arr[], int num)
{
	int i = 0;
	while (arr[i] != nullptr)
	{
		i++;
	}
	arr[i] = new int(num);
}

/// <summary>
/// deletes a number from the array
/// </summary>
/// <param name="arr">the array to alter</param>
/// <param name="index">the index to delete</param>
void del(int* arr[], int index)
{
	for (int i = index; arr[i] != nullptr; i++)
	{
		arr[i] = arr[i + 1];
	}
}

/// <summary>
/// prints the array
/// </summary>
/// <param name="arr">the array to print</param>
void print_array(int* arr[])
{
	for (int i = 0; i < Max_Arr_Length; i++)
	{
		if (arr[i] != nullptr)
		{
			cout << i << ": " << *arr[i] << endl;
		}
		else
		{
			cout << i << ": NULL" << endl;
		}
	}
}

/// <summary>
/// Takes input from the user for an index and verifies that it is correct
/// </summary>
/// <param name="statement">output statement that asks user to input an index</param>
/// <param name="count">the amount of numbers in the array</param>
/// <returns>the index that was inputted</returns>
int indexInput(string statement, int count)
{
	int index;
	do {
		cout << statement;
		cin >> index;
		if (cin.fail())
		{
			throw runtime_error("INPUT WAS NOT A NUMBER");
		}
		else if (index < 0 || index > count - 1)
		{
			cout << "That index is invalid. Please use another index.\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (index < 0 || index > count - 1);
	/// verifying user inputs instead of using a try block because according to this forum it wouldn't catch a Access Violation Exception
	/// https://stackoverflow.com/questions/24739986/catching-c-access-violation-writing-exception
	return index;
}