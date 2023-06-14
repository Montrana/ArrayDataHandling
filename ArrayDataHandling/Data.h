#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int Max_Arr_Length = 150;

void inFile(int* arr[], string infile);
bool search(int* arr[], int num, int& index);
void set_index(int* arr[], int num, int index);
void append(int* arr[], int num);
void del(int* arr[], int index);