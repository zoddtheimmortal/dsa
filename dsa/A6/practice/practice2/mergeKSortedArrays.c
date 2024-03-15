#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

typedef struct Node{
	int val;
	int arrIdx;
	int nextIdx;
} Node;

void heapify(Node* arr,int n,int i){
	int left=2*i+1,right=2*i+2,small=i;
	if(left<n&&arr[small].val>arr[left].val) small=left;
	if(right<n&&arr[small].val>arr[right].val) small=right;

	if(small!=i){
		Node temp=arr[i];
		arr[i]=arr[small];
		arr[small]=temp;
		heapify(arr,n,small);
	}
}

void buildHeap(Node* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

void mergeArrays(int** arrays,int* size,int n){
	Node* heap=(Node*) malloc(sizeof(Node)*n);
	for(int i=0;i<n;i++){
		heap[i].val=arrays[i][0];
		heap[i].arrIdx=i;
		heap[i].nextIdx=1;
	}

	buildHeap(heap,n);

	while(1){
		Node root=heap[0];
		printf("%d ",root.val);

		if(root.nextIdx<size[root.arrIdx]){
			root.val=arrays[root.arrIdx][root.nextIdx++];
		}else root.val=INT_MAX;

		heap[0]=root;
		heapify(heap,n,0);

		if(heap[0].val==INT_MAX) break;
	}
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	int** arrays=(int**) malloc(sizeof(int*)*n);
	int* size=(int*) malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",&size[i]);
		arrays[i]=(int*) malloc(sizeof(int)*size[i]);
		for(int j=0;j<size[i];j++) scanf("%d",&arrays[i][j]);
	}

	mergeArrays(arrays,size,n);
}