#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int Max_Arr_Length = 15;// The maximum array length

/// <summary>
/// Reads in the file with the integers that will become the array
/// </summary>
/// <param name="arr">The array the integers will be pushed into</param>
/// <param name="infile">the file name that the integers are in</param>
/// <param name="count">the count of integers that are in the array</param>
void inFile(int* arr[], string infile, int& count);

/// <summary>
/// Searches the array for a number, returns if it was found, and if found, the index as well
/// </summary>
/// <param name="arr">the array to search through</param>
/// <param name="num">the number to search for</param>
/// <param name="index">the index of the number if it was found</param>
/// <returns>if the number was found or not</returns>
bool search(int* arr[], int num, int& index);

/// <summary>
/// replaces one value with a different value
/// </summary>
/// <param name="arr">the array that gets altered</param>
/// <param name="num">the new number</param>
/// <param name="index">the index that gets replaced</param>
void replace(int* arr[], int num, int index);

/// <summary>
/// appends a number to the end of the array
/// </summary>
/// <param name="arr">the array to alter</param>
/// <param name="num">the number that will be appended</param>
void append(int* arr[], int num);

/// <summary>
/// deletes a number from the array
/// </summary>
/// <param name="arr">the array to alter</param>
/// <param name="index">the index to delete</param>
void del(int* arr[], int index);

/// <summary>
/// prints the array
/// </summary>
/// <param name="arr">the array to print</param>
void print_array(int* arr[]);

/// <summary>
/// Takes input from the user for an index and verifies that it is correct
/// </summary>
/// <param name="statement">output statement that asks user to input an index</param>
/// <param name="count">the amount of numbers in the array</param>
/// <returns>the index that was inputted</returns>
int indexInput(string statement, int count);