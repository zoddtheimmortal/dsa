#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

void push(struct Node** head,int data){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));

	node->data=data;
	node->next=(*head);
	node->prev=NULL;

	if((*head)!=NULL) (*head)->prev=node;

	(*head)=node;
}

void reverse(struct Node** head){
	struct Node* temp;
	struct Node* cur=*head;

	while(cur!=NULL){
		temp=cur->prev;
		cur->prev=cur->next;
		cur->next=temp;
		cur=cur->prev;
	}

	if(temp!=NULL) *head=temp->prev;
}

struct Node* addList(struct Node* a,struct Node* b){
	int carry=0,sum=0;
	struct Node* c=NULL;

	while(a!=NULL && b!=NULL){
		int temp=(a->data)+(b->data)+carry;
		sum=temp%10; carry=temp/10;

		push(&c,sum);
		a=a->next; b=b->next;
	}

	while(a!=NULL){
		int temp=(a->data)+carry;
		sum=temp%10; carry=temp/10;

		push(&c,sum);
		a=a->next;
	}
	while(b!=NULL){
		int temp=(b->data)+carry;
		sum=temp%10; carry=temp/10;

		push(&c,sum);
		b=b->next;
	}

	if(carry!=0) push(&c,carry);

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

	struct Node* a=NULL;struct Node* b=NULL;

	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		push(&a,x);
	}

	for(int i=0;i<m;i++){
		int x; scanf("%d",&x);
		push(&b,x);
	}

	reverse(&a); reverse(&b);

	struct Node* c=addList(a,b);

	reverse(&c);

	printList(c);
}