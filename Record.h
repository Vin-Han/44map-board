#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Record
{
public:
	void ReadRecord(int& gameLevel, int array[4][4], int& speNumVer, int& speNumHor, int& userStep);
	void SaveRecord(const int& gameLevel, const int array[4][4], const int& speNumVer, const int& speNumHor, const int& userStep);
};

