#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,k;
int arr[MAX_N];

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
} node;

node* createTree(int x){
	node* root=(node*) malloc(sizeof(node));
	root->val=arr[x];
	root->left=NULL; root->right=NULL;
	if(2*x+1<n){
		root->left=createTree(2*x+1);
	}
	if(2*x+2<n){
		root->right=createTree(2*x+2);
	}
	return root;
}

void negate(node* root,int val){
	if(root==NULL) return;

	if(root->left!=NULL&&root->left->val==val){
		root->left=NULL;
		return;
	}else{
		negate(root->left,val);
	}

	if(root->right!=NULL&&root->right->val==val){
		root->right=NULL;
		return;
	}else{
		negate(root->right,val);
	}
}

int height(node* root){
	if(root==NULL) return 0;

	int left=height(root->left);
	int right=height(root->right);
	return max(left+1,right+1);
}	

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0);
	negate(root,k);
	int h=height(root);
	printf("%d\n",h);
}