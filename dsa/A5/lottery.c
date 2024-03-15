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

int isPali(struct Node* head){
	struct Node* tail=head;
	while(tail->next!=NULL) tail=tail->next;

	while(tail!=head){
		if(tail->data!=head->data) return 0;
		tail=tail->prev;
		head=head->next;
	}
	return 1;
}

int main(){
	int n; scanf("%d",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	struct Node* a=NULL;
	for(int i=0;i<n;i++){
		push(&a,arr[i]);
	}
	int ans=isPali(a);
	printf("%s\n",(ans?"YES":"NO"));
}