#ifndef _SHAPE_H_
#define _SHAPE_H_

/* 1 - struct shape */
/*
 * shapeType - 0: rectangle, 1: circle
 */
typedef struct Shape 
{
	bool isFilled;
	int shapeType;
	double posX, posY, sizeX, sizeY;
	string color;
	struct Shape *next, *last;
} Shape;
/* end of 1 */

/* 2 - draw shape */
void DrawShape(Shape *s);
/* end of 2 */

/* 3 - windows structure */
Shape *createShape(bool isInLinkedList, bool isF, int sTy, 
				   double pX, double pY, double sX, double sY, string clr);
/* end of 3 */

/* 9 - delete */
bool isInShape(double mx, double my, Shape *s);
void deleteShape(Shape *s);
/* end of 9 */

/* 11 - fail */
bool crashed(Shape *s);
/* end of 11 */


#endif // _SHAPE_H_
