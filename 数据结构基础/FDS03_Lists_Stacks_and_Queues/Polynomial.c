#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;
typedef struct Node Node;

Polynomial Read(){
	/* Input should be sorted in decreasing order of exponents. */
	typedef PtrToNode ptr;
	ptr head = (ptr)malloc(sizeof(Node)), tail = NULL;
	head->Next = NULL, tail = head;
	
	int length;	scanf("%d", &length);
	while(length--){
		tail->Next = (PtrToNode)malloc(sizeof(Node));
		tail = tail->Next, tail->Next = NULL;
		scanf("%d%d", &tail->Coefficient, &tail->Exponent);
	}
	
	return head;
} 

void Print(Polynomial L){
	if(L == NULL){
		printf("\n");
		return;
	}
	
	Polynomial temp = L->Next;
	while(temp != NULL){
		printf("%d %d ", temp->Coefficient, temp->Exponent);
		temp = temp->Next;
	}
	printf("\n");
	return;
}

Polynomial Add(Polynomial a, Polynomial b);

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    //Print(a);
    Print(s);
    printf("%p %p", s, s->Next);
    return 0;
}
