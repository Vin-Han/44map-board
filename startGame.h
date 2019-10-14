#pragma once
#include <iostream>
#include<sstream>
#include "toolFunction.h"
#include "Record.h"
#include "coreMove.h"
#include "time.h"
using namespace std;


class startGame{
private:
	int array[4][4];
	int arrayChe[4][4];
	int speNumVer;
	int speNumHor;
	int gameLevel;
	int userStep;
	string userOrder;
private:
	void userInterFace();
	void creatMap();
	void readRecord();
	void PrintArray();
	bool CheckArray();
	void gameStart();

public:
	void startNewGame();
	startGame();
};

