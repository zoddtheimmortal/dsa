#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int inorder[MAX_N],preorder[MAX_N];

typedef struct node{
	struct node* l;
	struct node* r;
	int val;
} node;

int height(node* root){
	if(root==NULL) return 0;
	else{
		int left=height(root->l);
		int right=height(root->r);

		if(left>right) return left+1;
		return right+1;
	}
}

node* createTree(int p_si,int p_ei,int i_si,int i_ei){

	if(p_si>p_ei||p_si<0||p_si>=n||p_ei<0||p_ei>=n) return NULL;
	if(i_si>i_ei||i_si<0||i_si>=n||i_ei<0||i_ei>=n) return NULL;

	node* root=(node*) malloc(sizeof(node));
	root->l=NULL,root->r=NULL;
	root->val=preorder[p_si];

	int ipivot=0,ppivot=0;
	for(int i=i_si;i<=i_ei;i++){
		if(inorder[i]==preorder[p_si]){
			ipivot=i;
			break;
		}
	}
	int flag=0;
	for(int i=p_si+1;i<=p_ei&&flag==0;i++){
		for(int j=ipivot+1;j<=i_ei;j++){
			if(inorder[j]==preorder[i]){
				ppivot=i;
				flag=1;
				break;
			}
		}
	}
	root->l=createTree(p_si+1,ppivot-1,i_si,ipivot-1);
	root->r=createTree(ppivot,p_ei,ipivot+1,i_ei);
	return root;
}

void printLevel(node* root,int level){
	if(level<1) return;
	if(root==NULL){
		printf("%d ",-1);
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
	for(int i=0;i<n;i++) scanf("%d",&inorder[i]);
	for(int i=0;i<n;i++) scanf("%d",&preorder[i]);

	node* root=createTree(0,n-1,0,n-1);
	printTree(root);
	printf("\n");
}