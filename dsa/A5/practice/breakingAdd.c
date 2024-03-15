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

struct Node* addList(struct Node* a,struct Node* b){
	int sum=0,carry=0;
	struct Node* c=NULL;
	while(a!=NULL & b!=NULL){
		int temp=a->data+b->data+carry;
		sum=temp%10;
		carry=temp/10;
		push_back(&c,sum);
		a=a->next;
		b=b->next;
	}

	while(a!=NULL){
		int temp=a->data+carry;
		sum=temp%10;
		carry=temp/10;
		push_back(&c,sum);
		a=a->next;
	}

	while(b!=NULL){
		int temp=b->data+carry;
		sum=temp%10;
		carry=temp/10;
		push_back(&c,sum);
		b=b->next;
	}

	if(carry>0) push_back(&c,carry);
	return c;
}

void printList(struct Node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
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

	struct Node* c=addList(a,b);
	printList(c);
}