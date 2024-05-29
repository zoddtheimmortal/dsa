#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef struct node{
	int val;
	struct node* next;
} node;

node* push_back(node* tail,int x){
	node* root=(node*) malloc(sizeof(node));
	root->val=x;
	root->next=NULL;

	if(tail!=NULL) tail->next=root;
	return root;
}

int main(){
	int n,p,q; scanf("%d %d %d",&n,&p,&q);
	node* head=NULL;
	node* tail=NULL;
	for(int i=1;i<=n;i++){
		tail=push_back(tail,i);
		if(head==NULL) head=tail;
	}

	tail->next=head;

	node* a=NULL;
	node* b=NULL;

	while(head->val!=p) head=head->next;
	a=head;

	while(head->val!=q) head=head->next;
	b=head;

	while(a->val!=b->val){
		b=b->next;
		a=a->next->next;
	}

	printf("%d\n",a->val);
}