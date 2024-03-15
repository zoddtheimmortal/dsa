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

void removeDupes(struct Node* head){
	while(head->next!=NULL){
		if(head->data==(head->next)->data){
			struct Node* temp=head->next;
			head->next=(head->next)->next;
			free(temp);
		}
		else head=head->next;
	}
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
		push_back(&a,x);
	}
	removeDupes(a);
	printList(a);
}