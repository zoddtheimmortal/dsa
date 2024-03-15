#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

int n,k;

void push(struct Node** head,int data){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->data=data;
	node->next=*head;
	node->prev=NULL;

	if((*head)!=NULL) (*head)->prev=node;
	*head=node;
}

void push_back(struct Node** head,int data){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->data=data;
	node->next=NULL;

	if((*head)==NULL){
		*head=node;
		return;
	}

	struct Node* temp=*head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=node;
	node->prev=temp;
}

void remForward(struct Node** head){
	struct Node* temp=*head;
	*head=(*head)->next;
	(*head)->prev=NULL;
	free(temp);
}

void remBack(struct Node** head){
	struct Node* temp=*head;
	while((temp->next)->next!=NULL) temp=temp->next;
	struct Node* del=(temp->next);
	temp->next=NULL;
	free(del);
}

void printForw(struct Node* head){
	if(head==NULL){ printf("-1\n"); return; }
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

void printBack(struct Node* head){
	if(head==NULL){ printf("-1\n"); return; }
	struct Node* back=head;
	while(back->next!=NULL) back=back->next;
	while(back!=NULL){
		printf("%d ",back->data);
		back=back->prev;
	}
	printf("\n");
}

int main(){
	scanf("%d %d",&n,&k);
	struct Node* a=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		push_back(&a,x);
	}

	while(k--){
		int x; scanf("%d",&x);
		if(x==1){
			int data; scanf("%d",&data);
			push(&a,data);
		}
		else if(x==2){
			int data; scanf("%d",&data);
			push_back(&a,data); 
		}
		else if(x==3){
			remForward(&a);
		}
		else if(x==4) remBack(&a);
		else if(x==5) printForw(a);
		else if(x==6) printBack(a);
	}
}