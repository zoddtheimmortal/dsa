#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
};

int n,k;

void push_back(struct Node** head,int data){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->data=data;
	node->next=NULL;

	if(*head==NULL){
		*head=node;
		return;
	}

	struct Node* temp=*head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=node;
	if(data==n) node->next=*head;
}

int josephus(struct Node** head){
	struct Node* pivot=*head;
	int left=0;
	while(pivot->next!=NULL){
		struct Node* kill=pivot;
		for(int i=0;i<k-2;i++) kill=kill->next;
		struct Node* temp=kill->next;
		kill->next=(kill->next)->next;
		pivot=kill->next;
		left=temp->data;
		free(temp);
	}
	return left;
}

int main(){
	scanf("%d %d",&n,&k);
	struct Node* a=NULL;

	for(int i=0;i<n;i++) push_back(&a,i+1);
	int x=josephus(&a);
	printf("%d\n",x);
}