#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int postorder[MAX_N];

typedef struct node{
	struct node* l;
	struct node* r;
	int val;
} node;

node* createTree(int si,int ei){
	if(si>ei||si<0||si>=n||ei<0||ei>=n) return NULL;
	node* root=(node*) malloc(sizeof(node));
	root->l=NULL,root->r=NULL;
	root->val=postorder[ei];

	int sep=si;
	while(sep<ei&&postorder[sep]<=postorder[ei]) sep++;

	root->l=createTree(si,sep-1);
	root->r=createTree(sep,ei-1);
	return root;
}

int height(node* root){
	if(root==NULL) return 0;
	int left=height(root->l);
	int right=height(root->r);
	if(left>right) return left+1;
	return right+1;
}

void printLevel(node* root,int level){
	if(level<1) return;
	if(root==NULL){
		printf("-1 ");
		return;
	}
	if(level==1) printf("%d ",root->val);
	else{
		printLevel(root->l,level-1);
		printLevel(root->r,level-1);
	}
}

void printTree(node* root){
	int h=height(root);
	for(int i=1;i<=h;i++) printLevel(root,i);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&postorder[i]);

	node* root=createTree(0,n-1);
	printTree(root);
	printf("\n");
}