#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef struct node{
	struct node* next;
	int data;
} node;

node* push(node* head,int x){
	node* root=(node*) malloc(sizeof(node));
	root->data=x;
	root->next=head;
	return root;
}

void printList(node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	node* head=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		head=push(head,x);
	}

	printList(head);
}