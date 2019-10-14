#include "coreMove.h"


void coreMove::ChangeArray(int &speNumVer ,int &speNumHor ,int array[4][4],int gameLevel,int &userStep) {
	cout << "***give me order to controll the number 0 :" << endl;
	cout << "***\"WSAD\" to control it up ,down ,right and left" << endl;
	cout << "***\"R\" to save this game" << endl;
	string userControl;
	getline(cin, userControl);
	system("cls");
	if (userControl == "w") up(speNumVer, speNumHor, array, userStep);
	else if (userControl == "s") down(speNumVer, speNumHor, array, userStep);
	else if (userControl == "a") right(speNumVer, speNumHor, array, userStep);
	else if (userControl == "d") left(speNumVer, speNumHor, array, userStep);
	else if (userControl == "r") SaveRecord(gameLevel,array, speNumVer, speNumHor, userStep);
	else {
		cout << "worry number,try other way" << endl;
		return;
	}
}
	void coreMove::up(int &speNumVer ,int &speNumHor,int array[4][4],int &userStep) {
		if (speNumVer == 0) {
			cout << "0 can not move up,try other way" << endl;
			return;
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer - 1][speNumHor];
			speNumVer = speNumVer - 1;
			array[speNumVer][speNumHor] = 16;
			userStep++;
		}
	}
	void coreMove::down(int& speNumVer, int& speNumHor, int array[4][4], int &userStep) {
		if (speNumVer == 3) {
			cout << "0 can not move down,try other way" << endl;
			return;
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer + 1][speNumHor];
			speNumVer = speNumVer + 1;
			array[speNumVer][speNumHor] = 16;
			userStep++;
		}
	}
	void coreMove::right(int& speNumVer, int& speNumHor, int array[4][4], int &userStep) {
		if (speNumHor == 0) {
			cout << "0 can not move right,try other way" << endl;
			return;
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer][speNumHor - 1];
			speNumHor = speNumHor - 1;
			array[speNumVer][speNumHor] = 16;
			userStep++;
		}
	}
	void coreMove::left(int& speNumVer, int& speNumHor, int array[4][4], int &userStep) {
		if (speNumHor == 3) {
			cout << "0 can not move left,try other way" << endl;
			return;
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer][speNumHor + 1];
			speNumHor = speNumHor + 1;
			array[speNumVer][speNumHor] = 16;
			userStep++;
		}
	}