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

int giveMeet(struct Node* jim,struct Node* dwight){
	while(jim->data != dwight->data){
		jim=jim->next;
		dwight=(dwight->next)->next;
	}
	return jim->data;
}

int main(){
	scanf("%d %d %d",&n,&d,&j);
	struct Node* a=NULL;
	for(int i=0;i<n;i++) push_back(&a,i+1);

	struct Node* jim=a;struct Node* dwight=a;
	while(jim->data!=j) jim=jim->next;
	while(dwight->data!=d) dwight=dwight->next;

	int ans=giveMeet(jim,dwight);
	printf("%d\n",ans);
}