#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

int n,k;

Node* push_back(Node* tail,Node* head,int data){
	Node* node=(Node*) malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;
	if(tail!=NULL){
		tail->next=node;
	}
	if(data==n) node->next=head;
	return node;
}

int josephus(Node* head){
	Node* pivot=head;
	int ans=0;
	while(pivot->next!=NULL){
		Node* kill=pivot;
		for(int i=0;i<k-2;i++) kill=kill->next;
		Node* del=kill->next;
		kill->next=kill->next->next;
		pivot=kill->next;
		ans=del->data;
		free(del);
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&k);
	Node* head=NULL; Node* tail=NULL;
	for(int i=0;i<n;i++){
		tail=push_back(tail,head,i+1);
		if(head==NULL) head=tail;
	}
	int ans=josephus(head);
	printf("%d\n",ans);
}