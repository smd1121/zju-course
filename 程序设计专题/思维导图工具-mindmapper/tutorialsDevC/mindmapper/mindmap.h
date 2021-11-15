#ifndef _MINDMAP_H_
#define _MINDMAP_H_

/* ���ͣ�˼ά��ͼ��� 
 * -----------------------
 * isFolded ���ڼ�¼�ý��Ķ����Ƿ��۵�
 * 
 * isToRight ���ڼ�¼������չ����ģʽ�½���Ƿ��ڸ��ڵ��Ҳ� 
 * 
 * father ָ����ĸ��ף�firstChild ָ���һ�����ӣ�nextSibling ָ����һ���ֵ�
 * ����ʹ�������ַ�������������ʵ���Ͼ���ÿ�������ӽ���γ�һ���� nextSibling ���ɵ�����
 * lastSibling ָ��ǰһ���ֵܣ�ʹ���乹��һ��˫������
 * 
 * posX �ǽ�������ľ��Ժ�����
 * posY �ǽ�㼸�����ĵľ���������
 *
 * �����ֶε���������Ȼ��
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

/* ���� Mindmap newMindmapNode(...)
 * -----------------------
 * ���������������½�һ��˼ά��ͼ��㡣
 */
Mindmap newMindmapNode(bool isF, bool isTR, int lw, char *bgc, char *fgc, char *cntt, Mindmap fa);

/* ���� double calculateHeight(Mindmap M, int level)
 * -----------------------
 * ������ M Ϊ����������
 * ����ÿ����㣬ά��������߶��Լ������߶ȣ�
 * ���������ֵܽ�㣬���������ֵܸ߶�֮�͡�
 * ͬʱ����ÿ����㣬ά���������ȣ�
 * ����ý��ȵ�ǰ��¼�����ڲ�����ȿ�����֮��
 * -----------------------
 * Usage: calculateHeight(MindmapRoot, 0);
 */
void calculateDisplayMode1(Mindmap M, int level, double pX, double pY);

/* ���� Mindmap getLastChild(Mindmap M)
 * -----------------------
 * ���� M �����һ�����ӡ���� M Ϊ�ջ��� M û�ж��ӣ����� NULL��
 */
Mindmap getLastChild(Mindmap M);

#endif
