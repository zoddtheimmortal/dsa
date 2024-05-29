#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef struct node{
	char val;
	struct node* next;
	struct node* prev;
} node;

node* push_back(node* tail,char x){
	node* root=(node*)malloc(sizeof(node));
	root->val=x;
	root->next=NULL;
	root->prev=tail;

	if(tail!=NULL) tail->next=root;
	return root;
}

int check(node* head,node* tail){
	while(head!=tail){
		if(head->val!=tail->val) return 0;
		head=head->next;
		tail=tail->prev;
	}
	return 1;
}

int main(){
	int n; scanf("%d",&n);
	char arr[n]; scanf("%s",arr);
	node* head=NULL;
	node* tail=NULL;

	for(int i=0;i<n;i++){
		tail=push_back(tail,arr[i]);
		if(head==NULL) head=tail;
	}
	int ans=check(head,tail);
	printf("%s\n",(ans==0?"NO":"YES"));
}