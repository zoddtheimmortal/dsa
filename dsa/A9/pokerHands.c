#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,m;
int tree[MAX_N],subtree[MAX_N];

typedef struct node{
	struct node* l;
	struct node* r;
	int val;
} node;

node* createTree(int arr[],int n,int x){
	node* root=(node*) malloc(sizeof(node));
	root->l=NULL,root->r=NULL;
	root->val=arr[x];

	if(2*x+1<n){
		root->l=createTree(arr,n,2*x+1);
	}
	if(2*x+2<n){
		root->r=createTree(arr,n,2*x+2);
	}
	return root;
}

node* findNode(node* root,node* subroot){
	if(root==NULL) return NULL;
	if(root->val==subroot->val) return root;

	node* left=findNode(root->l,subroot);
	node* right=findNode(root->r,subroot);

	if(left!=NULL) return left;
	return right;
}

int findSubtree(node* root,node* subroot){
	if(root==NULL && subroot==NULL) return 1;
	else if((root==NULL && subroot!=NULL)||(root!=NULL&subroot==NULL)) return 0;

	int main=(root->val==subroot->val);
	int left=findSubtree(root->l,subroot->l);
	int right=findSubtree(root->r,subroot->r);

	return (main&&left&&right);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&tree[i]);
	for(int i=0;i<m;i++) scanf("%d",&subtree[i]);

	node* root=createTree(tree,n,0);
	node* subroot=createTree(subtree,m,0);

	root=findNode(root,subroot);
	int ans=findSubtree(root,subroot);
	printf("%s\n",(ans==1?"WIN":"LOSS"));
}