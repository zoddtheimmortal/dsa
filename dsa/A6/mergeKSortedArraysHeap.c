1#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

typedef struct Node{
	int val,arrayIdx,nextIdx;
} Node;

void minHeapify(Node heap[],int n,int i){
	int left=2*i+1,right=2*i+2,smallest=i;
	if(left<n&&heap[smallest].val>heap[left].val) smallest=left;
	if(right<n&&heap[smallest].val>heap[right].val) smallest=right;

	if(smallest!=i){
		Node temp=heap[smallest];
		heap[smallest]=heap[i];
		heap[i]=temp;
		minHeapify(heap,n,smallest);
	}
}

void buildMinHeap(Node heap[],int n){
	for(int i=n/2-1;i>=0;i--) minHeapify(heap,n,i);
}

void mergeArrays(int** arrays,int* size,int n){
	Node* heap=(Node*) malloc(sizeof(Node)*n);
	for(int i=0;i<n;i++){
		heap[i].val=arrays[i][0];
		heap[i].arrayIdx=i;
		heap[i].nextIdx=1;
	}

	buildMinHeap(heap,n);

	while(1){
		Node root=heap[0];
		printf("%d ",root.val);

		if(root.nextIdx<size[root.arrayIdx]){
			root.val=arrays[root.arrayIdx][root.nextIdx++];
		}else root.val=INT_MAX;

		heap[0]=root;
		minHeapify(heap,n,0);

		if(heap[0].val==INT_MAX) break;
	}
	free(heap);
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
	for(int i=0;i<n;i++) free(arrays[i]);
	free(size); free(arrays);
}