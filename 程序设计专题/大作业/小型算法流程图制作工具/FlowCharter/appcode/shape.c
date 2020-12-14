/* File: shape.c
 * -------------
 * This file provides the basic structure, linked list
 * and functions on graphing in the project. 
 */

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
Shape *shapeHead = NULL, *shapeTail = NULL;

/* Function: NormalizeShape
 * Usage: NormalizeShape(A)
 * -----------
 * This function makes sure that the Shape is large enough
 * to be operated on.
 */

void NormalizeShape(Shape *A)
{
	if(A == NULL) return;
	if(A->sizeX < 0.2) A->sizeX = 0.2;
	if(A->sizeX > 2.0) A->sizeX = 2.0;
	if(A->sizeY < 0.2) A->sizeY = 0.2;
	if(A->sizeY > 0.6) A->sizeY = 0.6;
}

/* 
 * Function: DrawShape
 * Usage: DrawShape(A)
 * -----------
 * Draw the shape A.
 */
void DrawShape(Shape *A)
{
	if(A == NULL)	return;
	
	/* Normalize the Shape, in case there are 
	   negative parameters in the Shape. */
	NormalizeShape(A);
	
	if(A->color == NULL)
		SetPenColor("Black");
	else
		SetPenColor(A->color);
	SetPenSize(A->width);
	
	/* if isFilled == TRUE, fill the shape */
	if(A->isFilled)	StartFilledRegion(1);	
	switch(A->shapeType)
	{
		/* rectangle */
		case 1:		
			MovePen(A->posX - A->sizeX/2.0, A->posY - A->sizeY/2.0);
			DrawLine(A->sizeX, 0); 
			DrawLine(0, A->sizeY); 
			DrawLine(-A->sizeX, 0); 
			DrawLine(0, -A->sizeY);
			break;
		
		/* rounded rectangle */	
		case 2:		
			/* Note: We preset the radius of the rounded angle as 
			   one-third of the length in the Y direction. */
			MovePen(A->posX + A->sizeX/2.0, A->posY - A->sizeY/6.0);
			DrawLine(0, A->sizeY/3.0);
			DrawArc(A->sizeY/3.0, 0.0, 90.0);
			DrawLine(2*A->sizeY/3.0 - A->sizeX, 0);
			DrawArc(A->sizeY/3.0, 90.0, 90.0);
			DrawLine(0, -A->sizeY/3.0);
			DrawArc(A->sizeY/3.0, 180.0, 90.0);
			DrawLine(A->sizeX - 2*A->sizeY/3.0, 0);
			DrawArc(A->sizeY/3.0, 270.0, 90.0);
			break;
			
		/* lozenge */
		case 3:
			MovePen(A->posX - A->sizeX/2.0, A->posY);
			DrawLine(A->sizeX/2.0, A->sizeY/2.0);
			DrawLine(A->sizeX/2.0, -A->sizeY/2.0);
			DrawLine(-A->sizeX/2.0, -A->sizeY/2.0);
			DrawLine(-A->sizeX/2.0, A->sizeY/2.0);
			break;
		
		/* parallelogram */
		case 4:
			/* Note: We preset the degree of base angle is 60.0 */
			MovePen(A->posX - A->sizeX/2.0, A->posY - A->sizeY/2.0);
			DrawLine(A->sizeY/2.0, A->sizeY);
			DrawLine(A->sizeX - A->sizeY/2.0, 0);
			DrawLine(-A->sizeY/2.0, -A->sizeY);
			DrawLine(A->sizeY/2.0 - A->sizeX, 0);
			break;
			
		default:
			return;
	}
	if(A->isFilled) EndFilledRegion();
	
	SetPenColor("Black");
	if(A->contents != NULL)
	{
		MovePen(A->posX - A->sizeX/3.0, A->posY - 0.05);
		DrawTextString(A->contents);
	}
}

/* Function: DrawAllShape
 * ---------
 * Draw all Shapes.
 */
void DrawAllShape()
{
	Shape *A = shapeTail;
	while(A != NULL)
	{
		DrawShape(A);
		A = A->last;
	}
}

/* Function: SaveShape
 * --------------------
 * This function save all data about a Shape
 * on the screen
 */
void SaveShape(FILE *fp, Shape *A)
{
	fprintf(fp, "%d %d %d %lf %lf %lf %lf %s ",
		 		A->isFilled, A->shapeType, A->width, A->posX, 
				A->posY, A->sizeX, A->sizeY, A->color);
	if(A->contents == NULL || strlen(A->contents) <= 1)
		fprintf(fp, "-*-*-\n");
	else
	{
		int i;
		for(i = 0; i < strlen(A->contents); i++)
		{
			if(A->contents[i] == ' ')	A->contents[i] = '_';
		}
		fprintf(fp, "%s\n", A->contents);
		for(i = 0; i < strlen(A->contents); i++)
		{
			if(A->contents[i] == '_')	A->contents[i] = ' ';
		}
	}
		
}

/* Function: SaveAllShape
 * ---------
 * This function save all data about the Shapes
 * on the screen.
 */
void SaveAllShape(FILE *fp)
{
	Shape *A = shapeHead;
	while(A != NULL)
	{
		SaveShape(fp, A);
		A = A->next;
	}
}

/* Function: InShape
 * Usage: if(InShape(A, x, y)) ...
 * ----------
 * This function judges whether point (x, y) is 
 * in the minimum enclosing rectangle of the Shape.
 */
bool InShape(Shape *A, double x, double y)
{
	if(A == NULL) return FALSE;
	if(x >= A->posX - A->sizeX / 2.0 && x <= A->posX + A->sizeX / 2.0
	&& y >= A->posY - A->sizeY / 2.0 && y <= A->posY + A->sizeY / 2.0)
		return TRUE;
		
	return FALSE;
}

/* Function: SearchShape
 * Usage: nowShape = SearchShape(x, y)
 * ----------
 * This function search for the latest added Shape
 * whose area contains point (x, y)
 */ 
Shape *SearchShape(double x, double y)
{
	Shape *A = shapeTail;
	while(A != NULL)
	{
		if(InShape(A, x, y))
			return A;
		A = A->last;
	}
	return NULL;
}

/* Function: CreateShape
 * ------------
 * This function creates a new shape with the given arguments
 * and adds it to the tail of the linked list, finally draw it.
 */
Shape *CreateShape(bool isFilled, int shapeType, int width, double posX,
				   double posY, double sizeX, double sizeY, string color,
				   string contents)
{
	/* linked list operation */
	if(shapeHead == NULL)
	{
		shapeHead = shapeTail = (Shape*)malloc(sizeof(Shape));
		shapeTail->last = NULL;
	}
	else
	{
		shapeTail->next = (Shape*)malloc(sizeof(Shape));
		shapeTail->next->last = shapeTail;
		shapeTail = shapeTail->next;
	}
	
	/* initialize the Shape*/
	shapeTail->next = NULL;
	shapeTail->color = (char *)malloc(sizeof(char) * strlen(color));
	strcpy(shapeTail->color, color);
	shapeTail->isFilled = isFilled;
	shapeTail->posX = posX;
	shapeTail->posY = posY;
	shapeTail->sizeX = sizeX;
	shapeTail->sizeY = sizeY;
	shapeTail->shapeType = shapeType;
	shapeTail->width = width;
	strcpy(shapeTail->contents, contents);
	/* draw it */
	DrawShape(shapeTail);
	return shapeTail;
}

/* Function: ReadShape
 * ----------------
 * Read a Shape from data.
 */
bool ReadShape(FILE *fp)
{
	bool isFilled;
	int shapeType, width;
	double posX, posY, sizeX, sizeY;
	char contents[101], color[20];
	if(fscanf(fp, "%d%d%d%lf%lf%lf%lf%s%s",
			  &isFilled, &shapeType, &width, &posX, 
			  &posY, &sizeX, &sizeY, &color, &contents) != EOF)
			  {
			  		if(strcmp(contents, "-*-*-") == 0)	contents[0] = '\0';
			  		int i;
			  		for(i = 0; i < strlen(contents); i++)
			  		{
			  			if(contents[i] == '_')	contents[i] = ' ';
			  		}
					CreateShape(isFilled, shapeType, width, posX,
							    posY, sizeX, sizeY, color, contents);
					
					return TRUE;
			  }
	return FALSE;
}
