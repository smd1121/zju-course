#ifndef _MINDMAP_H_
#define _MINDMAP_H_

/* 类型：思维导图结点 
 * -----------------------
 * isFolded 用于记录该结点的儿子是否被折叠
 * 
 * isToRight 用于记录在两侧展开的模式下结点是否在根节点右侧 
 * 
 * father 指向结点的父亲，firstChild 指向第一个儿子，nextSibling 指向下一个兄弟
 * 这里使用了这种方法保存多叉树，实际上就是每个结点的子结点形成一个由 nextSibling 连成的链表
 * lastSibling 指向前一个兄弟，使得其构成一个双向链表
 * 
 * posX 是结点最左侧的绝对横坐标
 * posY 是结点几何中心的绝对纵坐标
 *
 * 其他字段的意义是显然的
 */
enum ShapeType {ROUNDED_RECT, RECTANGLE, CIRCLE};
struct MindmapNode
{
	enum ShapeType ty;
	bool 	isFolded, isToRight, isFilled;
	int 	lineWidth, childNum, level;
	double 	selfHeight, childHeightSum, selfWidth, sizeY;
	double	posX, posY;
	char 	backgroundColor[32], foregroundColor[32], lineColor[32];
	char 	contents[256];
	struct MindmapNode	
			*father, *firstChild, *nextSibling, *lastSibling;
};

typedef struct MindmapNode *Mindmap;

extern Mindmap MindmapRoot;
extern double MindmapLevelWidth[64];

/* 函数 Mindmap newMindmapNode(...)
 * -----------------------
 * 根据所给参数，新建一个思维导图结点。
 */
Mindmap newMindmapNode(bool isF, bool isTR, int lw, char *bgc, char *fgc, char *cntt, Mindmap fa);

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
void calculateDisplayMode1(Mindmap M, int level, double pX, double pY);

/* 函数 Mindmap getLastChild(Mindmap M)
 * -----------------------
 * 返回 M 的最后一个儿子。如果 M 为空或者 M 没有儿子，返回 NULL。
 */
Mindmap getLastChild(Mindmap M);

#endif
