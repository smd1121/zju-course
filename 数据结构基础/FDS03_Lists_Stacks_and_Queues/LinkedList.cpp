// HW 6-2 Reverse Linked List "details omitted"

#include<stdio.h>
#include<stdlib.h> 

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(){
	PtrToNode head = (PtrToNode)malloc(sizeof(Node)), tail = NULL;
	head->Element = 0, head->Next = NULL, tail = head;
	
	int length;	scanf("%d", &length);
	while(length--){
		tail->Next = (PtrToNode)malloc(sizeof(Node));
		tail = tail->Next, tail->Next = NULL;
		scanf("%d", &tail->Element);
	}
	
	return head;
}

void Print(List L){
	if(L == NULL){
		printf("\n");
		return;
	}
	
	List temp = L->Next;
	while(temp != NULL){
		printf("%d ", temp->Element);
		temp = temp->Next;
	}
	printf("\n");
	return;
}
