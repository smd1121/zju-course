#include "pch.h"
using namespace std;

class Room {
private:
	int index;		/* Rooms will be stored in an array. The index of each room equals to its index in array.*/
	int nextRoom[4];			/* The index of the room connected by exit: east, west, up and down. -1 means that the exit does not exist.*/
	int exitNum = 0;			/* The number of existent exit(s). */
	bool isMonster = false, isPrincess = false, isLobby = false; 
	static string dirName[4];			/*east, west, up and down */
public:
	static bool hasFound;			/* Whether the player has met the princess.*/
	void init(int index, int *nextRoom);		/*Initialize the index and exits of the room*/
	bool enterNewRoom() const;			/* Print the information about the room. And if the game is over, return true.*/
	int getNextRoom(const string &direction) const;			/* Return the index of the room connect by the 'direction' exit.*/
	void setSpecialRoom(int type);			/*Set the rooms with princess (type1) or monster (type2).*/
};

bool Room::hasFound = false;
string Room::dirName[4] = { "east", "west", "up", "down" };

/*Initialize the index and exits of the room*/
void Room::init(int index, int *nextRoom) {
	if (index == 1)	isLobby = true;
	this->index = index;
	for (int i = 0; i < 4; i++) {
		this->nextRoom[i] = nextRoom[i];
		if (nextRoom[i] != -1)	exitNum++;
	}
}

/* Print the information about the room. And if the game is over, return true.*/
bool Room::enterNewRoom() const {
	if (isLobby && hasFound) {
		cout << "Congratulations! You've made it to save the princess!" << endl;
		return true;
	}
	else if (isLobby)  cout << "Welcome to the lobby. ";
	else cout << "You've entered a room. ";

	if (isMonster) {
		cout << "Unluckily, there is a monster in this room. Your adventure has failed. " << endl;
		return true;
	}
	if (isPrincess) {
		cout << "Congratulations! You've found the princess! Please take her outside the castle! " << endl;
		hasFound = true;
	}

	if (exitNum == 1) {
		cout << "There is only 1 exit: ";
		for (int i = 0; i < 4; i++)	if (nextRoom[i] != -1)	cout << dirName[i];
		cout << "." << endl;
	}
	else {
		cout << "There are " << exitNum << " exits: ";
		int count = 0;		/* to show what time to print "and" */
		for (int i = 0; i < 4; i++) 
			if (nextRoom[i] != -1) {
				cout << dirName[i];
				count++;
				switch (exitNum - count) {
				case 0: cout << "." << endl; break;
				case 1: cout << " and "; break;
				default: cout << ", "; break;
				} //end of switch
			} //end of if
	} // end of else

	cout << "Enter your command:" << endl;
	return false;
}

/* Return the index of the room connect by the 'direction' exit.*/
int Room::getNextRoom(const string &direction) const {
	for (int i = 0; i < 4; i++) {
		if (direction == dirName[i]) {
			return nextRoom[i];
		}
	}
	return -1;		 /* -1 indicates an error input.*/
}

/*Set the rooms with princess (type1) or monster (type2).*/
void Room::setSpecialRoom(int type) {
	if (type == 1)		isPrincess = true;
	if (type == 2)	isMonster = true;
}