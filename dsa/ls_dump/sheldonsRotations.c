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

void rotate(node** head,int rot){
	for(int i=0;i<rot;i++){
		node* temp=*head;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=*head;
		node* nh=(*head)->next;
		(*head)->next=NULL;
		*head=nh;
	}
}

node* push_back(node* tail,int x){
	node* root=(node*) malloc(sizeof(node));
	root->val=x;
	root->next=NULL;

	if(tail!=NULL) tail->next=root;
	return root;
}

void printList(node* head){
	while(head!=NULL){
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n");
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	node* head=NULL;
	node* tail=NULL;

	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		tail=push_back(tail,x);
		if(head==NULL) head=tail;
	}

	rotate(&head,k%n);
	printList(head);
}