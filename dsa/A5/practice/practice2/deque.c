#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* add_back(Node* tail,int data){
	Node* node=(Node*) malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;
	if(tail!=NULL){
		tail->next=node;
	}
	node->prev=tail;
	return node;
}

Node* add_front(Node* head,int data){
	Node* node=(Node*) malloc(sizeof(Node));
	node->data=data;
	node->prev=NULL;
	if(head!=NULL){
		head->prev=node;
	}
	node->next=head;
	return node;
}

void delete_front(Node** head){
	if(*head==NULL) return;
	Node* del=*head;
	if((*head)->next!=NULL){
		(*head)->next->prev=NULL;
	}
	*head=(*head)->next;
	free(del);
}

void delete_back(Node** tail){
	if(*tail==NULL) return;
	Node* del=*tail;
	if((*tail)->prev!=NULL){
		(*tail)->prev->next=NULL;
	}
	(*tail)=(*tail)->prev;
	free(del);
}

void printFor(Node* head){
	if(head==NULL){printf("-1\n");return;}
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

void printBack(Node* tail){
	if(tail==NULL){ printf("-1\n"); return;}
	while(tail!=NULL){
		printf("%d ",tail->data);
		tail=tail->prev;
	}
	printf("\n");
}

int main(){
	int n,q; scanf("%d %d",&n,&q);
	Node* head=NULL;
	Node* tail=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		tail=add_back(tail,x);
		if(head==NULL) head=tail;
	}
	while(q--){
		int op; scanf("%d",&op);
		if(op==1){
			int x; scanf("%d",&x);
			head=add_front(head,x);
		}
		else if(op==2){
			int x; scanf("%d",&x);
			tail=add_back(tail,x);
		}
		else if(op==3){
			delete_front(&head);
		}
		else if(op==4){
			delete_back(&tail);
		}
		else if(op==5){
			printFor(head);
		}
		else if(op==6) printBack(tail);
	}
}