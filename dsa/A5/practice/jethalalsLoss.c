#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head,int data){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->data=data;
	node->next=*head;
	*head=node;
}

void printList(struct Node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	struct Node* a=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		push(&a,x);
	}
	printList(a);
}