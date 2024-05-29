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
	if(si>ei||si<0||si>=n||ei<0||ei>=n) return NULL;
	node* root=(node*) malloc(sizeof(node));
	root->val=arr[ei];
	root->left=NULL; root->right=NULL;

	int sep=si;
	while(sep<ei&&arr[sep]<arr[ei]) sep++;

	root->left=createTree(si,sep-1);
	root->right=createTree(sep,ei-1);
	return root;
}

int height(node* root){
	if(root==NULL) return 0;

	int left=height(root->left);
	int right=height(root->right);

	return max(left+1,right+1);
}

void printLevel(node* root,int level){
	if(level<1) return;
	if(root==NULL){
		printf("-1 ");
		return;
	}
	if(level==1) printf("%d ",root->val);
	else{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}

void printTree(node* root){
	int h=height(root);
	for(int i=1;i<=h;i++) printLevel(root,i);
	printf("\n");
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0,n-1);
	printTree(root);
}