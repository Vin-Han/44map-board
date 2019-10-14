#include "toolFunction.h"

bool toolFunction::CheckArray(int array[4][4], int arrayChe[4][4]) {
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			if (array[ver][hor] == arrayChe[ver][hor]) continue;
			else return false;
		}
	}
	return true;
}

void toolFunction::CreatArray(int array[4][4]) {
	int arrayCount = 1;
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			array[ver][hor] = arrayCount;
			arrayCount++;
		}
	}
}

void toolFunction::RandNum(int gameLevel, int array[4][4], int& speNumVer, int& speNumHor) {
	int temrNum = 0;
	int dirNumCheck = 0;
	for (int curLevel = 0; curLevel < gameLevel;) {
		int ranNum = rand() % 4;
		if (ranNum == 0)	  upR(array, speNumVer, speNumHor, dirNumCheck, curLevel);
		else if (ranNum == 1) downR(array, speNumVer, speNumHor, dirNumCheck, curLevel);
		else if (ranNum == 2) rightR(array, speNumVer, speNumHor, dirNumCheck, curLevel);
		else if (ranNum == 3) leftR(array, speNumVer, speNumHor, dirNumCheck, curLevel);
		else continue;
	}
}

void toolFunction::upR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel) {
	if (speNumVer != 3 && dirNumCheck != 1) {
		array[speNumVer][speNumHor] = array[speNumVer + 1][speNumHor];
		speNumVer = speNumVer + 1;
		array[speNumVer][speNumHor] = 16;
		curLevel++;
		dirNumCheck = 2;
	}
	else return;
}

void toolFunction::downR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel) {
	if (speNumVer != 0 && dirNumCheck != 2) {
		array[speNumVer][speNumHor] = array[speNumVer - 1][speNumHor];
		speNumVer = speNumVer - 1;
		array[speNumVer][speNumHor] = 16;
		curLevel++;
		dirNumCheck = 1;
	}
	else return;
}

void toolFunction::rightR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel) {
	if (speNumHor != 3 && dirNumCheck != 3) {
		array[speNumVer][speNumHor] = array[speNumVer][speNumHor + 1];
		speNumHor = speNumHor + 1;
		array[speNumVer][speNumHor] = 16;
		curLevel++;
		dirNumCheck = 4;
	}
	else return;
}

void toolFunction::leftR(int array[4][4], int& speNumVer, int& speNumHor, int& dirNumCheck, int& curLevel) {

	if (speNumHor != 0 && dirNumCheck != 4) {
		array[speNumVer][speNumHor] = array[speNumVer][speNumHor - 1];
		speNumHor = speNumHor - 1;
		array[speNumVer][speNumHor] = 16;
		curLevel++;
		dirNumCheck = 3;
	}
	else return;
}