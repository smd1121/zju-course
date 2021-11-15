#ifndef _DISPLAY_H_
#define _DISPLAY_H_

extern double centerX, centerY;

/* void drawShape(...)
 * -----------------------
 * ������������������һ��ͼԪ��
 * ע�⣬�˴� pX, pY ΪͼԪ�������ĵ����ꡣ
 */
void drawShape(enum ShapeType ty, double pX, double pY, double sX, double sY, 
               char *text, int lineW, char *bgc, char *fgc, bool isF);

void displayMindmap(Mindmap M, int level);

#endif
