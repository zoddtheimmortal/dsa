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



void printList(Node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

void rotateList(Node** head,Node** tail,int rot){
	while(rot--){
		Node* back=*head;
		if((*head)!=NULL){
			(*head)=(*head)->next;
		}
		if((*tail)!=NULL){
			(*tail)->next=back;
		}
		(*tail)=back;
		back->next=NULL;
	}
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	Node* head=NULL;
	Node* tail=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		tail=push_back(tail,x);
		if(head==NULL) head=tail;
	}

	rotateList(&head,&tail,k%n);
	printList(head);
}