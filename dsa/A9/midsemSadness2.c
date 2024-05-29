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
	int i;
} node;

int arr[MAX_N],n,p,q;

node* createTree(int x){
	node* root=(node*) malloc(sizeof(node));
	root->l=NULL,root->r=NULL;
	root->i=x;
	if(2*x+1<n){
		root->l=createTree(2*x+1);
	}
	if(2*x+2<n){
		root->r=createTree(2*x+2);
	}
	return root;
}

int recurSum(node* u){
	int weight=arr[u->i];
	int left=0,right=0;
	if(u->l!=NULL){
		left=recurSum(u->l);
	}
	if(u->r!=NULL){
		right=recurSum(u->r);
	}
	if(u->i==0) return weight+right+left;
	return weight+max(right,left);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0);
	int ans=recurSum(root);
	printf("%d\n",ans);
}