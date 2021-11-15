/* File: arrow.h
 * -------------
 * This file provides the form of all Arrows.
 */
#ifndef ARROW_H
#define ARROW_H

#include "myIncludes.h"
#include "shape.h"

/*
 * Type: Arrow
 * ------------
 * This structure is the form of all Arrows.
 * 
 * Meanwhile, this structure is also a linked list, which is designed
 * with a "next" and "last" pointer to the next/last node of Arrow.
 * -------------
 * Variables:
 * 
 * The "isFilled" variable shows whether the shape is filled.
 * 
 * The "width" variable shows the width of lines in pixels.
 * 
 * The "posX/Y" variable shows the position(in inches) of the arrow by 
 * a coordinate (x, y) of the beginning point, in the unit of inch.
 *
 * The "sizeX/Y" variable shows the offset of the arrow 
 * by the length (in inches) in the x and y direction.
 * 
 * The "color" variable shows the color of the arrow by a string, which can
 * be one of: "Black", "Dark Gray","Gray", "Light Gray", "White", "Brown", 
 * "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Magenta", "Cyan".
 *
 * The "contents" variable is designed to use in if-else structures.
 * We write "Y" or "N" on the arrow to show which way to go.
 *
 * The "arrBegin" & "arrEnd" variable shows where the arrow is
 * from and to which shape the arrow point to.
 */
typedef struct myArrow
{
	bool isDotted;
	int width;
	double posX, posY, sizeX, sizeY;
	string color, contents;
	struct myArrow *next, *last;
	Shape *arrBegin, *arrEnd;
}Arrow;

/*
 * Type: ArrowPair
 * ------------
 * This structure contains two pointers to Arrow.
 * It is used for if-else structure, which has 2 out-arrows.
 */

typedef struct doubleArrow
{
	Arrow *arrowOne, *arrowTwo;
}ArrowPair;

/* Global variable: arrowHead, arrowTail
 * The head and tail of the linked list
 */
extern Arrow *arrowHead, *arrowTail;

/* Function: NormalizeArrow
 * Usage: NormalizeArrow(A)
 * -----------
 * This function makes sure that the Arrow is large enough
 * to be operated on.
 */
void NormalizeArrow(Arrow *A);

/* 
 * Function: DrawArrow
 * Usage: DrawArrow(A)
 * -----------
 * Draw the arrow A.
 */
void DrawArrow(Arrow *A);

/* Function: DrawAllArrow
 * ---------
 * Draw all Arrows.
 */
void DrawAllArrow();

/* Function: SaveArrow
 * --------------------
 * This function save all data about an Arrow
 * on the screen
 */
void SaveArrow(FILE *fp, Arrow *A);

/* Function: SaveAllArrow
 * ---------
 * This function save all data about the Arrows
 * on the screen.
 */
void SaveAllArrow(FILE *fp);

/* Function: InArrow
 * -------------
 * This function judges whether point (x, y) is 
 * near the Arrow enough.
 */
bool InArrow(Arrow *A, double x, double y);

/* Function: SearchArrowPair
 * Usage: nowArrow = SearchArrowPair(nowShape).arrowOne
 * ----------
 * This function search for the latest added 2 Arrows
 * which begin from the given shape.
 * If there is less than 2 Arrow begins from the given
 * shape, the second or both pointer will be NULL.
 */ 
ArrowPair SearchArrowPair(Shape *shape);

/* Function: SearchArrow
 * -------------------
 * This function search for the latest added Arrow
 * whose area contains point (x, y)
 */ 
Arrow *SearchArrow(double x, double y);

/* Function: CreateArrow
 * ------------
 * This function creates a new shape with the given arguments
 * and adds it to the tail of the linked list, finally draw it.
 */
Arrow *CreateArrow(bool isDotted, int width, double posX, double posY,
				   double sizeX, double sizeY, string color, string contents);

/* Function: ReadArrow
 * ----------------
 * Read an Arrow from data.
 */
bool ReadArrow(FILE *fp);

#endif  /* ARROW_H */
