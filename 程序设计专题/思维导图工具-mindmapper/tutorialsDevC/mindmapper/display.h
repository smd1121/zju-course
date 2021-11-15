#ifndef _DISPLAY_H_
#define _DISPLAY_H_

extern double centerX, centerY;

/* void drawShape(...)
 * -----------------------
 * 根据所给参数，绘制一个图元。
 * 注意，此处 pX, pY 为图元几何中心的坐标。
 */
void drawShape(enum ShapeType ty, double pX, double pY, double sX, double sY, 
               char *text, int lineW, char *bgc, char *fgc, bool isF);

void displayMindmap(Mindmap M, int level);

#endif
