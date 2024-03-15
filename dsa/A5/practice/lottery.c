#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	char data;
	struct Node* next;
	struct Node* prev;
};

void push(struct Node** head,char data){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->data=data;
	node->prev=NULL;
	node->next=*head;

	if(*head!=NULL) (*head)->prev=node;
	*head=node;
}

int isPali(struct Node** head_ref){
	struct Node* head=*head_ref;
	struct Node* tail=*head_ref;
	while(tail->next!=NULL) tail=tail->next;

	while(head->next!=tail->prev){
		if(head->data!=tail->data) return 0;
		head=head->next;
		tail=tail->prev;
	}
	return 1;
}

int main(){
	int n; scanf("%d",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	struct Node* a=NULL;
	for(int i=0;i<n;i++) push(&a,arr[i]);

	int x=isPali(&a);
	printf("%s\n",(x?"YES":"NO"));
}