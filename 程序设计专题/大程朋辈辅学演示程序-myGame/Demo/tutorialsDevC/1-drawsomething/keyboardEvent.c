#include "myHeader.h"

bool isCtrl = FALSE, isP = FALSE;
void KeyboardEventProcess(int key, int event)
{
	switch(key)
	{
		case 'R':	/* 5 - press R */
			if (event == KEY_DOWN && !gameStatus)
				boardDirection *= -1;
			break;
		case 'P':	/* 6 - pause */
			isP = !event;
			if (isP && isCtrl)
				if (gameStatus == 0)		gameStatus = 1;
				else if (gameStatus == 1)	gameStatus = 0;
			break;
		case VK_LCONTROL: case VK_RCONTROL: case VK_CONTROL:
			isCtrl = !event;
			/* 6 - pause */
			if (isP && isCtrl)
				if (gameStatus == 0)		gameStatus = 1;
				else if (gameStatus == 1)	gameStatus = 0;
			break;
			/* end of 6 */
	}
	display();
}
