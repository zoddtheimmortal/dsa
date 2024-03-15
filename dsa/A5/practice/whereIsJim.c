#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
};

int n,d,j;

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
	if(data==n) node->next=*head;
}

void push(struct Node** head,int data){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->data=data;
	node->next=*head;
	*head=node;
	if(data==n){
		struct Node* temp=*head;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=*head;
	}
}

int findMeet(struct Node* jim,struct Node* dwight){
	while(jim->data!=dwight->data){
		jim=jim->next;
		dwight=(dwight->next)->next;
	}
	return jim->data;
}

int main(){
	scanf("%d %d %d",&n,&d,&j);
	struct Node* a=NULL;
	for(int i=0;i<n;i++) push(&a,i+1);

	struct Node* jim=a;
	while(jim->data!=j) jim=jim->next;

	struct Node* dwight=a;
	while(dwight->data!=d) dwight=dwight->next;

	int ans=findMeet(jim,dwight);
	printf("%d\n",ans);
}