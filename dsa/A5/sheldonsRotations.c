#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
};

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
}

void printList(struct Node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

void rotateList(struct Node** head,int rot){
	while(rot--){
		struct Node* back=(*head);
		(*head)=(*head)->next;
		back->next=NULL;

		struct Node* temp=*head;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=back;
	}
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	struct Node* a=NULL;

	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		push_back(&a,x);
	}

	rotateList(&a,k%n);
	printList(a);
}