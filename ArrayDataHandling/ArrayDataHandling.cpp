// ArrayDataHandling.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Developer: Montana Nicholson
// Date: June 10, 2023
// This project allows a user to input an array from a file and alter that array in several ways.
// The user can search for, replace, append, and delete numbers from the array as well as printing the array out.

#include "Data.h"

int main()
{
	int* arr[Max_Arr_Length]{};
	int count = 0;
	// Initializes the array to an array of null pointers
	for (int i = 0; i < Max_Arr_Length; i++)
	{
		arr[i] = nullptr;
	}
	string filename = "integers.txt";
	string inputChoice;
	inFile(arr, filename, count);
	print_array(arr);
	do
	{
		//cout << "Count: " << count << endl;

		// The list of choices the player has
		cout << "What would you like to do with this array?\n";
		cout << "(s)earch for a number\n";
		if (count > 0) // Makes sure that the user can't delete from the array if there are no values
		{
			cout << "(r)eplace a number\n";
		}
		if (count < Max_Arr_Length) // Makes sure that the user can't append to an array if the max size is hit
		{
			cout << "(a)ppend a number to the end of the array\n";
		}
		if (count > 0) // Makes sure that the user can't replace a value in the array if there are no values
		{
			cout << "(d)elete a number from the array\n";
		}
		cout << "(p)rint the array\n";
		cout << "(q)uit\n";
		cout << "Choice: ";
		cin >> inputChoice;
		inputChoice = tolower(inputChoice[0]);
		if (inputChoice == "s")
		{
			int num;
			int index;
			try {
				cout << "What number would you like to search for? ";
				cin >> num;
				if (cin.fail())
				{
					throw runtime_error("INPUT WAS NOT A NUMBER");
				}
				else
				{
					if (search(arr, num, index))
					{
						cout << "The number " << num << " was found at index " << index << ".\n";
					}
					else
					{
						cout << "The number " << num << " could not be found.\n";
					}
				}
			}
			catch (runtime_error err)
			{
				cout << "Error: " << err.what() << endl;
				cout << "Please try again.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		else if (inputChoice == "r" && count > 0)
		{
			int num;
			string output = "What index would you like to replace? ";
			try {
				int index = indexInput(output, count);
				cout << "What number would you like to put in index " << index << "? ";
				cin >> num;
				if (cin.fail())
				{
					throw runtime_error("INPUT WAS NOT A NUMBER");
				}
				else
				{
					replace(arr, num, index);
				}
			}
			catch (runtime_error err)
			{
				cout << "Error: " << err.what() << endl;
				cout << "Please try again.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		else if (inputChoice == "a" && count < Max_Arr_Length)
		{
			int num;
			try {
				cout << "What number would you like to append to the end of the array? ";
				cin >> num;
				if (cin.fail())
				{
					throw runtime_error("INPUT WAS NOT A NUMBER");
				}
				else
				{
					append(arr, num);
					count++;
				}
			}
			catch (runtime_error err)
			{
				cout << "Error: " << err.what() << endl;
				cout << "Please try again.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		else if (inputChoice == "d" && count > 0)
		{
			string output = "What is the index that you would like to delete? ";
			try
			{
				int index = indexInput(output, count);
				del(arr, index);
				count--;
			}
			catch (runtime_error err)
			{
				cout << "Error: " << err.what() << endl;
				cout << "Please try again.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		else if (inputChoice == "p")
		{
			print_array(arr);
		}
		else if (inputChoice == "q")
		{
			break;
		}
		else
		{
			cout << "That is not a valid option, please choose another option.\n";
		}
	} while (inputChoice != "q");
}