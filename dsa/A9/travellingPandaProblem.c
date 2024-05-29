#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,ans=0;
int arr[MAX_N]={0};

typedef struct node{
	struct node* l;
	struct node* r;
	int i;
} node;

node* createTree(int x){
	node* root=(node*) malloc(sizeof(node));
	root->l=NULL,root->r=NULL,root->i=x;
	if(2*x+1<n){
		root->l=createTree(2*x+1);
	}
	if(2*x+2<n){
		root->r=createTree(2*x+2);
	}
	return root;
}

void dfs(node* root,int depth){
	if(root==NULL) return;
	if(arr[root->i]!=-1) ans+=depth;
	dfs(root->l,depth+1);
	dfs(root->r,depth+1);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0);
	dfs(root,0);
	printf("%d\n",ans);
}