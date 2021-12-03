#ifndef ROOM_H
#define ROOM_H

class Room {
private:
	int index;		/* Rooms will be stored in an array. The index of each room equals to its index in array.*/
	int nextRoom[4];			/* The index of the room connected by exit: east, west, up and down. -1 means that the exit does not exist.*/
	int exitNum = 0;			/* The number of existent exit(s). */
	bool isMonster = false, isPrincess = false, isLobby = false;
	static std::string dirName[4];			/*east, west, up and down */
public:
	static bool hasFound;			/* Whether the player has met the princess.*/
	void init(int index, int *nextRoom);		/*Initialize the index and exits of the room*/
	bool enterNewRoom() const;			/* Print the information about the room. And if the game is over, return true.*/
	int getNextRoom(const std::string &direction) const;			/* Return the index of the room connect by the 'direction' exit.*/
	void setSpecialRoom(int type);			/*Set the rooms with princess (type1) or monster (type2).*/
};

#endif //ROOM_H