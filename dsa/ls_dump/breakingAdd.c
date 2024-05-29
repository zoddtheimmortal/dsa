#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef struct node{
	int val;
	struct node* next;
} node;

node* push_back(node* tail,int x){
	node* root=(node*) malloc(sizeof(node));
	root->val=x;
	root->next=NULL;

	if(tail!=NULL) tail->next=root;
	return root;
}

node* addLists(node* a,node* b){
	int sum=0,carry=0;
	node* ch=NULL;
	node* ct=NULL;

	printf("%d %d\n",a->val,b->val);
	while(a!=NULL&&b!=NULL){
		int x=a->val,y=b->val;
		sum=(x+y+carry)%10;
		carry=(x+y+carry)/10;
		ct=push_back(ct,sum);
		if(ch==NULL) ch=ct;

		a=a->next;
		b=b->next;
	}

	while(a!=NULL){
		int x=a->val;
		sum=(x+carry)%10;
		carry=(x+carry)/10;
		ct=push_back(ct,sum);
		a=a->next;
	}

	while(b!=NULL){
		int x=b->val;
		sum=(x+carry)%10;
		carry=(x+carry)/10;
		ct=push_back(ct,sum);
		b=b->next;
	}

	if(carry>0) ct=push_back(ct,carry);
	return ch;
}

void printList(node* head){
	while(head!=NULL){
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n");
}

int main(){
	int n,m; scanf("%d",&n,&m);

	node* ah=NULL;
	node* at=NULL;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		at=push_back(at,x);
		if(ah==NULL) ah=at;
	}

	printList(ah);

	// node* bh=NULL;
	// node* bt=NULL;
	// for(int i=0;i<m;i++){
	// 	int x; scanf("%d",&x);
	// 	bt=push_back(bt,x);
	// 	if(bh==NULL) bh=bt;
	// }

	// node* ans=addLists(ah,bh);
	// printList(ans);
}