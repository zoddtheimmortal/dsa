#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
};

void push(int data,struct Node** head){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node)*1);
	node->data=data;
	node->next=*head;
	(*head)=node;
}

void printList(struct Node* node){
	while(node!=NULL){
		printf("%d ",node->data);
		node=node->next;
	}
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);

	struct Node* head=NULL;
	while(n--){
		int x; scanf("%d",&x);
		push(x,&head);
	}
	printList(head);
}