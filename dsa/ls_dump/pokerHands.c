#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,m;
int tree[MAX_N],subtree[MAX_N];

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
} node;

node* createTree(int arr[],int n,int x){
	node* root=(node*) malloc(sizeof(node));
	root->val=arr[x];
	root->left=NULL; root->right=NULL;
	if(2*x+1<n){
		root->left=createTree(arr,n,2*x+1);
	}
	if(2*x+2<n){
		root->right=createTree(arr,n,2*x+2);
	}
	return root;
}

node* findTree(node* root,int val){
	if(root==NULL) return NULL;
	if(root->val==val) return root;

	node* left=findTree(root->left,val);
	node* right=findTree(root->right,val);

	if(left!=NULL) return left;
	return right;
}

int compare(node* a,node* b){
	if(a==NULL&&b==NULL) return 1;
	if((a==NULL&&b!=NULL)||(a!=NULL&&b==NULL)) return 0;

	int mid=(a->val==b->val);
	int left=compare(a->left,b->left);
	int right=compare(a->right,b->right);

	return mid&&left&&right;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&tree[i]);
	for(int i=0;i<m;i++) scanf("%d",&subtree[i]);

	node* root=createTree(tree,n,0);
	node* subroot=createTree(subtree,m,0);

	root=findTree(root,subroot->val);
	int ans=compare(root,subroot);

	printf("%s\n",(ans==1?"WIN":"LOSS"));
}