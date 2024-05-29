#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int inorder[MAX_N],preorder[MAX_N];

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
} node;

node* createTree(int p_si,int p_ei,int i_si,int i_ei){
	if(p_si>p_ei||p_si<0||p_si>=n||p_ei<0||p_ei>=n) return NULL;
	if(i_si>i_ei||i_si<0||i_si>=n||i_ei<0||i_ei>=n) return NULL;
	node* root=(node*) malloc(sizeof(node));
	root->val=preorder[p_si];
	root->left=NULL; root->right=NULL;

	int x=i_si,y=INT_MAX;
	while(x<=i_ei&&inorder[x]!=preorder[p_si]) x++;

	for(int i=x+1;i<=i_ei;i++){
		for(int p=p_si+1;p<=p_ei;p++){
			if(inorder[i]==preorder[p]) y=min(y,p);
		}
	}

	root->left=createTree(p_si+1,y-1,i_si,x-1);
	root->right=createTree(y,p_ei,x+1,i_ei);

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

	if(level==1){
		printf("%d ",root->val);
	}else{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}

void printTree(node* root){
	int h=height(root);
	for(int i=1;i<=h;i++) printLevel(root,i);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&inorder[i]);
	for(int i=0;i<n;i++) scanf("%d",&preorder[i]);

	node* root=createTree(0,n-1,0,n-1);
	printTree(root);
	printf("\n");
}