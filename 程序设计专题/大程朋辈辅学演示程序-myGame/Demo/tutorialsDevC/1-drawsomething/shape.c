#include "myHeader.h"

char colorList[100][100] = {"Black", "Dark Gray", "Gray", "Brown", "Red", "Orange", 
"Green", "Blue", "Violet", "Magenta", "Cyan", "Light Gray", "White", "Yellow"};
const int colorNumber = 14, validColorNumber = 11;

Shape *head = NULL, *tail = NULL;

/* 2 - draw shape */
void DrawShape(Shape *s) {
	SetPenColor(s->color);							// set color
	/* if isFilled == TRUE, fill the shape */
	if(s->isFilled)	StartFilledRegion(1);	
	switch(s->shapeType)
	{
		case 0:	//rectangle
		{
			MovePen(s->posX - s->sizeX/2.0, s->posY - s->sizeY/2.0);
			DrawLine(s->sizeX, 0); 
			DrawLine(0, s->sizeY); 
			DrawLine(-s->sizeX, 0); 
			DrawLine(0, -s->sizeY);
			break;
		}
		case 1: //circle
		{
			MovePen(s->posX + s->sizeX/2.0, s->posY);
			DrawArc(s->sizeX/2.0, 0, 360);
			break;
		}
	} // End of switch
	if(s->isFilled) EndFilledRegion();
}
/* end of 2 */

/* 3 - windows structure */
Shape *createShape(bool isInLinkedList, bool isF, int sTy, 
				   double pX, double pY, double sX, double sY, string clr) 
{
	Shape *s = (Shape *)malloc(sizeof(Shape));
	
	s->isFilled = isF, s->shapeType = sTy, s->posX = pX, 
	s->posY = pY, s->sizeX = sX, s->sizeY = sY, s->color = clr;
	s->next = s->last = NULL;
	
	if (sTy == 1)	s->sizeY = sX; 		// circle : sizeY <- r 
	
	/* 7 - click to create circle */
	if (isInLinkedList)
	{
		if (!head) head = tail = s;
		else 
		{
			tail->next = s;
			s->last = tail;
			tail = s;
		}
	}
	/* end of 7 */
	
	return s;
}
/* end of 3 */

/* 9 - delete */
bool isInShape(double mx, double my, Shape *s) {
	if (!s) return FALSE;
	switch(s->shapeType)
	{
		case 0:	//rectangle
		{
			if (mx > s->posX - s->sizeX / 2 && mx < s->posX + s->sizeX / 2
			 && my > s->posY - s->sizeY / 2 && my < s->posY + s->sizeY / 2)
			 	return TRUE;
			else return FALSE;
			break;
		}
		case 1: //circle
		{
			//(x - x0)^2 + (y - y0)^2 < r^2
			if ((mx - s->posX)*(mx - s->posX) + (my - s->posY)*(my - s->posY) 
				< s->sizeX * s->sizeX / 4) 
				return TRUE;
			else return FALSE;
			break;
		}
	} // End of switch
}
void deleteShape(Shape *s) {
	// s not linked list
	if (!s->last && !s->next && head != s)
		return;
	
	if (!s->last)
		head = s->next;
	if (!s->next)
		tail = s->last;
	if (s->last)
		s->last->next = s->next;
	if (s->next)
		s->next->last = s->last;
}
/* end of 9 */

/* 11 - fail */
// return true if s and board overlap
bool crashed(Shape *s) {
	if (s->posX > board->posX - board->sizeX / 2 && s->posX < board->posX + board->sizeX / 2
	 && s->posY - s->sizeX / 2 < board->sizeY && s->posY + s->sizeX / 2 > 0)
	 	return TRUE;
	if (isInShape(board->posX - board->sizeX / 2, board->posY - board->sizeY / 2, s)
	 || isInShape(board->posX - board->sizeX / 2, board->posY + board->sizeY / 2, s)
	 || isInShape(board->posX + board->sizeX / 2, board->posY - board->sizeY / 2, s)
	 || isInShape(board->posX + board->sizeX / 2, board->posY + board->sizeY / 2, s))
	 	return TRUE;
	return FALSE;
}
/* end of 11 */
