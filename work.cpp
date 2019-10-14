#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;

void PrintArray(int array[4][4]);												//print out the line 
void CreatArray(int array[4][4]);												//creat a new array which is arranged in order
void ChangeArray(int array[4][4], int& speNumVer, int& speNumHor);				//core function that control the array 
bool CheckArray(int array[4][4], int arrayChe[4][4]);							//check the array if it is finished
void RandNum(int gameLevel, int array[4][4], int& speNumVer, int& speNumHor);	//change the level as user's want

void mains(){
	int array[4][4];
	int arrayChe[4][4] ;
	int speNumVer = 3 ;
	int speNumHor = 3 ;
	int gameLevel = 0 ;
	int userStep = 0 ;
	string userOrder ;
	srand((unsigned)time(NULL));
	cout << "******welcome to game!*****\n" << endl;
	cout << "putin \"1\" to begin the game\n" << endl;
	cout << "putin \"2\" to quit the game\n" << endl;
	cout << "***************************\n" << endl;
	getline(cin, userOrder);
	system("cls");
	if (userOrder == "1") {
		cout << "give the level of game :" << endl;
		cin >> gameLevel;
		CreatArray(array);
		CreatArray(arrayChe);
		RandNum(gameLevel, array, speNumVer, speNumHor);
		PrintArray(array);
		do {
			ChangeArray(array, speNumVer, speNumHor);
			userStep++;
			PrintArray(array);
		} while (!CheckArray(array,arrayChe));
		cout << "***you win , good job ! " << endl;
		cout << "***it is level " << gameLevel << " game" << endl;
		cout << "***and you use " << userStep << " steps to finish it !" << endl;
		return;
	}
	else if (userOrder == "2") return;
	else {
		cout << "***wrroy number ,please try again " << endl;
		mains();
	}
}

void CreatArray(int array[4][4]) {
	int arrayCount = 1;
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			array[ver][hor] = arrayCount;
			arrayCount++;
		}
	}
	array[3][3] = 0;
}

void PrintArray(int array[4][4]) {
	system("cls");
	cout << "*****welcome to game!*****" << endl;
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			cout << array[ver][hor] << "\t";
		}
		cout << endl;
	}
	cout << "*******play for fun!******" << endl;
}

bool CheckArray(int array[4][4], int arrayChe[4][4]) {

	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			if (array[ver][hor] == arrayChe[ver][hor]) continue;
			else return false;
		}
	}
	return true;
}

void ChangeArray(int array[4][4], int& speNumVer, int& speNumHor) {
	cout << "***give me order to controll the number 0 :" << endl;
	cout << "***\"WSAD\" to control it up ,down ,right and left" << endl;
	string userControl ;
	cin.clear();
	cin.ignore(1024,'\n');
	getline(cin, userControl);
	if (userControl == "w") {
		if (speNumVer == 0) {
			cout << "0 can not move up,try other way" << endl;
			ChangeArray(array, speNumVer, speNumHor);
			return ;
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer - 1][speNumHor];
			speNumVer = speNumVer - 1;
			array[speNumVer][speNumHor] = 0;
		}
	}
	else if (userControl == "s") {
		if (speNumVer == 3) {
			cout << "0 can not move down,try other way" << endl;
			ChangeArray(array, speNumVer, speNumHor);
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer + 1][speNumHor];
			speNumVer = speNumVer + 1;
			array[speNumVer][speNumHor] = 0;
		}
	}
	else if (userControl == "a") {
		if (speNumHor == 0) {
			cout << "0 can not move right,try other way" << endl;
			ChangeArray(array, speNumVer, speNumHor);
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer][speNumHor - 1];
			speNumHor = speNumHor - 1;
			array[speNumVer][speNumHor] = 0;
		}
	}
	else if (userControl == "d") {
		if (speNumHor == 3) {
			cout << "0 can not move left,try other way" << endl;
			ChangeArray(array, speNumVer, speNumHor);
		}
		else {
			array[speNumVer][speNumHor] = array[speNumVer][speNumHor + 1];
			speNumHor = speNumHor + 1;
			array[speNumVer][speNumHor] = 0;
		}
	}
	else{
		cout << "worry number,try other way" << endl;
		ChangeArray(array, speNumVer, speNumHor);
	}
}

void RandNum(int gameLevel, int array[4][4], int& speNumVer, int& speNumHor) {
	int temrNum = 0;
	int dirNumCheck0 = 0;
	for (int curLevel = 0; curLevel < gameLevel;) {
		int ranNum = rand() % 4;
		if (ranNum == 0) {
			if (speNumVer != 3 && dirNumCheck0 != 1) {
				array[speNumVer][speNumHor] = array[speNumVer + 1][speNumHor];
				speNumVer = speNumVer + 1;
				array[speNumVer][speNumHor] = 0;
				curLevel++;
				dirNumCheck0 = 2;
			}
			else continue;
		}
		else if (ranNum == 1) {
			if (speNumVer != 0 && dirNumCheck0 != 2) {
				array[speNumVer][speNumHor] = array[speNumVer - 1][speNumHor];
				speNumVer = speNumVer - 1;
				array[speNumVer][speNumHor] = 0;
				curLevel++;
				dirNumCheck0 = 1;
			}
			else continue;
		}
		else if (ranNum == 2) {
			if (speNumHor != 3 && dirNumCheck0 != 3) {
				array[speNumVer][speNumHor] = array[speNumVer][speNumHor + 1];
				speNumHor = speNumHor + 1;
				array[speNumVer][speNumHor] = 0;
				curLevel++;
				dirNumCheck0 = 4;
			}
			else continue;
		}
		else if (ranNum == 3) {
			if (speNumHor != 0 && dirNumCheck0 != 4) {
				array[speNumVer][speNumHor] = array[speNumVer][speNumHor - 1];
				speNumHor = speNumHor - 1;
				array[speNumVer][speNumHor] = 0;
				curLevel++;
				dirNumCheck0 = 3;
			}
			else continue;
		}
		else continue;
	}
}