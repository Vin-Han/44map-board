#pragma once
#include <iostream>
#include<sstream>
using namespace std;

class toolFunction
{
public:
	bool CheckArray(int array[4][4], int arrayChe[4][4]);

	void CreatArray(int array[4][4]);

	void RandNum(int gameLevel, int array[4][4], int& speNumVer, int& speNumHor);

	void upR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel);

	void downR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel);

	void rightR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel);

	void leftR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel);
};