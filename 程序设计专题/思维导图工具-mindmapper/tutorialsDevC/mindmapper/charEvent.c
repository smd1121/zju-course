#include "myHeader.h"

void CharEventProcess(char c) {
	if (!currentNode || isCtrl)
		return;
	
	int len = strlen(currentNode->contents);
	switch(c) {
		case '\x08':
			dbgI(c); dbgC(' '); dbgS(currentNode->contents); dbgC('\n');
			if(len > 0) 
			{
				if (currentNode->contents[len-1] < 0) currentNode->contents[--len] = 0; 
				//����ռ2���ֽ���ÿ���ֽ����λ��Ϊ 1 by xdq @20210517
				currentNode->contents[--len] = 0; 
				//ASCII�ַ�����һ���ֽڣ����ֻ���2���ֽ� by xdq @20210517 
			}
			break;
		case '\r': case '\n':
			break;
		default:
			if(len == 254) break;
			currentNode->contents[len++] = c;
			currentNode->contents[len] = 0;
			break;
	}
	display();
}
