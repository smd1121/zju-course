/* Suppose that all the keys in the binary tree are distinct positive integers. */

#include<stdio.h>

const int MAXN = 105;
int n, inorder[MAXN], postorder[MAXN];					// Input
int left[MAXN], right[MAXN], value[MAXN], count = -1;	// Tree Nodes

int find(int value){
	for(int i = 0; i < n; i++)	if(value == inorder[i])	return i;
	return -1;
}

/* return value of buildTree is the index of the root */
int buildTree(int inLeft, int inRight, int postLeft, int postRight){
	if(inLeft > inRight)	return -1;
	if(inLeft == inRight){
		value[++count] = postorder[postRight];
		left[count] = right[count] = -1;
		return count;
	}
	value[++count] = postorder[postRight];	// In this subtree, postorder[r] is the root.
	
	int root = find(value[count]), thisIndex = count;
	left [thisIndex] = buildTree(inLeft, root-1, postLeft, postRight-(inRight-root)-1);
    // (inRight - root) is the size of the right subtree
	right[thisIndex] = buildTree(root+1, inRight, postLeft+(root-inLeft), postRight-1);
    // (root - inLeft)  is the size of the left  subtree
    
	return thisIndex;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)	scanf("%d", &inorder[i]);
	for(int i = 0; i < n; i++)	scanf("%d", &postorder[i]);
	buildTree(0, n-1, 0, n-1);
	
	for(int i = 0; i < n; i++)	printf("%3d %3d %3d %3d\n", i, value[i], left[i], right[i]);
}
