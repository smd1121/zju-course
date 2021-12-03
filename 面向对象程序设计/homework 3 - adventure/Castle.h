#ifndef CASTLE_H
#define CASTLE_H

#include "room.h"

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

#endif //CASTLE_H