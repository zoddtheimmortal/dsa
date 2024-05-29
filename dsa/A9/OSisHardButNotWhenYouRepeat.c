#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,k,p=0;
int arr[MAX_N]={0},inorder[MAX_N]={0};

typedef struct node{
	struct node* l;
	struct node* r;
	int val;
} node;

node* createTree(int x){
	node* root=(node*) malloc(sizeof(node));
	root->l=NULL; root->r=NULL; root->val=arr[x];
	if(root->val==-1) return NULL;

	if(2*x+1<n){
		root->l=createTree(2*x+1);
	}
	if(2*x+2<n){
		root->r=createTree(2*x+2);
	}
	return root;
}

void getInorder(node* root){
	if(root==NULL) return;

	getInorder(root->l);
	inorder[p++]=root->val;
	getInorder(root->r);
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0);
	getInorder(root);

	// for(int i=0;i<p;i++) printf("%d ",inorder[i]);
	printf("%d\n",inorder[p-k]);
}