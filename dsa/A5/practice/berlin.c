#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
};

int n,k;

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

int josephus(struct Node** head){
	int ans=0;
	struct Node* pivot=*head;
	while(pivot->next!=NULL){
		struct Node* kill=pivot;
		for(int i=0;i<k-2;i++) kill=kill->next;
		struct Node* temp=kill->next;
		kill->next=(kill->next)->next;
		pivot=kill->next;
		ans=temp->data;
		free(temp);
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&k);
	struct Node* a=NULL;
	for(int i=0;i<n;i++) push_back(&a,i+1);
	int ans=josephus(&a);
	
	printf("%d\n",ans);
}