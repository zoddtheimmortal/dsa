#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
	float data;
	struct Node* next;
} Node;

Node* insert(Node* head,float data){
	Node* node=(Node*) malloc(sizeof(Node));
	node->data=data;
	node->next=head;
	return node;
}

Node* insertionSort(Node* head){
	Node* sorted=NULL;
	Node* curr=head;
	while(curr!=NULL){
		Node* next=curr->next;
		if(sorted==NULL||sorted->data>=curr->data){
			curr->next=sorted;
			sorted=curr;
		}else{
			Node* temp=sorted;
			while(temp->next!=NULL&&temp->next->data<curr->data){
				temp=temp->next;
			}
			curr->next=temp->next;
			temp->next=curr;
		}
		curr=next;
	}
	return sorted;
}

void bucketSort(float* arr,int n){
	Node** buckets=(Node**) malloc(sizeof(Node*)*n);
	int* size=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) buckets[i]=NULL,size[i]=0;

	for(int i=0;i<n;i++){
		int bi=n*arr[i];
		buckets[bi]=insert(buckets[bi],arr[i]);
		size[bi]++;
	}

	for(int i=0;i<n;i++){
		buckets[i]=insertionSort(buckets[i]);
	}

	for(int i=0;i<n;i++){
		Node* node=buckets[i];
		while(node!=NULL){
			printf("%.1f ",node->data);
			node=node->next;
		}
	}
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",size[i]);
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	float arr[n]; for(int i=0;i<n;i++) scanf("%f",&arr[i]);
	bucketSort(arr,n);
}