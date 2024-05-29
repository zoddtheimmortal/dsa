#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef struct node{
	struct node* l;
	struct node* r;
	int val;
} node;

int arr[MAX_N],path1[MAX_N],path2[MAX_N];
int n,p,q,k1,k2;

node* createTree(int x){
	node* root=(node*) malloc(sizeof(node));
	root->l=NULL,root->r=NULL,root->val=arr[x];
	if(2*x+1<n){
		root->l=createTree(2*x+1);
	}
	if(2*x+2<n){
		root->r=createTree(2*x+2);
	}
	return root;
}

int findPath(node* root,int* path,int k,int p){
	if(root==NULL) return 0;
	path[k++]=root->val;
	if(root->val==p) return 1;

	if(root->l!=NULL&&findPath(root->l,path,k,p)) return 1;
	if(root->r!=NULL&&findPath(root->r,path,k,p)) return 1;

	--k;
	return 0;
}

int cmnAnc(node* root,int p,int q){
	if(findPath(root,path1,k1,p)==0||findPath(root,path2,k2,q)==0) return -1;

	int i;
	for(i=0;i<k1&&i<k2;i++){
		if(path1[i]!=path2[i]) break;
	}
	return path1[i-1];
}

int main(){
	scanf("%d %d %d",&n,&p,&q);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0);
	int anc=cmnAnc(root,p,q);
	printf("%d\n",anc);
}