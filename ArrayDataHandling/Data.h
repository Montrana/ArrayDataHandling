#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int Max_Arr_Length = 15;

void inFile(int* arr[], string infile, int& count);
bool search(int* arr[], int num, int& index);
void replace(int* arr[], int num, int index);
void append(int* arr[], int num);
void del(int* arr[], int index);
void print_array(int* arr[]);
int indexInput(string statement, int count);