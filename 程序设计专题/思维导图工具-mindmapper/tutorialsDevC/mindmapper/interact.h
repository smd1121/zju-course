#ifndef _INTERACT_H_
#define _INTERACT_H_

extern Mindmap currentNode;
void MouseEventProcess(int x, int y, int button, int event);
Mindmap inNode(Mindmap M, double mx, double my);

void CharEventProcess(char c);

extern bool isCtrl;
extern bool isMovingStatus;
void KeyboardEventProcess(int key, int event);

#endif
