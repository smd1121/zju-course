#include "myHeader.h"

/* 4 - timer */
void mytimer(int timerID)
{
	if (timerID)	return;
	if (gameStatus)	return;		/* 6 - pause */
	
	/* Part 1: board */
	board->posX += 0.5 * boardDirection;
	if (board->posX + board->sizeX / 2 >= 6)
		boardDirection = -1;
	if (board->posX - board->sizeX / 2 <= 0)
	 	boardDirection = 1;
	
	/* Part 2: speed & score */
	if (speed < 2)	speed += 0.0001 * (rand() % 10);
	score += rand() % 10;
	
	/* Part 3: fall */ /* 8 - fall */
	Shape *temp = head;
	while (temp) 
	{
		temp->posY -= temp->sizeX / 2;
		/* 11 - fail */
		if (crashed(temp))
		{
			gameStatus = 2;
		}
		/* end of 11 */
		/* 10 - success */
		if (temp->posY < -temp->sizeX)
		{
			score += speed * 100;
			deleteShape(temp);
		}
		/* end of 10 */
		temp = temp->next;
	}
	/* end of 8 */
	
	display();
}
