/* File: graphEvent.c
 * ------------------
 * This file provides the interaction
 * about shapes and arrows.
 */
#include "arrow.h"
#include "shape.h"

#define DRAW_AREA_LEFT 0.88
#define DRAW_AREA_BOTTOM 0.9
#define DRAW_AREA_RIGHT (GetWindowWidth() - 0.2)
#define DRAW_AREA_HEIGHT (GetWindowHeight() - 0.43)

double omx = 0.0, omy = 0.0;	/*old mouse coordinate in inches*/

void GraphMouseEvent(int x, int y, int button, int event)
{
	Shape *nowShape;
	static bool isChangeSize = FALSE, isMove = FALSE;
	double mx = ScaleXInches(x), my = ScaleYInches(y);	/*pixels --> inches*/
	switch(event)
	{
		case BUTTON_DOWN:
			isChangeSize = FALSE;
			isMove = FALSE;
			if(button == LEFT_BUTTON)
			{
				nowShape = SearchShape(mx, my);
				if(nowShape != NULL) isChangeSize = TRUE;
			}
			else if(button == RIGHT_BUTTON)
			{
				nowShape = SearchShape(mx, my);
				if(nowShape != NULL) isMove = TRUE;
			}
			omx = mx; omy = my;
			break;
		case BUTTON_UP:
			isChangeSize = FALSE;
			isMove = FALSE;
			break;
		case MOUSEMOVE:
			OverButton(mx, my);
			if(nowShape == NULL)	break;
			if(isMove) 
			{
                if(nowShape->posX + mx - omx - nowShape->sizeX/2.0 <= DRAW_AREA_LEFT
				|| nowShape->posY + my - omy - nowShape->sizeY/2.0 <= DRAW_AREA_BOTTOM
				|| nowShape->posX + mx - omx + nowShape->sizeX/2.0 >= DRAW_AREA_RIGHT
				|| nowShape->posY + my - omy + nowShape->sizeY/2.0 >= DRAW_AREA_HEIGHT)
				{
					omx = mx;
					omy = my;
					break;
				}
				nowShape->posX += mx - omx;
                nowShape->posY += my - omy;
				omx = mx;
				omy = my;
			}
			else if(isChangeSize) 
			{
            	DisplayClear();
                nowShape->sizeX += mx - omx;
                nowShape->sizeY += my - omy;
				omx = mx;
				omy = my;
			}
            break;
        case BUTTON_DOUBLECLICK:
			break;
	}
	DrawAll();
}
