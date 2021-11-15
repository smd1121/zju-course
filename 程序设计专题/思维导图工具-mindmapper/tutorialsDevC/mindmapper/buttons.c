#include "myHeader.h"

int overedButton = 0;
int mode = 0;

struct button buttons[2][BUTTON_NUM] = 
{
	{
		{0,  1.0, 8.85, 2.0, 0.3, "存储到文件 Ctrl+S", "Gray", "Green"}, 
		{1,  5.5, 8.85, 2.0, 0.3, "从文件读取 Ctrl+O", "Gray", "Green"},
		{2,  7.5, 8.85, 2.0, 0.3, "移动画布 Ctrl+M", "Gray", "Green"},
		
		{3, 13.5, 8.20, 2.0, 0.5, "收起子树 Ctrl+F", "Gray", "Green"},
		{4, 13.5, 7.60, 2.0, 0.5, "新建子结点 Ctrl+N", "Gray", "Green"},
		{5, 13.5, 7.00, 2.0, 0.5, "删除结点及子树 Ctrl+D", "Gray", "Green"},
		{6, 12.95, 6.20, 1.0, 0.5, "填充", "Gray", "Green"},
		{7, 14.05, 6.20, 1.0, 0.5, "不填充", "Gray", "Green"},
		
		{8, 13.5, 5.6, 1.5, 0.5, "文字颜色", "Light Gray", "Light Gray"},
		{9, 12.4, 5.25, 0.2, 0.2, "", "Pink", "Pink"},
		{10, 12.7, 5.25, 0.2, 0.2, "", "Black", "Black"},
		{11, 13.0, 5.25, 0.2, 0.2, "", "Red", "Red"},
		{12, 13.3, 5.25, 0.2, 0.2, "", "Yellow", "Yellow"},
		{13, 13.7, 5.25, 0.2, 0.2, "", "Orange", "Orange"},
		{14, 14.0, 5.25, 0.2, 0.2, "", "Green", "Green"},
		{15, 14.3, 5.25, 0.2, 0.2, "", "White", "White"},
		{16, 14.6, 5.25, 0.2, 0.2, "", "Cyan", "Cyan"},
		
		{17, 13.5, 4.7, 1.5, 0.5, "边框及填充颜色", "Light Gray", "Light Gray"},
		{18, 12.4, 4.35, 0.2, 0.2, "", "Pink", "Pink"},
		{19, 12.7, 4.35, 0.2, 0.2, "", "Black", "Black"},
		{20, 13.0, 4.35, 0.2, 0.2, "", "Red", "Red"},
		{21, 13.3, 4.35, 0.2, 0.2, "", "Yellow", "Yellow"},
		{22, 13.7, 4.35, 0.2, 0.2, "", "Orange", "Orange"},
		{23, 14.0, 4.35, 0.2, 0.2, "", "Green", "Green"},
		{24, 14.3, 4.35, 0.2, 0.2, "", "White", "White"},
		{25, 14.6, 4.35, 0.2, 0.2, "", "Cyan", "Cyan"},
		
		{26, 13.5, 3.8, 1.5, 0.5, "线条颜色", "Light Gray", "Light Gray"},
		{27, 12.4, 3.45, 0.2, 0.2, "", "Pink", "Pink"},
		{28, 12.7, 3.45, 0.2, 0.2, "", "Black", "Black"},
		{29, 13.0, 3.45, 0.2, 0.2, "", "Red", "Red"},
		{30, 13.3, 3.45, 0.2, 0.2, "", "Yellow", "Yellow"},
		{31, 13.7, 3.45, 0.2, 0.2, "", "Orange", "Orange"},
		{32, 14.0, 3.45, 0.2, 0.2, "", "Green", "Green"},
		{33, 14.3, 3.45, 0.2, 0.2, "", "White", "White"},
		{34, 14.6, 3.45, 0.2, 0.2, "", "Cyan", "Cyan"},
		
		{35, 13.5, 3, 1.5, 0.5, "结点形状", "Light Gray", "Light Gray"},
		{36, 12.95, 2.55, 1.0, 0.5, "矩形", "Gray", "Green"},
		{37, 14.05, 2.55, 1.0, 0.5, "圆角矩形", "Gray", "Green"},
		
		{38, 13.5, 2.05, 1.5, 0.5, "边框宽度", "Light Gray", "Light Gray"},
		{39, 12.85, 1.65, 0.5, 0.4, "1", "Gray", "Green"},
		{40, 13.5, 1.65, 0.5, 0.4, "2", "Gray", "Green"},
		{41, 14.15, 1.65, 0.5, 0.4, "3", "Gray", "Green"}, 
		
		{42,  9.25, 8.85, 1.5, 0.3, "模式一", "Gray", "Green" },
		{43,  10.75, 8.85, 1.5, 0.3, "模式二", "Gray", "Green" },
		
		{44, 13.5, 8.75, 2.5, 0.3, "", "Light Gray", "Light Gray"},
		{45, 3.25, 8.85, 2.5, 0.3, "存储到二进制文件 Ctrl+B", "Gray", "Green"}
	},
	{
		{0,  1.0, 8.85, 2.0, 0.3, "存储到文件 Ctrl+S", "Black", "Black"}, 
		{1,  5.5, 8.85, 2.0, 0.3, "从文件读取 Ctrl+O", "Black", "Black"},
		{2,  7.5, 8.85, 2.0, 0.3, "移动画布 Ctrl+M", "Black", "Black"},
		
		{3, 13.5, 8.20, 1.5, 0.5, "收起子树 Ctrl+F", "Black", "Black"},
		{4, 13.5, 7.60, 1.5, 0.5, "新建子结点 Ctrl+N", "Black", "Black"},
		{5, 13.5, 7.00, 1.5, 0.5, "删除结点及子树 Ctrl+D", "Black", "Black"},
		{6, 12.95, 6.20, 1.0, 0.5, "填充", "Black", "Black"},
		{7, 14.05, 6.20, 1.0, 0.5, "不填充", "Black", "Black"},
		
		{8, 13.5, 5.6, 1.5, 0.5, "文字颜色", "Black", "Black"},
		{9, 12.4, 5.25, 0.2, 0.2, "", "Pink", "Pink"},
		{10, 12.7, 5.25, 0.2, 0.2, "", "Black", "Black"},
		{11, 13.0, 5.25, 0.2, 0.2, "", "Red", "Red"},
		{12, 13.3, 5.25, 0.2, 0.2, "", "Yellow", "Yellow"},
		{13, 13.7, 5.25, 0.2, 0.2, "", "Orange", "Orange"},
		{14, 14.0, 5.25, 0.2, 0.2, "", "Green", "Green"},
		{15, 14.3, 5.25, 0.2, 0.2, "", "White", "White"},
		{16, 14.6, 5.25, 0.2, 0.2, "", "Cyan", "Cyan"},
		
		{17, 13.5, 4.7, 1.5, 0.5, "边框及填充颜色", "Black", "Black"},
		{18, 12.4, 4.35, 0.2, 0.2, "", "Pink", "Pink"},
		{19, 12.7, 4.35, 0.2, 0.2, "", "Black", "Black"},
		{20, 13.0, 4.35, 0.2, 0.2, "", "Red", "Red"},
		{21, 13.3, 4.35, 0.2, 0.2, "", "Yellow", "Yellow"},
		{22, 13.7, 4.35, 0.2, 0.2, "", "Orange", "Orange"},
		{23, 14.0, 4.35, 0.2, 0.2, "", "Green", "Green"},
		{24, 14.3, 4.35, 0.2, 0.2, "", "White", "White"},
		{25, 14.6, 4.35, 0.2, 0.2, "", "Cyan", "Cyan"},
		
		{26, 13.5, 3.8, 1.5, 0.5, "线条颜色", "Black", "Black"},
		{27, 12.4, 3.45, 0.2, 0.2, "", "Pink", "Pink"},
		{28, 12.7, 3.45, 0.2, 0.2, "", "Black", "Black"},
		{29, 13.0, 3.45, 0.2, 0.2, "", "Red", "Red"},
		{30, 13.3, 3.45, 0.2, 0.2, "", "Yellow", "Yellow"},
		{31, 13.7, 3.45, 0.2, 0.2, "", "Orange", "Orange"},
		{32, 14.0, 3.45, 0.2, 0.2, "", "Green", "Green"},
		{33, 14.3, 3.45, 0.2, 0.2, "", "White", "White"},
		{34, 14.6, 3.45, 0.2, 0.2, "", "Cyan", "Cyan"},
		
		{35, 13.5, 3, 1.5, 0.5, "结点形状", "Black", "Black"},
		{36, 12.95, 2.55, 1.0, 0.5, "矩形", "Black", "Black"},
		{37, 14.05, 2.55, 1.0, 0.5, "圆角矩形", "Black", "Black"},
		
		{38, 13.5, 2.05, 1.5, 0.5, "边框宽度", "Black", "Black"},
		{39, 12.85, 1.65, 0.5, 0.4, "1", "Black", "Black"},
		{40, 13.5, 1.65, 0.5, 0.4, "2", "Black", "Black"},
		{41, 14.15, 1.65, 0.5, 0.4, "3", "Black", "Black"}, 
		
		{42,  9.25, 8.85, 1.5, 0.3, "模式一", "Black", "Black" },
		{43,  10.75, 8.85, 1.5, 0.3, "模式二", "Black", "Black" },
		
		{44, 13.5, 8.75, 2.5, 0.3, "", "Black", "Black"},
		{45, 3.25, 8.85, 2.5, 0.3, "存储到二进制文件 Ctrl+B", "Black", "Black"}
	}
};

#define _b buttons[mode][i]
char fgcM[6][6] = {"Black", "Black", "White", "Green", "Blue", "White"};

void displayButtons()
{	
	//sprintf(MindmapRoot->contents, "%d", overedButton);
	int i;
	for (i = 0; i < BUTTON_NUM; i++)
	{
		if (i >= 3 && i <= 5 && !currentNode)
			continue;
		
		if (i == 3)
		{
			if (currentNode->isFolded)
				strcpy(_b.contents, "展开子树 Ctrl+F");
			else
				strcpy(_b.contents, "收起子树 Ctrl+F");
		}
		
		if (i == 8 || i == 17 || i == 26 || i == 44 || i == 35 || i == 38)
		{
			drawShape(RECTANGLE, _b.posX, _b.posY, _b.sizeX, _b.sizeY,
					  _b.contents, 0, _b.color, fgcM[mode * 2], TRUE);
			continue;
		}
			
		if (overedButton == i || (i == 2 && isMovingStatus) || (mode + 42 == i))
			drawShape(RECTANGLE, _b.posX, _b.posY, _b.sizeX, _b.sizeY, 
			 		  _b.contents, 0, _b.overedColor, fgcM[mode * 2 + 1], TRUE);
		else
			drawShape(RECTANGLE, _b.posX, _b.posY, _b.sizeX, _b.sizeY,
					  _b.contents, 0, _b.color, fgcM[mode * 2], TRUE);
		if (overedButton == i && i >= 9 && i <= 34)
			drawShape(RECTANGLE, _b.posX, _b.posY, _b.sizeX + 0.04, _b.sizeY + 0.04,
					  _b.contents, 0, fgcM[mode + 4], fgcM[mode * 2], FALSE);
	}
}

char colorList[8][7] = {"Pink", "Black", "Red", "Yellow", 
						"Orange", "Green", "White", "Cyan"};

void changeAllFgc(Mindmap M, int c)
{
	if (!M)	return;
	strcpy(M->foregroundColor, colorList[c]);
	changeAllFgc(M->firstChild, c);
	changeAllFgc(M->nextSibling, c);
}

void changeAllBgc(Mindmap M, int c)
{
	if (!M)	return;
	strcpy(M->backgroundColor, colorList[c]);
	changeAllBgc(M->firstChild, c);
	changeAllBgc(M->nextSibling, c);
}

void changeAllLc(Mindmap M, int c)
{
	if (!M)	return;
	strcpy(M->lineColor, colorList[c]);
	changeAllLc(M->firstChild, c);
	changeAllLc(M->nextSibling, c);
}

void changeAllFill(Mindmap M, bool B)
{
	if (!M)	return;
	M->isFilled = B;
	changeAllFill(M->firstChild, B);
	changeAllFill(M->nextSibling, B);
}

void changeAllTy(Mindmap M, int t)
{
	if (!M)	return;
	M->ty = t;
	changeAllTy(M->firstChild, t);
	changeAllTy(M->nextSibling, t);
}

void changeAllLw(Mindmap M, int lw)
{
	if (!M)	return;
	M->lineWidth = lw;
	changeAllLw(M->firstChild, lw);
	changeAllLw(M->nextSibling, lw);
}

void buttonEvent(int button)
{
	if (button == -1 || button == 8 || button == 26 
	 || button == 17 || button == 44 || button == 35
	 || button == 38)
		return;
	switch (button)
	{
		case 0:{
			saveIntoFile();
			break;
		}
		case 45:{
			saveIntoBinaryFile();
			break;
		}
		case 1:{
			KeyboardEventProcess(VK_CONTROL, KEY_DOWN);
			KeyboardEventProcess('O', KEY_DOWN);
			KeyboardEventProcess(VK_CONTROL, KEY_UP);
			break;
		}
		case 2:{
			isMovingStatus = !isMovingStatus;
			break;
		}
		case 3:{
			if (currentNode)
				currentNode->isFolded = !currentNode->isFolded;
			break;
		}
		case 4:{
			if (currentNode)
			{
				KeyboardEventProcess(VK_CONTROL, KEY_DOWN);
				KeyboardEventProcess('N', KEY_DOWN);
				KeyboardEventProcess(VK_CONTROL, KEY_UP);
			}
			break;
		}
		case 5:{
			if (currentNode)
			{
				KeyboardEventProcess(VK_CONTROL, KEY_DOWN);
				KeyboardEventProcess('D', KEY_DOWN);
				KeyboardEventProcess(VK_CONTROL, KEY_UP);
			}
			break;
		}
		case 6:{                                
			if (currentNode)
				currentNode->isFilled = TRUE;
			else
				changeAllFill(MindmapRoot, TRUE);
			break;
		}
		case 7:{
			if (currentNode)
				currentNode->isFilled = FALSE;
			else
				changeAllFill(MindmapRoot, FALSE);
			break;
		}
	}
	if (button >= 9 && button <= 16)
	{
		if (currentNode)
			strcpy(currentNode->foregroundColor, colorList[button - 9]);
		else
			changeAllFgc(MindmapRoot, button - 9);
	}
	if (button >= 18 && button <= 25)
	{
		if (currentNode)
			strcpy(currentNode->backgroundColor, colorList[button - 18]);
		else
			changeAllBgc(MindmapRoot, button - 18);	
	}
	if (button >= 27 && button <= 34)
	{
		if (currentNode)
			strcpy(currentNode->lineColor, colorList[button - 27]);
		else
			changeAllLc(MindmapRoot, button - 27);	
	}
	if (button >= 36 && button <= 37)
	{
		if (currentNode)
			currentNode->ty = (button == 36);
		else
			changeAllTy(MindmapRoot, button == 36);	
	}
	if (button >= 39 && button <= 41)
	{
		if (currentNode)
			currentNode->lineWidth = button - 38;
		else
			changeAllLw(MindmapRoot, button - 38);	
	}
	if (button == 42 && mode == 1)
	{
		mode = 0;
		changeAllFgc(MindmapRoot, 1);
		changeAllBgc(MindmapRoot, 1);
		changeAllFill(MindmapRoot, FALSE);
		changeAllLc(MindmapRoot, 1);
	}
	if (button == 43 && mode == 0)
	{
		mode = 1;
		changeAllFgc(MindmapRoot, 1);
		changeAllBgc(MindmapRoot, 6);
		changeAllFill(MindmapRoot, TRUE);
		changeAllLc(MindmapRoot, 6);
	}
}


