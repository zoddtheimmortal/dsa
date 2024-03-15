#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* push_back(Node* tail,int data){
	Node* node=(Node*) malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;

	if(tail!=NULL){
		tail->next=node;
	}
	return node;
}

void removeDupes(Node** head){
	Node* pivot=*head;
	while(pivot->next!=NULL){
		if(pivot->data==(pivot->next)->data){
			Node* rem=pivot->next;
			pivot->next=rem->next;
			free(rem);
		}else pivot=pivot->next;
	}
}

void printList(Node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	Node* head=NULL; Node* tail=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		tail=push_back(tail,x);
		if(head==NULL) head=tail;
	}

	removeDupes(&head);
	printList(head);
}