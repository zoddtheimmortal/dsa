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
		node->prev=tail;
	}else node->prev=NULL;
	return node;
}

Node* add_next(Node* current,int data){
	Node* node=(Node*) malloc(sizeof(Node));
	node->data=data;
	node->prev=current;
	node->next=current->next;
	if(current->next!=NULL){
		current->next->prev=node;
	}
	current->next=node;
	return node;
}

Node* get_next(Node* current){
	return (current->next!=NULL?current->next:current);
}

Node* get_prev(Node* current){
	return (current->prev!=NULL?current->prev:current);
}

Node* deleteNow(Node** head,Node** tail,Node** current){
	Node* node=((*current)->next!=NULL?(*current)->next:(*current)->prev);
	if((*current)->next!=NULL){
		((*current))->next->prev=((*current))->prev;
	}else *tail=((*current))->prev;

	if((*current)->prev!=NULL){
		((*current))->prev->next=((*current))->next;
	}else *head=((*current))->next;
	((*current))=node;
}

void printList(Node* head,Node* tail){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
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
	Node* current=head;
	while(q--){
		int op; scanf("%d",&op);
		if(op==1){
			printf("%d\n",(current!=NULL?current->data:0));
		}
		else if(op==2){
			int song; scanf("%d",&song);
			add_next(current,song);
		}
		else if(op==3){
			int song; scanf("%d",&song);
			add_back(tail,song);
		}
		else if(op==4){
			current=get_next(current);
		}
		else if(op==5){
			current=get_prev(current);
		}
		else if(op==6){
			deleteNow(&head,&tail,&current);
		}
	}
}