/* File: shape.h
 * -------------
 * This file provides the basic structure, linked list
 * and functions on graphing in the project. 
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "myIncludes.h"

/*
 * Type: Shape
 * ------------
 * This structure is the basic form of all required shapes:
 * rectangle, rounded rectangle, lozenge and parallelogram.
 * 
 * Meanwhile, this structure is also a linked list, which is designed
 * with a "next" and "last" pointer to the next/last node of Shape.
 * -------------
 * Variables:
 * 
 * The "isFilled" variable shows whether the shape is filled.
 * 
 * The "shapeType" variable shows the actual shape with an integer 1~4,
 * which corresponds with the 4 shapes mentioned above in order.
 * 
 * The "width" variable shows the width of lines in pixels.
 * 
 * The "posX/Y" variable shows the position(in inches) of the shape by 
 * a coordinate (x, y) of the center point, in the unit of inch.
 *
 * The "sizeX/Y" variable shows the size of the shape by the length (in inches)
 * in the x and y direction of its minimum enclosing rectangle.
 * 
 * The "color" variable shows the color of the lines (and filler) by a string,
 * which can be one of: "Black", "Dark Gray","Gray", "Light Gray", "White",
 * "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Magenta", "Cyan".
 *
 * The "contents" variable shows the text inside the shape.
 */
typedef struct myShape
{
	bool isFilled;
	int shapeType, width;
	double posX, posY, sizeX, sizeY;
	char contents[101];
	string color;
	struct myShape *next, *last;
}Shape; 

/* Global variable: shapeHead, shapeTail
 * The head and tail of the linked list
 */
extern Shape *shapeHead, *shapeTail;

/* Function: DrawAllShape
 * ---------
 * Draw all Shapes.
 */
void DrawAllShape();

/* Function: SaveShape
 * --------------------
 * This function save all data about a Shape
 * on the screen
 */
void SaveShape(FILE *fp, Shape *A);

/* Function: SaveAllShape
 * ---------
 * This function save all data about the Shapes
 * on the screen.
 */
void SaveAllShape(FILE *fp);

/* Function: InShape
 * Usage: if(InShape(A, x, y)) ...
 * ----------
 * This function judges whether point (x, y) is 
 * in the minimum enclosing rectangle of theShape.
 */
bool InShape(Shape *A, double x, double y);

/* Function: SearchShape
 * Usage: nowShape = SearchShape(x, y)
 * ----------
 * This function search for the latest added Shape
 * whose area contains point (x, y)
 */ 
Shape *SearchShape(double x, double y);

/* Function: CreateShape
 * ------------
 * This function creates a new shape with the given arguments
 * and adds it to the tail of the linked list, finally draw it.
 */
Shape *CreateShape(bool isFilled, int shapeType, int width, double posX,
				   double posY, double sizeX, double sizeY, string color,
				   string contents);
				   
/* Function: ReadShape
 * ----------------
 * Read a Shape from data.
 */
bool ReadShape(FILE *fp);
				   
#endif /* SHAPE_H */
