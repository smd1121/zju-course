#include "myHeader.h"

struct MindmapRecord
{
	bool 	isFo, isTR, isFi;
	int 	lw, id, fa;
	char 	bgC[32], fgC[32];
	char 	ct[256];
} records[1024];
int num = -1;

#define rn records[num]
void genRecords(Mindmap M, int faID)
{
	if (!M)	return;
	
	num++;
	
	rn.isFo = M->isFolded, rn.isTR = M->isToRight, rn.isFi = M->isFilled;
	rn.lw = M->lineWidth, rn.id = num, rn.fa = faID;
	strcpy(rn.bgC, M->backgroundColor);
	strcpy(rn.fgC, M->foregroundColor);
	strcpy(rn.ct, M->contents);
	
	genRecords(M->firstChild, num);
	genRecords(M->nextSibling, faID);
}

#define ri records[i]
// ����ֵ: �ɹ� 1, ʧ�� 0
// ͨ�� path ���ػ�ȡ��·��
int FileDialog(char *path)
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); // �ṹ��С
    ofn.lpstrFile = path; // ·��
    ofn.nMaxFile = MAX_PATH; // ·����С
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0"; // �ļ�����
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName(&ofn);
}

void saveIntoFile()
{
	num = -1;
	genRecords(MindmapRoot, -1);
	FILE *file = NULL;
	int i = 0;
	char fileName[256];
	
	do
	{
		dbgS(fileName); dbgC('\n');
		i++;
		sprintf(fileName, "../saved/mindmap%d.mmp", i);
		file = fopen(fileName, "r");
	}
	while (file);
	
	file = fopen(fileName, "w");
	
	for (i = 0; i <= num; i++)
		fprintf(file, "%d %d %d %d %d %d %s %s %s\n", ri.isFo, ri.isTR, ri.isFi, 
				ri.lw, ri.id, ri.fa, ri.bgC, ri.fgC, ri.ct);
	
	sprintf(buttons[mode][44].contents, "�ѱ����� %s", fileName);
	
	fclose(file);
}

Mindmap ptrs[1024];
void readFromFile()
{
	char filePath[256] = {0};
	if (!FileDialog(filePath))	return;
	
	FILE *file;
	if (filePath[strlen(filePath) - 1] == 'b')
	{
		int len = strlen(filePath);
		while (filePath[len] != '\\')	len--;
		sprintf(buttons[mode][44].contents, "��ȡ�������ļ� %s", filePath + len + 1);
		
		file = fopen(filePath, "rb");
		if (!file)	return;

		int i = -1;
		while(!feof(file))
		{
			i++;
			if (fread(&records[i], sizeof(struct MindmapRecord), 1, file) != 1)
				break;
			
			ptrs[i] = newMindmapNode(ri.isFi, ri.isTR, ri.lw, ri.bgC, ri.fgC, ri.ct, ri.fa == -1 ? NULL : ptrs[ri.fa]);
			ptrs[i]->isFolded = ri.isFo;
		}
		MindmapRoot = ptrs[0];
		currentNode = NULL;
		num = -1;
		
		fclose(file);
	}
	else
	{
		int len = strlen(filePath);
		while (filePath[len] != '\\')	len--;
		sprintf(buttons[mode][44].contents, "��ȡ�ı��ļ� %s", filePath + len + 1);
		
		file = fopen(filePath, "r");
		if (!file)	return;
		int i = -1;
		while(!feof(file))
		{
			i++;
			fscanf(file, "%d %d %d %d %d %d %s %s %s\n", &ri.isFo, &ri.isTR, &ri.isFi, 
				   &ri.lw, &ri.id, &ri.fa, ri.bgC, ri.fgC, ri.ct);
				   
			ptrs[i] = newMindmapNode(ri.isFi, ri.isTR, ri.lw, ri.bgC, ri.fgC, ri.ct, ri.fa == -1 ? NULL : ptrs[ri.fa]);
			ptrs[i]->isFolded = ri.isFo;
		}
		MindmapRoot = ptrs[0];
		currentNode = NULL;
		num = -1;
		
		fclose(file);
	}
}

void saveIntoBinaryFile()
{
	num = -1;
	genRecords(MindmapRoot, -1);
	FILE *file = NULL;
	int i = 0;
	char fileName[256];
	
	do
	{
		dbgS(fileName); dbgC('\n');
		i++;
		sprintf(fileName, "../saved/mindmap%d.mmpb", i);
		file = fopen(fileName, "rb");
	}
	while (file);
	
	file = fopen(fileName, "wb");
	
	for (i = 0; i <= num; i++)
		fwrite(&records[i], sizeof(struct MindmapRecord), 1, file);
	
	sprintf(buttons[mode][44].contents, "�ѱ����� %s", fileName);
	
	fclose(file);
}
