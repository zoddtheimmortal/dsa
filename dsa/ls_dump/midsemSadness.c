#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int arr[MAX_N];

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
} node;

node* createTree(int x){
	node* root=(node*) malloc(sizeof(node));
	root->val=x;
	root->left=NULL; root->right=NULL;
	if(2*x+1<n){
		root->left=createTree(2*x+1);
	}
	if(2*x+2<n){
		root->right=createTree(2*x+2);
	}
	return root;
}

int recurSum(node* root){
	if(root==NULL) return 0;
	int weight=arr[root->val];
	int left=recurSum(root->left);
	int right=recurSum(root->right);

	if(root->val==0) return weight+left+right;
	return weight+max(left,right);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	node* root=createTree(0);
	int ans=recurSum(root);
	printf("%d\n",ans);
}