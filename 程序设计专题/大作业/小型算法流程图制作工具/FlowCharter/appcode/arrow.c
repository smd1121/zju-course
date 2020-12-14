/* File: arrow.c
 * -------------
 * This file provides the form of all Arrows.
 */
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
Arrow *arrowHead = NULL, *arrowTail = NULL;

/* Function: NormalizeArrow
 * Usage: NormalizeArrow(A)
 * -----------
 * This function makes sure that the Arrow is large enough
 * to be operated on.
 */
void NormalizeArrow(Arrow *A)
{
	if(A == NULL) return;
	if(A->sizeX >= -0.2 && A->sizeX < 0.2) A->sizeX = 0.2 * (A->sizeX < 0 ? -1 : 1);
	if(A->sizeY >= -0.2 && A->sizeY < 0.2) A->sizeY = 0.2 * (A->sizeY < 0 ? -1 : 1);
}

/* 
 * Function: DrawArrow
 * Usage: DrawArrow(A)
 * -----------
 * Draw the arrow A.
 */
void DrawArrow(Arrow *A)
{
	if(A == NULL)	return;
	
	SetPenColor(A->color);
	SetPenSize(A->width);
	
	/* Print "content" */
	const double charOffset = 0.5;
	MovePen(A->posX + charOffset * A->sizeX, A->posY + charOffset * A->sizeY);
	DrawTextString(A->contents);
	
	/* If isDotted == true, draw line 
	   seprately to get a dashed line. */
	MovePen(A->posX, A->posY);
	
	if(A->isDotted)
	{
		int dotFlag = 0;
		const double elemLength = 0.05;
		double 	ArrowLength = sqrt(A->sizeX * A->sizeX + A->sizeY * A->sizeY),
		 		offsetX = elemLength / ArrowLength * A->sizeX,
		 		offsetY = elemLength / ArrowLength * A->sizeY;
		 
		double i = 0;	
		for(; i <= ArrowLength; i += elemLength){
			if(!dotFlag)	DrawLine(offsetX, offsetY);
			else			MovePen(GetCurrentX() + offsetX, GetCurrentY() + offsetY);
			dotFlag = (dotFlag + 1) % 2;	//dotFlag = !dotFlag
		}
	}
	else	DrawLine(A->sizeX, A->sizeY);
	
	/* draw the arrowhead */
	StartFilledRegion(1);	
	const double headLenBase = 0.025, headLenHei = 0.1;
	double 	ArrowLength = sqrt(A->sizeX * A->sizeX + A->sizeY * A->sizeY),
		 		offsetX = A->sizeX / ArrowLength,
		 		offsetY = A->sizeY / ArrowLength;
	DrawLine(-offsetY * headLenBase, offsetX * headLenBase);
	DrawLine(offsetX * headLenHei + offsetY * headLenBase, offsetY * headLenHei - offsetX * headLenBase);
	DrawLine(-offsetX * headLenHei + offsetY * headLenBase, -offsetY * headLenHei - offsetX * headLenBase);
	DrawLine(-offsetY * headLenBase, offsetX * headLenBase);
	EndFilledRegion();
}

/* Function: DrawAllArrow
 * ---------
 * Draw all Arrows.
 */
void DrawAllArrow()
{
	Arrow *A = arrowTail;
	while(A != NULL)
	{
		DrawArrow(A);
		A = A->last;
	}
}

/* Function: SaveArrow
 * --------------------
 * This function save all data about an Arrow
 * on the screen
 */
void SaveArrow(FILE *fp, Arrow *A)
{
	fprintf(fp, "%d %d %lf %lf %lf %lf %s ",
		 	A->isDotted, A->width, A->posX, A->posY,
			A->sizeX, A->sizeY, A->color, A->contents);
	if(A->contents == NULL || strlen(A->contents) < 1)
		fprintf(fp, "X\n");
	else
		fprintf(fp, "%s\n", A->contents);
}

/* Function: SaveAllArrow
 * ---------
 * This function save all data about the Arrows
 * on the screen.
 */
void SaveAllArrow(FILE *fp)
{
	Arrow *A = arrowHead;
	while(A != NULL)
	{
		SaveArrow(fp, A);
		A = A->next;
	}
}
 
/* Function: InArrow
 * -------------
 * This function judges whether point (x, y) is 
 * near the Arrow enough.
 */
bool InArrow(Arrow *A, double x, double y)
{
	if(A == NULL) return FALSE;
	if((x >= A->posX && x <= A->posX + A->sizeX) 
	 ||(x <= A->posX && x >= A->posX + A->sizeX))
	{
		double arrowY = A->posY + (x - A->posX) / A->sizeX * A->sizeY;
		if(y >= arrowY - 0.3 && y <= arrowY + 0.3)
			return TRUE;
	}
	if((y >= A->posY && y <= A->posY + A->sizeY) 
	 ||(y <= A->posY && y >= A->posY + A->sizeY))
	{
		double arrowX = A->posX + (y - A->posY) / A->sizeY * A->sizeX;
		if(x >= arrowX - 0.3 && x <= arrowX + 0.3)
			return TRUE;
	}
	return FALSE;
}

/* Function: SearchArrowPair
 * Usage: nowArrow = SearchArrowPair(nowShape).arrowOne
 * ----------
 * This function search for the latest added 2 Arrows
 * which begin from the given shape.
 * If there is less than 2 Arrow begins from the given
 * shape, the second or both pointer will be NULL.
 */ 
ArrowPair SearchArrowPair(Shape *shape)
{
	ArrowPair arrowPair;
	arrowPair.arrowOne = arrowPair.arrowTwo = NULL;
	Arrow *A = arrowTail;
	while(A != NULL)
	{
		if(InShape(shape, A->posX, A->posY))
		{
			if(arrowPair.arrowOne == NULL)
				arrowPair.arrowOne = A;
			else
			{
				arrowPair.arrowTwo = A;
				return arrowPair;
			}
		}
		A = A->last;
	}
	return arrowPair;
}

/* Function: SearchArrow
 * -------------------
 * This function search for the latest added Arrow
 * whose area contains point (x, y)
 */ 
Arrow *SearchArrow(double x, double y)
{
	Arrow *A = arrowTail;
	while(A != NULL)
	{
		if(InArrow(A, x, y))
			return A;
		A = A->last;
	}
	return NULL;
}

/* Function: CreateArrow
 * ------------
 * This function creates a new shape with the given arguments
 * and adds it to the tail of the linked list, finally draw it.
 */
Arrow *CreateArrow(bool isDotted, int width, double posX, double posY,
				   double sizeX, double sizeY, string color, string contents)
{
	/* linked list operation */
	if(arrowHead == NULL)
	{
		arrowHead = arrowTail = (Arrow*)malloc(sizeof(Arrow));
		arrowTail->last = NULL;
	}
	else
	{
		arrowTail->next = (Arrow*)malloc(sizeof(Arrow));
		arrowTail->next->last = arrowTail;
		arrowTail = arrowTail->next;
	}
	
	/* initialize the Arrow*/
	arrowTail->next = NULL;
	arrowTail->contents = contents;
	arrowTail->color = (char *)malloc(sizeof(char) * strlen(color));
	strcpy(arrowTail->color, color);
	arrowTail->isDotted = isDotted;
	arrowTail->posX = posX;
	arrowTail->posY = posY;
	arrowTail->sizeX = sizeX;
	arrowTail->sizeY = sizeY;
	arrowTail->width = width;
	arrowTail->contents = (char *)malloc(sizeof(char) * strlen(contents));
	strcpy(arrowTail->contents, contents);
	
	/* draw it */
	DrawArrow(arrowTail);
	return arrowTail;
}

/* Function: ReadArrow
 * ----------------
 * Read an Arrow from data.
 */
bool ReadArrow(FILE *fp)
{
	bool isDotted;
	int width;
	double posX, posY, sizeX, sizeY;
	char color[20], contents[5];
	if(fscanf(fp, "%d%d%lf%lf%lf%lf%s%s",
			  &isDotted, &width, &posX, &posY, 
			  &sizeX, &sizeY, &color, &contents) != EOF)
			  {
			  		if(strcmp(contents, "X") == 0)	contents[0] = '\0';
					CreateArrow(isDotted, width, posX, posY,
				  				sizeX, sizeY, color, contents);
				  	return TRUE;
			  }
	return FALSE;
}
