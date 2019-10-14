#include "Record.h"

void Record::ReadRecord(int& gameLevel, int array[4][4], int& speNumVer, int& speNumHor, int& userStep) {
	ifstream documentRea("GameRecord.txt");
	if (!documentRea.is_open()) {
		cout << "file is missing" << endl;
		return;
	}
	else {
		documentRea >> gameLevel;
		documentRea >> speNumVer;
		documentRea >> speNumHor;
		documentRea >> userStep;
		for (int ver = 0; ver < 4; ver++) {
			for (int hor = 0; hor < 4; hor++) {
				documentRea >> array[ver][hor];
			}
		}
		documentRea.close();
	}
}

void Record::SaveRecord(const int &gameLevel, const int array[4][4], const int &speNumVer, const int &speNumHor, const int &userStep) {
	ofstream documentSav("GameRecord.txt");
	if (!documentSav.is_open()){
		cout << "file is missing" << endl;
		return;
	}
	else{
		documentSav << gameLevel << endl;
		documentSav << speNumVer << endl;
		documentSav << speNumHor << endl;
		documentSav << userStep << endl;
		for (int ver = 0; ver < 4; ver++) {
			for (int hor = 0; hor < 4; hor++) {
				documentSav << array[ver][hor] << endl;
			}
		}
		documentSav.close();
		cout << "file saved successfully" << endl;
	}
}