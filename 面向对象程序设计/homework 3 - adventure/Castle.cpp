#include "pch.h"
#include "room.h"

using namespace std;

class Castle {
private:
	static const int castleSize = 100;		/*maximum size of the castle*/
	Room room[castleSize + 5];		/*index start from 1*/
	int size;	/*the actual size of the castle*/
	int currentRoom = 1;
	void readRoomData();
	void generate(); /*randomly generate the room of princess and monster*/
public:
	void init();
	void play();
};

void Castle::init() {
	readRoomData();
	generate();
}

void Castle::readRoomData() {
	ifstream fin;
	fin.open("RoomData.in", ios::in);
	fin >> size;
	for (int i = 1; i <= size; i++) {
		int nextRoom[4];
		for (int j = 0; j < 4; j++)
			fin >> nextRoom[j];
		room[i].init(i, nextRoom);
	}
	fin.close();
}

/*randomly generate the room of princess and monster*/
void Castle::generate() {
	srand(time(0));

	int princess = rand() % (size - 1) + 2; /*make sure that the princess is not in the lobby (with index 1)*/
	int monster = rand() % (size - 1) + 2;
	while (princess == monster)	monster = rand() % (size - 1) + 2; /*make sure that princess and monster are not in a same room*/

	room[princess].setSpecialRoom(1);
	room[monster].setSpecialRoom(2);
}

void Castle::play() {
	string go, nextDir; /*each input has two words*/
	/*if entering the new room (printing the data at the same time) will not make the game over, enter another.*/
	while (!room[currentRoom].enterNewRoom()) {
		cin >> go >> nextDir;
		/*if the first word is not "go", or next room is unavailable, 
			which means the input is illegal, let the user input again.*/
		while (go != "go" ||  room[currentRoom].getNextRoom(nextDir) == -1) {
			cout << "The input is illegal! Please enter your command again:" << endl;
			cin >> go >> nextDir;
		}
		currentRoom = room[currentRoom].getNextRoom(nextDir);
	}
}