#include "myHeader.h"

double centerX = -4, centerY = -4.5;

/* void drawShape(...)
 * -----------------------
 * 根据所给参数，绘制一个图元。
 * 注意，此处 pX, pY 为图元几何中心的坐标。
 */
void drawShape(enum ShapeType ty, double pX, double pY, double sX, double sY, 
               char *text, int lineW, char *bgc, char *fgc, bool isF)
{
    if (isF)	StartFilledRegion(1);
    if (bgc)    SetPenColor(bgc);
    else        SetPenColor("Black");

    switch (ty)
    {
        case ROUNDED_RECT:
            SetPenSize(lineW);
            MovePen(pX + sX/2.0, pY - sY/6.0);
			DrawLine(0, sY/3.0);
			DrawArc(sY/3.0, 0.0, 90.0);
			DrawLine(2*sY/3.0 - sX, 0);
			DrawArc(sY/3.0, 90.0, 90.0);
			DrawLine(0, -sY/3.0);
			DrawArc(sY/3.0, 180.0, 90.0);
			DrawLine(sX - 2*sY/3.0, 0);
			DrawArc(sY/3.0, 270.0, 90.0);
            break;
        case RECTANGLE:
        	SetPenSize(lineW);
        	MovePen(pX - sX/2.0, pY - sY/2.0);
			DrawLine(sX, 0); 
			DrawLine(0, sY); 
			DrawLine(-sX, 0); 
			DrawLine(0, -sY);
        	break;
        case CIRCLE:
        	MovePen(pX + sX/2.0, pY);
			DrawArc(sX/2.0, 0, 360);
			break;
    }
    if (isF)	EndFilledRegion();
    
    if (text)
    {
        if (fgc)    SetPenColor(fgc);
        else        SetPenColor("Black");

        MovePen(pX - TextStringWidth(text) / 2, pY - GetFontAscent() / 2);
		DrawTextString(text);
    }
}

void displayMindmap(Mindmap M, int level)
{
    if (!M) return;
    if (!level)
		calculateDisplayMode1(MindmapRoot, 0, 0, 0);

	drawShape(M->ty, M->posX + MindmapLevelWidth[level] / 2 - centerX,
              M->posY - centerY, MindmapLevelWidth[level], M->selfHeight, 
              M->contents, M->lineWidth, M->backgroundColor, 
              M->foregroundColor, M->isFilled);
	
	if (level)
	{
		if (M->lineColor)	SetPenColor(M->lineColor);
		else				SetPenColor("Black");
		MovePen(M->father->posX + MindmapLevelWidth[level - 1] - centerX,
				M->father->posY - centerY);
		DrawLine(M->posX - (M->father->posX + MindmapLevelWidth[level - 1]), 
				 M->posY - M->father->posY);
	}
	
	if (M->isFolded)
	{
		MovePen(M->posX + MindmapLevelWidth[level] - centerX, M->posY - centerY);
		DrawLine(0.2, 0);
		DrawArc(0.1, 180, 360);
		return; 
	}
	 
	Mindmap temp = M->firstChild;
	while (temp)
	{
		displayMindmap(temp, level + 1);
		temp = temp->nextSibling;
	}
}

