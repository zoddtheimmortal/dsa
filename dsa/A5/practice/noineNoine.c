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

void mergeLists(struct Node* a,struct Node* b){
	while(a!=NULL && b!=NULL){
		if(a->data<b->data){
			printf("%d ",a->data);
			a=a->next;
		}else{
			printf("%d ",b->data);
			b=b->next;
		}
	}

	while(a!=NULL){
		printf("%d ",a->data);
		a=a->next;
	}
	while(b!=NULL){
		printf("%d ",b->data);
		b=b->next;
	}
}

int main(){
	int n,m; scanf("%d %d",&n,&m);
	struct Node* a=NULL; struct Node* b=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		push_back(&a,x);
	}
	for(int i=0;i<m;i++){
		int x; scanf("%d",&x);
		push_back(&b,x);
	}

	mergeLists(a,b);
	printf("\n");
}