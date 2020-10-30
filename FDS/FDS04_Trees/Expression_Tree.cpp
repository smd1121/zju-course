#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;
typedef struct TreeNode *Tree;

struct TreeNode{
	ElementType	value;
	Tree		leftChild, rightChild;
};

void LRD(Tree T){
	if(T == NULL)	return;
	LRD(T->leftChild);
	LRD(T->rightChild);
	putchar(T->value);
	putchar(' ');
}

void LDR(Tree T){
	if(T == NULL)	return;
	
	if(T->value == '+' || T->value == '-')
		putchar('(');
		
	LDR(T->leftChild);
	putchar(T->value);
	LDR(T->rightChild);
	
	if(T->value == '+' || T->value == '-')
		putchar(')');
}

Tree buildTree(){
	Tree stack[1005], temp;
	int stackHead = -1;
	for(char input = getchar(); input != '\n'; input = getchar()){
		switch(input){
			case ' ':
				break;
			case '+': case '-': case '*': case '/':
				//if(stackHead < 2)	return NULL;
				temp = (Tree)malloc(sizeof(struct TreeNode));
				temp->value = input;
				temp->rightChild = stack[stackHead--];
				temp->leftChild = stack[stackHead--];
				stack[++stackHead] = temp;
				break;
			default:
				temp = (Tree)malloc(sizeof(struct TreeNode));
				temp->value = input;
				temp->rightChild = temp->leftChild = NULL;
				stack[++stackHead] = temp;
				break;
		}
	}
	if(stackHead == 0)	return stack[0];
	return NULL;
}

int main(){
	Tree tree = buildTree();
	if(tree == NULL)
		puts("ERROR");
	else{
		LRD(tree); puts("");
		LDR(tree); puts("");	
	}
	return 0;
}
