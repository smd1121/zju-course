#include "myIncludes.h"
#include "shape.h"
#include "arrow.h"
#include "buttons.h"

#define DRAW_AREA_LEFT 0.88
#define DRAW_AREA_BOTTOM 0.9
#define DRAW_AREA_RIGHT (GetWindowWidth() * 2 / 3)
#define DRAW_AREA_HEIGHT (GetWindowHeight() - 0.43)

extern bool isFilledStatus, isGettingStr;
extern int DrawStatus, SizeStatus;
extern string ColorStatus, ArrowWords;

/* change contents */
extern Shape *changeTextShape;
void CharEventProcess(char c);

/* change pos & size */
Shape *nowShape;
Arrow *nowArrow;

void MouseEventProcess(int x, int y, int button, int event)
{	
	static double omx = 0.0, omy = 0.0;					/*old mouse coordinate in inches*/
	double mx = ScaleXInches(x), my = ScaleYInches(y);	/*pixels --> inches*/
	
	/* part 0 - TextBox */
	extern Shape textBox, inputBox;
	extern bool isEditingTextBox, isEditingInput;
	extern int messageStatus;
	if(InShape(&textBox, mx, my) && event == BUTTON_DOWN && button == LEFT_BUTTON)
	{
		messageStatus = 19;
		isEditingTextBox = TRUE;
	}
	else if(!InShape(&textBox, mx, my) && event == BUTTON_DOWN && button == LEFT_BUTTON && isEditingTextBox)
	{
		messageStatus = 0;
		isEditingTextBox = FALSE;
	}
	
	if(InShape(&inputBox, mx, my) && event == BUTTON_DOWN && button == LEFT_BUTTON)
	{
		messageStatus = 19;
		isEditingInput = TRUE;
	}
	else if(!InShape(&inputBox, mx, my) && event == BUTTON_DOWN && button == LEFT_BUTTON && isEditingTextBox)
	{
		messageStatus = 0;
		isEditingInput = FALSE;
	}
	/* End of part 0 */
	
	/* part 1 - Button Operation */
	if(event == BUTTON_DOWN && button == LEFT_BUTTON)
		ClickButton(mx, my);
	else if(event == MOUSEMOVE)
		OverButton(mx, my);
	/* End of part 1 */
		
	/* part 2 - change shape contents */
	Shape *temp = SearchShape(mx, my);
	if(DrawStatus == 1)
	{
		if(event == BUTTON_DOWN && changeTextShape != temp)
			CharEventProcess('\n');
		if(event == BUTTON_DOWN && button == LEFT_BUTTON)
			changeTextShape = temp;
	}
	else if(event == BUTTON_DOWN && changeTextShape != temp)
		CharEventProcess('\n');
		
	/* part 3 - Select: Change position & size */
	static bool isChangeSize = FALSE, isMove = FALSE;
	if(DrawStatus == 0)
	{	
		/* Ignore operations out of draw area*/
		if(mx <= DRAW_AREA_LEFT  || mx >= DRAW_AREA_RIGHT
		 ||my <= DRAW_AREA_BOTTOM|| my >= DRAW_AREA_HEIGHT)
		{
		 	omx = mx;
		 	omy = my;
		 	DrawAll();
		 	return;
		}
		
		switch(event)
		{
			case BUTTON_DOWN:
				isChangeSize = FALSE;
				isMove = FALSE;
				/* left button down: change position */
				if(button == LEFT_BUTTON)
				{
					nowShape = SearchShape(mx, my);
					nowArrow = SearchArrow(mx, my);
					if(nowShape != NULL || nowArrow != NULL) isMove = TRUE;
				}
				/* right button down: change size */
				else if(button == RIGHT_BUTTON)
				{
					nowShape = SearchShape(mx, my);
					nowArrow = SearchArrow(mx, my);
					if(nowShape != NULL || nowArrow != NULL) isChangeSize = TRUE;
				}
				omx = mx; omy = my;
				break;
				
			case BUTTON_UP:
				isChangeSize = FALSE;
				isMove = FALSE;
				break;
				
			case MOUSEMOVE:
				if(isChangeSize == FALSE && isMove == FALSE)	break;
				/* change position */
				if(isMove) 
				{
					if(nowArrow != NULL)
					{
						if(nowArrow->posX + mx - omx <= DRAW_AREA_LEFT   
						|| nowArrow->posX + mx - omx >= DRAW_AREA_RIGHT
						|| nowArrow->posY + my - omy <= DRAW_AREA_BOTTOM 
						|| nowArrow->posY + my - omy >= DRAW_AREA_HEIGHT
						|| nowArrow->posX + mx - omx + nowArrow->sizeX <= DRAW_AREA_LEFT   
						|| nowArrow->posX + mx - omx + nowArrow->sizeX >= DRAW_AREA_RIGHT
						|| nowArrow->posY + my - omy + nowArrow->sizeY <= DRAW_AREA_BOTTOM 
						|| nowArrow->posY + my - omy + nowArrow->sizeY >= DRAW_AREA_HEIGHT)
						{
							omx = mx;
							omy = my;
							break;
						}
						else
						{
							nowArrow->posX += mx - omx;
			                nowArrow->posY += my - omy;
							omx = mx;
							omy = my;
							break;
						}
					}
					else if(nowShape != NULL)
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
						else
						{
							nowShape->posX += mx - omx;
			                nowShape->posY += my - omy;
							omx = mx;
							omy = my;
							break;
						}
					}
				}
				/* change size */
				else if(isChangeSize) 
				{
					if(nowArrow != NULL)
	                {
						nowArrow->sizeX += mx - omx;
						nowArrow->sizeY += my - omy;
						omx = mx;
						omy = my;
						break;
	                }
					else if(nowShape != NULL)
					{
						nowShape->sizeX += mx - omx;
	                	nowShape->sizeY -= my - omy;
	                	omx = mx;
						omy = my;
						break;
					}
				}
	            break;
	            
	        default:
	        	break;
		}
	}
	/* End of part 3 */
	
	/* part 4 - Draw New Shape */
	static bool isDrawing = FALSE;
	if(DrawStatus >= 2 && DrawStatus <= 5)
	{
		/* Ignore operations out of draw area*/
		if(mx <= DRAW_AREA_LEFT  || mx >= DRAW_AREA_RIGHT
		 ||my <= DRAW_AREA_BOTTOM|| my >= DRAW_AREA_HEIGHT)
		{
		 	omx = mx;
		 	omy = my;
		 	DrawAll();
		 	return;
		}
		
		switch(event)
		{
			case BUTTON_DOWN:
				/* left button down: create new Shape */
				if(button == LEFT_BUTTON)
				{
					isDrawing = TRUE;
					if(DrawStatus == 3)
						nowShape = CreateShape(isFilledStatus, DrawStatus - 1, SizeStatus,
						 		    		   mx, my, 0, 0, ColorStatus, "START");
					else
						nowShape = CreateShape(isFilledStatus, DrawStatus - 1, SizeStatus,
						 		    		   mx, my, 0, 0, ColorStatus, "");
				}
				omx = mx; omy = my;
				break;
				
			case BUTTON_UP:
				isDrawing = FALSE;
				break;
				
			case MOUSEMOVE:
				if(isDrawing == FALSE || nowShape == NULL)	break;
				nowShape->sizeX += mx - omx;
	        	nowShape->sizeY -= my - omy;
	        	omx = mx;
				omy = my;
				break;
	            
	        default:
	        	break;
		}
	}
	/* End of part 4 */
	
	/* part 5 - Draw New Arrow */
	static bool isLining = FALSE;
	if(DrawStatus == 6 || DrawStatus == 7)
	{
		/* Ignore operations out of draw area*/
		if(mx <= DRAW_AREA_LEFT  || mx >= DRAW_AREA_RIGHT
		 ||my <= DRAW_AREA_BOTTOM|| my >= DRAW_AREA_HEIGHT)
		{
		 	omx = mx;
		 	omy = my;
		 	DrawAll();
		 	return;
		}
		
		switch(event)
		{
			case BUTTON_DOWN:
				/* left button down: create new Arrow */
				if(button == LEFT_BUTTON)
				{
					isLining = TRUE;
					nowArrow = CreateArrow(DrawStatus % 2, SizeStatus, mx, my, 0.2, 0.2, ColorStatus, ArrowWords);
				}
				omx = mx; omy = my;
				break;
				
			case BUTTON_UP:
				isLining = FALSE;
				break;
				
			case MOUSEMOVE:
				if(isLining == FALSE || nowArrow == NULL)	break;
				nowArrow->sizeX += mx - omx;
	        	nowArrow->sizeY += my - omy;
	        	omx = mx;
				omy = my;
				break;
	            
	        default:
	        	break;
		}
	}
	/* End of part 5 */
		
	DrawAll();
}
