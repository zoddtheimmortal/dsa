#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int arr[MAX_N];

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
} node;

node* createTree(int si,int ei){
	if(si>ei) return NULL;
	// int mid=si+(si<ei);
	int mid=si+(ei-si)/2;
	node* root=(node*) malloc(sizeof(node));
	root->val=arr[mid];

	root->left=createTree(si,mid-1);
	root->right=createTree(mid+1,ei);
	return root;
}

void printTree(node* root){
	if(root==NULL) return;

	printf("%d ",root->val);
	printTree(root->left);
	printTree(root->right);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0,n-1);
	printTree(root);
	printf("\n");
}