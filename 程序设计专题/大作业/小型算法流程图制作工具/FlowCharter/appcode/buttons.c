/* File: buttons.c
 * ---------------
 * Provides the buttons and functions on it.
 */

#include "myIncludes.h"
#include "arrow.h"
#include "shape.h"
#include "variables.h"

#define BUTTON_NUM 47

/* Global Variable: buttons[]
 * -----------
 * This array contains all the buttons needed
 * in the project.
 *
 * buttonStatus: 0 - invisiable, 1 - normal,
 * 2 - overed, 3 - chosen
 */
struct myButtons
{
	bool isFilled;
	int buttonIndex, buttonStatus;
	double posX, posY, sizeX, sizeY;
	string contents, color;
};
struct myButtons buttons[BUTTON_NUM];

/* Global Variables:
 * About Sidebar Buttons
 * ----------------
 * isFilledStatus: TRUE or FALSE.
 *
 * DrawStatus: 0~7. Each for: select, text, rectangle,
 * rounded rectangle, lozenge, parallelogram,
 * arrow, dotted arrow.
 * 
 * SizeStatus: 0~2. Each for: thin, middle, thick.
 * 
 * ColorStatus: one in the color table.
 *
 * ArrowWords: "", "Y" or "N".
 */
bool isFilledStatus = FALSE;
extern int DrawStatus = 0, SizeStatus = 0, messageStatus = 0, fileStatus = 0;
string ColorStatus = "Red", ArrowWords = "";

/* Function Declarations */
void setButton(bool isFilled, int buttonIndex, int buttonStatus,
			   double posX, double posY, double sizeX, double sizeY,
			   string contents, string color);
void initButtons();
void DrawButtons();
void drawSpecialButtons(int index, double posX, double posY);
int SearchButton(double x, double y);
void OverButton(double mx, double my);
void ClickButton(double mx, double my);
void RelatedVisiability(int buttonIndex, int changedStatus);
void ButtonEvent(int index);

/* Function Definitions */

/* Function: setButton
 * -------------------
 * Set buttons[buttonIndex] with given arguments.
 */
void setButton(bool isFilled, int buttonIndex, int buttonStatus,
			   double posX, double posY, double sizeX, double sizeY,
			   string contents, string color)
{
	buttons[buttonIndex].isFilled = isFilled;
	buttons[buttonIndex].buttonIndex = buttonIndex;
	buttons[buttonIndex].buttonStatus =  buttonStatus;
	buttons[buttonIndex].posX = posX;
	buttons[buttonIndex].posY = posY;
	buttons[buttonIndex].sizeX = sizeX;
	buttons[buttonIndex].sizeY = sizeY;
	buttons[buttonIndex].contents = contents;
	buttons[buttonIndex].color = color;
}

/* Function: initButtons()
 * --------------------
 * Set the buttons as their default status.
 */
void initButtons(){
	/* First Level Menu */
	setButton(FALSE, 0, 1, 1.0, GetWindowHeight() - 0.1, 0.6, 0.3, "File", "Gray");
	setButton(FALSE, 1, 1, 1.7, GetWindowHeight() - 0.1, 0.6, 0.3, "Edit", "Gray");
	setButton(FALSE, 2, 1, 2.4, GetWindowHeight() - 0.1, 0.6, 0.3, "Draw", "Gray");
	setButton(FALSE, 3, 1, 3.1, GetWindowHeight() - 0.1, 0.6, 0.3, "Run" , "Gray");
	setButton(FALSE, 4, 1, 3.8, GetWindowHeight() - 0.1, 0.6, 0.3, "More", "Gray");
	
	/* Second Level Menu */
		/* File */
		setButton(FALSE, 5, 0, 1.0, GetWindowHeight() - 0.45, 0.6, 0.3, "New   Ctrl+N", "Gray");
		setButton(FALSE, 6, 0, 1.0, GetWindowHeight() - 0.8 , 0.6, 0.3, "Open  Ctrl+O", "Gray");
		setButton(FALSE, 7, 0, 1.0, GetWindowHeight() - 1.15, 0.6, 0.3, "Save  Ctrl+S", "Gray");
		setButton(FALSE, 8, 0, 1.0, GetWindowHeight() - 1.5 , 0.6, 0.3, "Close Ctrl+W", "Gray");
		setButton(FALSE, 9, 0, 1.0, GetWindowHeight() - 1.85, 0.6, 0.3, "Exit  Alt+F4", "Gray");

		/* Edit */
		setButton(FALSE, 10, 0, 1.7, GetWindowHeight() - 0.45, 0.8, 0.3, "Copy    Ctrl+C", "Gray");
		setButton(FALSE, 11, 0, 1.7, GetWindowHeight() - 0.8 , 0.8, 0.3, "Paste   Ctrl+V", "Gray");
		setButton(FALSE, 12, 0, 1.7, GetWindowHeight() - 1.15, 0.8, 0.3, "Delete  Ctrl+D", "Gray");
		
		/* Draw */
		setButton(FALSE, 13, 0, 2.5, GetWindowHeight() - 0.45, 0.4, 0.3, "", "Gray");
		setButton(FALSE, 14, 0, 2.5, GetWindowHeight() - 0.8 , 0.4, 0.3, "", "Gray");
		setButton(FALSE, 15, 0, 2.5, GetWindowHeight() - 1.15, 0.4, 0.3, "", "Gray");
		setButton(FALSE, 16, 0, 2.5, GetWindowHeight() - 1.5 , 0.4, 0.3, "", "Gray");
		setButton(FALSE, 17, 0, 2.5, GetWindowHeight() - 1.85, 0.4, 0.3, "", "Gray");
		setButton(FALSE, 18, 0, 2.5, GetWindowHeight() - 2.2 , 0.4, 0.3, "", "Gray");
		setButton(FALSE, 19, 0, 2.5, GetWindowHeight() - 2.55, 0.4, 0.3, "", "Gray");
	
		/* Run */
		setButton(FALSE, 20, 0, 3.1, GetWindowHeight() - 0.45, 0.8, 0.3, "Run    F11", "Gray");
		setButton(FALSE, 21, 0, 3.1, GetWindowHeight() - 0.8 , 0.8, 0.3, "Debug  F5" , "Gray");
		setButton(FALSE, 22, 0, 3.1, GetWindowHeight() - 1.15, 0.8, 0.3, "Format F9" , "Gray");
		
		/* More */
		setButton(FALSE, 23, 0, 3.8, GetWindowHeight() - 0.45, 1.5, 0.3, "About&Help"  , "Gray");
		setButton(FALSE, 24, 0, 3.8, GetWindowHeight() - 0.8 , 1.5, 0.3, "Change BGM    F1" , "Gray");
	
	/* First Level Sidebar */
		setButton(FALSE, 25, 3, 0.1 , GetWindowHeight() - 0.7 , 0.6, 0.3, "Draw"  , "White");
		setButton(FALSE, 26, 3, 0.1 , GetWindowHeight() - 3.95, 0.6, 0.3, "Size"  , "White");
		setButton(FALSE, 27, 3, 0.05, GetWindowHeight() - 5.4 , 0.7, 0.3, "Color" , "White");
		setButton(FALSE, 28, 1, 0.02, GetWindowHeight() - 6.8 , 0.8, 0.3, "Filled" , "Gray");
	
	/* Second Level Sidebar */
		/* Draw */
			setButton(FALSE, 29, 1, 0.2, GetWindowHeight() - 1.05, 0.4, 0.3, "", "Gray");
			setButton(FALSE, 30, 1, 0.2, GetWindowHeight() - 1.4 , 0.4, 0.3, "", "Gray");
			setButton(FALSE, 31, 1, 0.2, GetWindowHeight() - 1.75, 0.4, 0.3, "", "Gray");
			setButton(FALSE, 32, 1, 0.2, GetWindowHeight() - 2.1 , 0.4, 0.3, "", "Gray");
			setButton(FALSE, 33, 1, 0.2, GetWindowHeight() - 2.45, 0.4, 0.3, "", "Gray");
			setButton(FALSE, 34, 1, 0.2, GetWindowHeight() - 2.8 , 0.4, 0.3, "", "Gray");
			setButton(FALSE, 35, 1, 0.2, GetWindowHeight() - 3.15, 0.4, 0.3, "", "Gray");
			/* Arrow : Y or N */
				setButton(FALSE, 43, 0, 0.16, GetWindowHeight() - 3.5, 0.2, 0.3, "Y", "Gray");
				setButton(FALSE, 44, 0, 0.44, GetWindowHeight() - 3.5, 0.2, 0.3, "N", "Gray");
		/* Size */
			setButton(FALSE, 36, 3, 0.1, GetWindowHeight() - 4.3 , 0.6, 0.3, "thin" , "Gray");
			setButton(FALSE, 37, 1, 0.1, GetWindowHeight() - 4.65, 0.6, 0.3, "mid"  , "Gray");
			setButton(FALSE, 38, 1, 0.1, GetWindowHeight() - 5.0 , 0.6, 0.3, "wide", "Gray");
		/* Color */
			setButton(FALSE, 39, 3, 0.1, GetWindowHeight() - 5.75, 0.3, 0.3, "", "Red");
			setButton(FALSE, 40, 1, 0.4, GetWindowHeight() - 5.75, 0.3, 0.3, "", "Green");
			setButton(FALSE, 41, 1, 0.1, GetWindowHeight() - 6.05, 0.3, 0.3, "", "Cyan");
			setButton(FALSE, 42, 1, 0.4, GetWindowHeight() - 6.05, 0.3, 0.3, "", "Orange");
	
	/* TextBox */
		setButton(FALSE, 45, 0, GetWindowWidth() * 5 / 6 - 0.1, GetWindowHeight() - 2.8, 0.3, 0.3, "OK", "Gray");
		setButton(FALSE, 46, 0, GetWindowWidth() * 5 / 6 - 0.1, GetWindowHeight() - 6, 0.3, 0.3, "OK", "Gray");
	
	DrawButtons();
}

/* Function: DrawButtons()
 * -----------------------
 * Draw all the buttons.
 */
void DrawButtons(){
	SetPenSize(1);
	
	int i = 0;
	for(; i < BUTTON_NUM; i++){
		if(buttons[i].buttonStatus == 0)	continue;
		if(i == 22)							continue;
		/* rounded rectangle */
		if((i <= 12) || (i >= 20 && i <= 24))
		{
			if(buttons[i].buttonStatus == 1) 		SetPenColor("Gray");
			else if(buttons[i].buttonStatus == 2)	SetPenColor("Light Gray");
			else									SetPenColor(buttons[i].color);
			
			if(buttons[i].buttonStatus != 3) 	
			 	StartFilledRegion(1);
			
			MovePen(buttons[i].posX + buttons[i].sizeX, buttons[i].posY - buttons[i].sizeY/1.5);
			DrawLine(0, buttons[i].sizeY/3.0);
			DrawArc(buttons[i].sizeY/3.0, 0.0, 90.0);
			DrawLine(2*buttons[i].sizeY/3.0 - buttons[i].sizeX, 0);
			DrawArc(buttons[i].sizeY/3.0, 90.0, 90.0);
			DrawLine(0, -buttons[i].sizeY/3.0);
			DrawArc(buttons[i].sizeY/3.0, 180.0, 90.0);
			DrawLine(buttons[i].sizeX - 2*buttons[i].sizeY/3.0, 0);
			DrawArc(buttons[i].sizeY/3.0, 270.0, 90.0);
			
			if(buttons[i].buttonStatus != 3) 	
			 	EndFilledRegion();
		}/* end rounded rectangle*/
		
		/* rectangle */
		else
		{
			if(i >= 39 && i <= 42)	/* color buttons */
			{
				SetPenColor(buttons[i].color);
				
				StartFilledRegion(1);
				
				MovePen(buttons[i].posX, buttons[i].posY);
				DrawLine(buttons[i].sizeX, 0); 
				DrawLine(0, -buttons[i].sizeY); 
				DrawLine(-buttons[i].sizeX, 0); 
				DrawLine(0, buttons[i].sizeY);
				
				EndFilledRegion();
				
				if(buttons[i].buttonStatus != 1)
				{
					if(buttons[i].buttonStatus == 2)	SetPenColor("Light Gray");
					else								SetPenColor("Black");
					
					SetPenSize(2);
					MovePen(buttons[i].posX, buttons[i].posY);
					DrawLine(buttons[i].sizeX, 0); 
					DrawLine(0, -buttons[i].sizeY); 
					DrawLine(-buttons[i].sizeX, 0); 
					DrawLine(0, buttons[i].sizeY);
					SetPenSize(1);
				}
			}
			
			else /* others */
			{
				if(buttons[i].buttonStatus == 1) 		SetPenColor("Light Gray");
				else if(buttons[i].buttonStatus == 2)	SetPenColor("Super Light Gray");
				else									SetPenColor(buttons[i].color);
			
				if(buttons[i].buttonStatus != 3) 		
					StartFilledRegion(1);
				
				MovePen(buttons[i].posX, buttons[i].posY);
				DrawLine(buttons[i].sizeX, 0); 
				DrawLine(0, -buttons[i].sizeY); 
				DrawLine(-buttons[i].sizeX, 0); 
				DrawLine(0, buttons[i].sizeY);
				
				if(buttons[i].buttonStatus != 3) 	
				 	EndFilledRegion();
			}
		}/* end rectangle */
		
		/* text */
		SetPenColor("Black");
		MovePen(buttons[i].posX + buttons[i].sizeX/6.0, buttons[i].posY - buttons[i].sizeY / 2.0 - 0.05);
		DrawTextString(buttons[i].contents);
		
		/* special buttons */
		if(i >= 13 && i <= 19)
			drawSpecialButtons(i - 13, buttons[i].posX + buttons[i].sizeX/2.0, buttons[i].posY - buttons[i].sizeY/2.0);
		if(i >= 29 && i <= 35)
			drawSpecialButtons(i - 29, buttons[i].posX + buttons[i].sizeX/2.0, buttons[i].posY - buttons[i].sizeY/2.0);
	}
}

/* Function: drawSpecialButtons
 * ----------------------------
 * There are several buttons that has
 * special shapes in it. This function
 * is used to draw these shapes.
 */
void drawSpecialButtons(int index, double posX, double posY)
{
	switch(index)
	{
		/* mouse */
		case 0:
			{
				SetPenColor("Black");
				MovePen(posX - 0.05, posY - 0.05);
				DrawTextString("A");
				break;
			}
		/* rectangle, rounded rectangle, lozenge and parallelogram */
		case 1: case 2: case 3: case 4:
			{
				Shape temp = {FALSE, index, 1, posX, posY,
							  0.2 + index * 0.05, 0.2};
				temp.color = (char*)malloc(sizeof(char) * 6);
				strcpy(temp.color, "Black");
				DrawShape(&temp);
				break;					  
			}
		/* arrow, dotted arrow */
		case 5: case 6:
			{
				Arrow temp = {(index + 1) % 2, 2, posX-0.15, posY,
							  0.2 + 0.05*(index%2), 0, "Black", "", 
							  NULL, NULL, NULL, NULL};
				DrawArrow(&temp);
				break;
			}
		default: 
			break;
	}
}

/* Function: SearchButton
 * ----------------------
 * Given (x, y), search a visiable button
 * that contains this point.
 * If there is not, return -1.
 */
int SearchButton(double x, double y)
{
	int i = 0;
	for(; i < BUTTON_NUM; i++)
		if(x >= buttons[i].posX && x <= buttons[i].posX + buttons[i].sizeX
		 &&y >= buttons[i].posY - buttons[i].sizeY && y <= buttons[i].posY)
		 	return i;
	return -1;
}

/* Function: OverButton
 * --------------------
 * Change the status of the button overed
 * by mouse, meanwhile reset the original
 * overed button to normal status.
 */
void OverButton(double mx, double my)
{
	int i = 0;
	for(; i < BUTTON_NUM; i++)
		if(buttons[i].buttonStatus == 2)
			buttons[i].buttonStatus = 1;
	int OveredButton = SearchButton(mx, my);
	if(OveredButton != -1 && buttons[OveredButton].buttonStatus == 1)
		buttons[OveredButton].buttonStatus = 2;
}

/* Function: ClickButton
 * ---------------------
 * When a click happens, check whether there is
 * a button selected. If there is, change the 
 * status and the global variables related.
 */
void ClickButton(double mx, double my)
{
	int ClickedButton = SearchButton(mx, my);
	
	/* If there is no button clicked or the clicked button is
	   invisiable, close all the drop-down menus and return.*/
	if(ClickedButton == -1 || buttons[ClickedButton].buttonStatus == 0)
	{
		RelatedVisiability(0, 1);
		return;
	}
	
	RelatedVisiability(ClickedButton, 3);
	
	if(ClickedButton >= 5 && ClickedButton <= 24)
		ButtonEvent(ClickedButton - 5);
	else if(ClickedButton == 45)
		ButtonEvent(-1);
	else if(ClickedButton == 46)
		ButtonEvent(20);
}

/* Function: RelatedVisiability
 * ----------------------------
 * Given a change on the status of a button, 
 * automatically change the status of its 
 * related buttons.
 */
void RelatedVisiability(int buttonIndex, int changedStatus)
{
	int i;
	/* Close all the drop-down menus */
	for(i = 0; i <= 4; i++)
		buttons[i].buttonStatus = 1;
	for(i = 5; i <= 24; i++)
		buttons[i].buttonStatus = 0;
	
	/* TextBox */
	if(buttonIndex == 45)	return;
	
	/* Menus */
	if(changedStatus == 3 && buttonIndex <= 4)
	{
		buttons[buttonIndex].buttonStatus = 3;
		switch(buttonIndex)
		{
			case 0:
				for(i = 5; i <= 9; i++)
					buttons[i].buttonStatus = 1;
				break;
			case 1:
				for(i = 10; i <= 12; i++)
					buttons[i].buttonStatus = 1;
				break;
			case 2:
				for(i = 13; i <= 19; i++)
					buttons[i].buttonStatus = buttons[i + 16].buttonStatus;
				break;
			case 3:
				for(i = 20; i <= 22; i++)
					buttons[i].buttonStatus = 1;
				break;
			case 4:
				for(i = 23; i <= 24; i++)
					buttons[i].buttonStatus = 1;
				break;
		}
	}
	
	/* Sidebar */
	if(changedStatus == 3 && buttonIndex >= 28)
	{
		/* isFilledStatus */
		if(buttonIndex == 28)
		{
			if(buttons[28].buttonStatus != 3)
			{
				isFilledStatus = TRUE;
				buttons[buttonIndex].buttonStatus = 3;
			}
			else
			{
				isFilledStatus = FALSE;
				buttons[buttonIndex].buttonStatus = 1;
			}
		}
		/* DrawStatus */
		else if(buttonIndex <= 35)
		{
			messageStatus = 13;
			if(buttons[buttonIndex].buttonStatus == 3)
			{
				DrawStatus = 0;
				
				for(i = 29; i <= 35; i++)
					buttons[i].buttonStatus = 1;
					
				buttons[43].buttonStatus = 0;
				buttons[44].buttonStatus = 0;
			}
			else
			{
				DrawStatus = buttonIndex - 28;
			
				for(i = 29; i <= 35; i++)
					buttons[i].buttonStatus = 1;
				
				if(buttonIndex == 34 || buttonIndex == 35)
				{
					buttons[43].buttonStatus = 1;
					buttons[44].buttonStatus = 1;
					if(strcmp(ArrowWords, "Y") == 0)
						buttons[43].buttonStatus = 3;
					if(strcmp(ArrowWords, "N") == 0)
						buttons[44].buttonStatus = 3;
				}
				else
				{
					buttons[43].buttonStatus = 0;
					buttons[44].buttonStatus = 0;
				}
			
				buttons[buttonIndex].buttonStatus = 3;
			}
		}
		/* SizeStatus */
		else if(buttonIndex <= 38)
		{
			SizeStatus = buttonIndex - 35;
			
			for(i = 36; i <= 38; i++)
				buttons[i].buttonStatus = 1;
				
			buttons[buttonIndex].buttonStatus = 3;
		}
		/* ColorStatus */
		else if(buttonIndex <= 42)
		{
			ColorStatus = buttons[buttonIndex].color;
			
			for(i = 39; i <= 42; i++)
				buttons[i].buttonStatus = 1;
				
			buttons[buttonIndex].buttonStatus = 3;
		}
		else
		{
			if(buttons[buttonIndex].buttonStatus == 3)
			{
				ArrowWords = "";
				buttons[buttonIndex].buttonStatus = 1;
			}
			else if(buttonIndex == 43)
			{
				ArrowWords = "Y";
				buttons[43].buttonStatus = 3;
				buttons[44].buttonStatus = 1;
			}
			else
			{
				ArrowWords = "N";
				buttons[43].buttonStatus = 1;
				buttons[44].buttonStatus = 3;
			}
		}
	}
} 

/* Function: ButtonEvent
 * ----------------------
 * All the event of drop-down menus
 * and short cut keys.
 */
char fileName[15] = "", lastInput[15] = "";
extern Shape textBox, inputBox;
extern int runningStatus;
void ButtonEvent(int index)
{
	extern Shape *nowShape;
	extern Arrow *nowArrow;
	
	buttons[45].buttonStatus = 0;
	if(runningStatus != 3) 	buttons[46].buttonStatus = 0;
	else					buttons[46].buttonStatus = 1;
	
	switch(index)
	{
		/* File - Textbox */
		case -1:
			strcpy(fileName, textBox.contents);
			switch(fileStatus)
			{
				case 1:	/* New */
					messageStatus = 1;
					break;
				
				case 2: /* Open */
				{
					char shapeFileName[50] = "./data/";
					strcat(shapeFileName, fileName);
					strcat(shapeFileName, "/shape.flowcharter");
					FILE *fpReadS = fopen(shapeFileName, "r");
					
					char arrowFileName[50] = "./data/";
					strcat(arrowFileName, fileName);
					strcat(arrowFileName, "/arrow.flowcharter");
					FILE *fpReadA = fopen(arrowFileName, "r");
					
					if(fpReadS == NULL || fpReadA == NULL)
					{
						strcpy(fileName, "");
						messageStatus = 3;
					}
					else
					{
						while(ReadShape(fpReadS)){};
						while(ReadArrow(fpReadA)){};
						messageStatus = 2;
					}
					
					fclose(fpReadS);
					fclose(fpReadA);
					break;
				} 
				default:
					break;
			}
			break;
			
		/* File - New & Open */
		case 0:	case 1:
			ButtonEvent(2);
			ButtonEvent(3);
			messageStatus = 20;
			buttons[45].buttonStatus = 1;
			fileStatus = index + 1;
			break;
		
		/* File - Save */
		case 2:	
			;
			mkdir("data");
			char dataFolder[50] = "data/";
			strcat(dataFolder, fileName);
			mkdir(dataFolder);
			
			char shapeFileName[50] = "./data/";
			strcat(shapeFileName, fileName);
			strcat(shapeFileName, "/shape.flowcharter");
			FILE *fpReadS = fopen(shapeFileName, "w");
					
			char arrowFileName[50] = "./data/";
			strcat(arrowFileName, fileName);
			strcat(arrowFileName, "/arrow.flowcharter");
			FILE *fpReadA = fopen(arrowFileName, "w");
			
			SaveAllShape(fpReadS);
			SaveAllArrow(fpReadA);
			
			fclose(fpReadS);
			fclose(fpReadA);
			
			messageStatus = 4;
			break;
			
		/* File - Close */
		/* Delete all shapes, arrows and variables */
		case 3:	
			{
				Shape *tempS;
				while(shapeTail != NULL)
				{
					tempS = shapeTail;
					shapeTail = shapeTail->last;
					free(tempS);
				}
				shapeTail = shapeHead = NULL;
				
				Arrow *tempA;
				while(arrowTail != NULL)
				{
					tempA = arrowTail;
					arrowTail = arrowTail->last;
					free(tempA);
				}
				arrowTail = arrowHead = NULL;
				
				Var *tempV;
				while(varHead != NULL)
				{
					tempV = varHead;
					varHead = varHead->next;
					free(tempV);
				}
				varTail = varHead = NULL;
				
				strcpy(fileName, "");
				
				messageStatus = 5;
				break;	
			}
			
		
		/* File - Exit */
		case 4:	
			exit(0);
			break;
	
		/* Edit - Copy */
		case 5:
			if(nowShape != NULL)
			{
				FILE *fp = fopen("clipboard.flowcharter", "w");
				fprintf(fp, "S ");
				nowShape->posX += 0.1, nowShape->posY += 0.1;
				SaveShape(fp, nowShape);
				nowShape->posX -= 0.1, nowShape->posY -= 0.1;
				fclose(fp);
				messageStatus = 6;
			}
			else if(nowArrow != NULL)
			{
				FILE *fp = fopen("clipboard.flowcharter", "w");
				fprintf(fp, "A ");
				nowArrow->posX += 0.1, nowArrow->posY += 0.1;
				SaveArrow(fp, nowArrow);
				nowArrow->posX -= 0.1, nowArrow->posY -= 0.1;
				fclose(fp);
				messageStatus = 7;
			}
			else	messageStatus = 8;
			break;
		
		/* Edit - Paste */
		case 6:	
			{
				FILE *fp = fopen("clipboard.flowcharter", "r");
				char type = fgetc(fp);
				while(type != 'A' && type != 'S' && type != EOF)
					type = fgetc(fp);
				
				if(type == EOF)
				{
					messageStatus = 10;
					break;
				}
				
				messageStatus = 9;
				
				if(type == 'S')
					ReadShape(fp);
				else if(type == 'A')
					ReadArrow(fp);
				else
					messageStatus = 10;
					
				fclose(fp);
				break;
			}
		
		/* Edit - Delete */
		case 7:	
			messageStatus = 11;
			if(nowShape != NULL)
			{
				if(nowShape->last != NULL)
					nowShape->last->next = nowShape->next;
				else
					shapeHead = nowShape->next;
				
				if(nowShape->next != NULL)
					nowShape->next->last = nowShape->last;
				else
					shapeTail = nowShape->last;
				
				free(nowShape);
			}
			else if(nowArrow != NULL)
			{
				if(nowArrow->last != NULL)
					nowArrow->last->next = nowArrow->next;
				else
					arrowHead = nowArrow->next;
				
				if(nowArrow->next != NULL)
					nowArrow->next->last = nowArrow->last;
				else
					arrowTail = nowArrow->last;
				
				free(nowArrow);
			}
			else
				messageStatus = 12;
			break;
			
		/* Draw - 7 kind of graphz */
		case 8: case 9: case 10:
		case 11: case 12: case 13: case 14:
			RelatedVisiability(index + 21, 3);
			break;
		
		/* Run - Run */
		case 15:
			if(runningStatus == 0)
			{
				if(initRunner())
				{
					runningStatus = 2;
					messageStatus = 17;
				}
				else
				{
					messageStatus = 15;
					break;
				}
				while(runningStatus == 1 || runningStatus == 2)
				{
					ButtonEvent(16);
				}
			}
			else
			{
				while(runningStatus == 1 || runningStatus == 2)
					ButtonEvent(16);
			}
			messageStatus = 14;
			break;
		
		/* Run - Debug */
		case 16:
			if(runningStatus == 0)
			{
				if(initRunner())
				{
					runningStatus = 2;
					messageStatus = 17;
				}
				else
					messageStatus = 15;
			}
			else
			{
				if(runningStatus == 3)	break;
				int tempStatus = nextStep();
				switch(tempStatus)
				{
					case 0: /* success */
						runningStatus = 2;
						messageStatus = 17;
						break;
						
					case -3: /* multi "START" nodes */
						runningStatus = 0;
						messageStatus = 21;
						break;
						
					case -2: /* running Shape is NULL */
						runningStatus = 0;
						messageStatus = 16;
						break;
						
					case -1: /* invalid expression */
						runningStatus = 0;
						messageStatus = 22;
						break;
						
					case 1: /* no next shape */
						runningStatus = 0;
						messageStatus = 16;
						break;
						
					case 2: /* waiting for input */
						runningStatus = 3;
						messageStatus = 23;
						break;
						
					default:
						runningStatus = 0;
						messageStatus = 16;
						break;
						
				}
			}
			break;
			
		/* Run - Format */
		case 17:
			break;
		
		/* More - Help */
		case 18:
			system("help.pdf");
			break;
		
		/* More - ChangeBGM */
		case 19:
			PlayBGM();
			break;
		
		/* Input */
		case 20:
			strcpy(lastInput, inputBox.contents);
			if(runningStatus == 3)
			{
				extern char inputVar[100];
				strcat(inputVar, "=");
				strcat(inputVar, lastInput);
				if(LexcialAnalisis(inputVar) == FALSE)
				{
					runningStatus = 0;
					messageStatus = 24;
				}
				else
				{
					FILE *fp = fopen("lexAnaLog.flowcharter", "r");
					char variable[20], op[3];
					double value;
					fscanf(fp, "%s%s%lf", variable, op, &value);
					fclose(fp);
					Var *nowVar = searchVar(variable);
					if(nowVar == NULL)	break;
					nowVar->value = value;
					
					extern Shape *runningShape;
					ArrowPair tempAP = SearchArrowPair(runningShape);
					if(tempAP.arrowOne == NULL)
					{
						runningStatus = 0;
						messageStatus = 16;
						break;
					}
					else
					{
						Shape *tempS = SearchShape(tempAP.arrowOne->posX + tempAP.arrowOne->sizeX
												  ,tempAP.arrowOne->posY + tempAP.arrowOne->sizeY);
						if(tempS == NULL)
						{
							runningStatus = 0;
							messageStatus = 16;
							break;
						}
						else
						{
							runningShape = tempS;
							runningStatus = 2;
							messageStatus = 17;
							break;
						}
					}
				}
			}
			break;
		
		default:
			break;
	}
	DrawAll();
}
