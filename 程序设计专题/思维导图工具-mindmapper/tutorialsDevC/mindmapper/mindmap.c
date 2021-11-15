#include "myHeader.h"

Mindmap MindmapRoot = NULL;
double MindmapLevelWidth[64] = {0.0};

double calculateHeight(Mindmap M, int level);

/* 函数 Mindmap newMindmapNode(...)
 * -----------------------
 * 根据所给参数，新建一个思维导图结点。
 */
Mindmap newMindmapNode(bool isF, bool isTR, int lw, char *bgc, char *fgc, char *cntt, Mindmap fa) 
{
	Mindmap M = (Mindmap)malloc(sizeof(struct MindmapNode));
	M->isFilled = isF, M->isToRight = isTR;
	M->isFolded = FALSE;
	M->lineWidth = lw, M->childNum = 0;
	M->ty = ROUNDED_RECT;
	strcpy(M->backgroundColor, bgc);
	strcpy(M->foregroundColor, fgc);
	strcpy(M->lineColor, "Black");
	//strcpy(M->foregroundColor, "Black");
	strcpy(M->contents, cntt);
	
	M->father = fa, M->firstChild = M->nextSibling = M->lastSibling = NULL;
	if (fa)
	{
		Mindmap temp;
		if (temp = getLastChild(fa))
		{
			temp->nextSibling = M;
			M->lastSibling = temp;
		}
		else
		{
			fa->firstChild = M;
		}
		fa->childNum++;
		M->level = fa->level + 1;
	}
	else M->level = 0;

	return M;
}

/* 函数 Mindmap getLastChild(Mindmap M)
 * -----------------------
 * 返回 M 的最后一个儿子。如果 M 为空或者 M 没有儿子，返回 NULL。
 */
Mindmap getLastChild(Mindmap M)
{
	if (!M || !M->firstChild) return NULL;
	Mindmap temp = M->firstChild;
	while (temp->nextSibling)
		temp = temp->nextSibling;
	return temp;
}

const double TREE_LEVEL_DISTANCE = 0.5;
/* 函数 calculateDisplayMode1(Mindmap M, double pX, double pY)
 * -----------------------
 * 计算以 M 为根的子树的布局位置。
 * -----------------------
 * Usage: calculateDisplayMode1(MindmapRoot, 0, 0, 0);
 */
void calculateDisplayMode1(Mindmap M, int level, double pX, double pY)
{
	if (!M)	return;
	if (level == 0)
		calculateHeight(M, 0);
	
	M->posX = pX, M->posY = pY;
	double nextX = pX + MindmapLevelWidth[level] + TREE_LEVEL_DISTANCE;
	double currentY = pY + M->childHeightSum / 2;

	if (M->isFolded)	return;
	Mindmap temp = M->firstChild;
	while (temp)
	{
		calculateDisplayMode1(temp, level + 1, nextX, currentY - temp->sizeY / 2);
		currentY -= temp->sizeY;
		temp = temp->nextSibling;
	}
}

const double NODE_HEIGHT_BORDER = 0.1;
const double NODE_WIDTH_BORDER = 0.2;
const double TREE_NODE_DISTANCE = 0.1;
/* 函数 double calculateHeight(Mindmap M, int level)
 * -----------------------
 * 搜索以 M 为根的子树。
 * 对于每个结点，维护其自身高度以及子树高度，
 * 遍历其后继兄弟结点，返回其后继兄弟高度之和。
 * 同时对于每个结点，维护其自身宽度；
 * 如果该结点比当前记录的所在层最大宽度宽，更新之。
 * -----------------------
 * Usage: calculateHeight(MindmapRoot, 0);
 */
double calculateHeight(Mindmap M, int level)
{
	if (!M || (M->father && M->father->isFolded))	return 0.0;

	if (!level)
	{
		int i = 0;
		for (; i < 64; i++)
			MindmapLevelWidth[i] = 0;
	}
	M->selfWidth = TextStringWidth(M->contents) + NODE_WIDTH_BORDER;
	if (M->selfWidth > MindmapLevelWidth[level])
		MindmapLevelWidth[level] = M->selfWidth;

	M->selfHeight = GetFontHeight() + NODE_HEIGHT_BORDER;
	M->childHeightSum = calculateHeight(M->firstChild, level + 1);
	double siblingHeightSum = calculateHeight(M->nextSibling, level);
	M->sizeY = (M->selfHeight > M->childHeightSum ? M->selfHeight : M->childHeightSum) + TREE_NODE_DISTANCE;
	
	return siblingHeightSum + M->sizeY;
}
