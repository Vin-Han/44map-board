#pragma once
#include <iostream>
#include<sstream>
#include "Record.h"
using namespace std;

class coreMove:public Record
{
public:
	void ChangeArray(int &speNumVer, int &speNumHor, int array[4][4], int gameLevel, int &userStep);
	void up(int& speNumVer, int& speNumHor, int array[4][4], int &userStep);
	void down(int& speNumVer, int& speNumHor, int array[4][4], int &userStep);
	void right(int& speNumVer, int& speNumHor, int array[4][4], int &userStep);
	void left(int& speNumVer, int& speNumHor, int array[4][4], int &userStep);
};

