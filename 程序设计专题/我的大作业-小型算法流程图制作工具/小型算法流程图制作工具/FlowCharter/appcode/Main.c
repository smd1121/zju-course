#include "myIncludes.h"
#include "shape.h"
#include "arrow.h"
#include "buttons.h"
#include "variables.h"

void initProject();
void DrawAll();
void MouseEventProcess(int x, int y, int button, int event);
void CharEventProcess(char c);
void KeyboardEventProcess(int key,int event);

Shape textBox, inputBox;

void Main()
{
	initProject();
	
	ButtonEvent(1);
	strcpy(textBox.contents, "example");
	ButtonEvent(-1);
}

char thisBgmName[80];
void PlayBGM()
{
#define BGM_NUM 7
	const string bgmName[BGM_NUM] = {"中勾手睡僅匹手.wav", "River Flows In You.wav", "Senbonzakura.wav", 
									 "景誹唗⑻.wav", "貉丹凶中及癡.wav", "漆及��尹月誰.wav", "澱毛及六化.wav"};
	char thisBgmTotName[100] = "../../bgm/";
	strcpy(thisBgmName, bgmName[rand() % BGM_NUM]);
	strcat(thisBgmTotName, thisBgmName);
	PlaySound(thisBgmTotName, NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void initProject()
{
	SetWindowTitle("Flow Charter");
	SetWindowSize(16, 9);
	InitGraphics();
	SetFont("Courier");
	SetFont("Courier New");
	DefineColor("Super Light Gray", .9, .9, .9);
	
	registerCharEvent(CharEventProcess);          
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);       
	
	/* initTextBox 1 - project name */
	textBox.isFilled = FALSE;
	textBox.shapeType = 1;
	textBox.width = 1;
	textBox.posX = GetWindowWidth() * 5 / 6;
	textBox.posY = GetWindowHeight() - 2.3;
	textBox.sizeX = 2;
	textBox.sizeY = 0.5;
	
	/* initTextBox 2 - input */
	inputBox.isFilled = FALSE;
	inputBox.shapeType = 1;
	inputBox.width = 1;
	inputBox.posX = GetWindowWidth() * 5 / 6;
	inputBox.posY = GetWindowHeight() - 5.5;
	inputBox.sizeX = 2;
	inputBox.sizeY = 0.5;
	
	PlayBGM();
	initButtons();
	DrawAll();
}

const string statusMessage[] = 
	{"Welcome", "File created success", "File opened success",			/*  0 ~  2 */
	 "File opened failed: no matching file", "File saved success",		/*  3 ~  4 */
	 "File closed", "Shape copied", "Arrow copied", 					/*  5 ~  7 */
	 "Copy failed: no element selected", "Paste success",				/*  8 ~  9 */
	 "Paste failed: nothing in clipboard", "Delete success",			/* 10 ~ 11 */
	 "Delete failed: no element selected", "Drawing", "Run finished", 	/* 12 ~ 14 */
	 "Error: no 'Start' rounded rectangle", "Debug finished",			/* 15 ~ 16 */
	 "Debug: press F5 to next step, press F11 to run",					/* 17	   */
	 "Format success", "Editing TextBox", "Please input file name", 	/* 18 ~ 20 */
	 "Error: multi 'Start' nodes", "Error: Invalid expression", 		/* 21 ~ 22 */
	 "Waiting for input", "Error: Invalid input"						/* 23 ~ 24 */
	};
	
void DrawAll()
{	
	DisplayClear();
	
	DrawAllShape();
	DrawAllArrow();
	DrawButtons();
	DrawVar();
	
	/* Draw Structure */
	SetPenColor("Violet");
	SetPenSize(2);
	MovePen(0, 0.9);
	DrawLine(GetWindowWidth(), 0);
	SetPenSize(1);
	MovePen(0, 0.42);
	DrawLine(GetWindowWidth(), 0);
	SetPenSize(2);
	MovePen(0.88, GetWindowHeight() - 0.43);
	DrawLine(0, 1.33 - GetWindowHeight());
	MovePen(GetWindowWidth() * 2 / 3, GetWindowHeight() - 0.43);
	DrawLine(0, 1.33 - GetWindowHeight());
	MovePen(0, GetWindowHeight() - 0.43);
	DrawLine(GetWindowWidth(), 0);
	
	/* Sign selected shapes */
	extern Shape *nowShape, *changeTextShape, *runningShape;
	extern int DrawStatus, runningStatus;
	if(nowShape != NULL && DrawStatus != 1)
	{
		Arrow temp = {FALSE, 5, GetWindowWidth() * 2 / 3 + 0.3, nowShape->posY,
					  -0.1, 0, "Black", "", 
					  NULL, NULL, NULL, NULL};
		DrawArrow(&temp);
		MovePen(GetWindowWidth() * 2 / 3 + 0.4, nowShape->posY - 0.05);
		DrawTextString("Now");
		SetPenColor("Super Light Gray");
		MovePen(GetWindowWidth() * 2 / 3, nowShape->posY);
		SetPenSize(1);
		DrawLine(-GetWindowWidth() * 2 / 3 + nowShape->posX + nowShape->sizeX / 2, 0);
	}
	if(changeTextShape != NULL)
	{
		Arrow temp = {FALSE, 5, GetWindowWidth() * 2 / 3 + 0.3, changeTextShape->posY,
					  -0.1, 0, "Black", "", 
					  NULL, NULL, NULL, NULL};
		DrawArrow(&temp);
		MovePen(GetWindowWidth() * 2 / 3 + 0.4, changeTextShape->posY - 0.05);
		DrawTextString("Now");
		SetPenColor("Super Light Gray");
		MovePen(GetWindowWidth() * 2 / 3, changeTextShape->posY);
		SetPenSize(1);
		DrawLine(-GetWindowWidth() * 2 / 3 + changeTextShape->posX + changeTextShape->sizeX / 2, 0);
	}
	if(runningShape != NULL && runningStatus != 0)
	{
		Arrow temp = {FALSE, 5, GetWindowWidth() * 2 / 3 + 0.3, runningShape->posY,
					  -0.1, 0, "Red", "", 
					  NULL, NULL, NULL, NULL};
		DrawArrow(&temp);
		MovePen(GetWindowWidth() * 2 / 3 + 0.4, runningShape->posY - 0.05);
		DrawTextString("Running");
		SetPenColor("Super Light Gray");
		MovePen(GetWindowWidth() * 2 / 3, runningShape->posY);
		SetPenSize(1);
		DrawLine(-GetWindowWidth() * 2 / 3 + runningShape->posX + runningShape->sizeX / 2, 0);
	}
	
	/* Status Message */
	MovePen(GetWindowWidth() * 2 / 3 + 0.1, GetWindowHeight() - 0.3);
	SetPenColor("Black");
	extern int messageStatus;
	DrawTextString(statusMessage[messageStatus]);
	
	/* BGM */
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 0.8);
	DrawTextString("BGM:");
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 1.1);
	SetPenColor("Red");
	DrawTextString(thisBgmName);
	SetPenColor("Black");
	
	/* Textbox 1 - Project name */
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 1.85);
	DrawTextString("Project name:");
	DrawShape(&textBox);
	
	/* Current Project Name */
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 3.5);
	DrawTextString("Current Project Name:");
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 3.8);
	extern char fileName[15];
	SetPenColor("Red");
	DrawTextString(fileName);
	SetPenColor("Black");
	
	/* Textbox 2 - Input */
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 5);
	DrawTextString("Input:");
	DrawShape(&inputBox);
	
	/* Last Input */
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 6.65);
	DrawTextString("Last Input:");
	MovePen(GetWindowWidth() * 2 / 3 + 1.7, GetWindowHeight() - 6.95);
	extern char lastInput[15];
	SetPenColor("Red");
	DrawTextString(lastInput);
	SetPenColor("Black");
}
