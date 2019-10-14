#include "startGame.h"

startGame::startGame() :speNumVer(3), speNumHor(3), gameLevel(0), userStep(0) {
	int arrayCount = 1;
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			array[ver][hor] = arrayCount;
			arrayChe[ver][hor] = arrayCount;
			arrayCount++;
		}
	}
}

void startGame::startNewGame() {
	srand((unsigned)time(NULL));
	userInterFace();
	if (userOrder == "1") {creatMap(); gameStart();}
	else if (userOrder == "2") {readRecord(); PrintArray(); gameStart();}
	else if (userOrder == "3") return;
	else {cout << "***wrroy number ,please try again " << endl; startNewGame();}
}

void startGame::userInterFace() {
	cout << "******welcome to game!*****\n" << endl;
	cout << "putin \"1\" to begin the game\n" << endl;
	cout << "putin \"2\" to read the record\n" << endl;
	cout << "putin \"3\" to quit the game\n" << endl;
	cout << "***************************\n" << endl;
	getline(cin, this->userOrder);
	system("cls");
}

void startGame::creatMap(){
	cout << "******welcome to game!*****\n" << endl;
	cout << "**give the level of game:**" << endl;
	cin >> gameLevel;
	cin.clear();
	cin.ignore(1024, '\n');
	toolFunction* newGame = new toolFunction;
	newGame->CreatArray(array);
	newGame->CreatArray(arrayChe);
	newGame->RandNum(gameLevel, array, speNumVer, speNumHor);
	system("cls");
	PrintArray();
	delete newGame;
	newGame = NULL;
}

void startGame::gameStart() {
	coreMove arrayNew;
	do {
		arrayNew.ChangeArray(speNumVer, speNumHor,array, gameLevel, userStep);
		PrintArray();
	} while (!CheckArray());
	cout << "***you win , good job ! " << endl;
	cout << "***the game is now in level " << gameLevel << endl;
	cout << "***used " << userStep << " steps to finish it !" << endl;
	return;
}

void startGame::readRecord() {
	Record* oldGame = new Record;
	oldGame->ReadRecord(gameLevel,array,speNumVer,speNumHor,userStep);
	delete oldGame;
	oldGame = NULL;
}

void startGame::PrintArray() {
	cout << "*****welcome to game!*****" << endl;
	cout << "***level " << gameLevel << "******step " << userStep << " ***" << endl;
	cout << "**************************" << endl;
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			if (array[ver][hor] != 16){
				cout << array[ver][hor] << "\t";
			}
			else{
				cout << "[~]" << "\t";
			}
		}
		cout << endl;
	}
	cout << "*******play for fun!******" << endl;
}

bool startGame::CheckArray() {
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			if (array[ver][hor] == arrayChe[ver][hor]) continue;
			else return false;
		}
	}
	return true;
}
