#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef struct node{
	int val,arrayIdx,nextIdx;
} node;

void heapify(node* arr,int n,int i){
	int left=2*i+1,right=2*i+2,x=i;
	if(left<n&&arr[left].val<arr[x].val) x=left;
	if(right<n&&arr[right].val<arr[x].val) x=right;

	if(x!=i){
		node temp=arr[x];
		arr[x]=arr[i];
		arr[i]=temp;
		heapify(arr,n,x);
	}
}

void mergeKArrays(int** arrays,int* sizes,int k){
	node heap[k];
	for(int i=0;i<k;i++){
		heap[i].val=arrays[i][0];
		heap[i].arrayIdx=i;
		heap[i].nextIdx=1;
	}

	for(int i=k/2-1;i>=0;i--) heapify(heap,k,i);

	while(1){
		node root=heap[0];
		printf("%d ",root.val);

		if(root.nextIdx<sizes[root.arrayIdx]){
			root.val=arrays[root.arrayIdx][root.nextIdx++];
		}else root.val=INT_MAX;

		heap[0]=root;
		heapify(heap,k,0);
		if(heap[0].val==INT_MAX) break;
	}
	printf("\n");
}

int main(){
	int k; scanf("%d",&k);
	int** arrays=(int**) malloc(sizeof(int*)*k);
	int* sizes=(int*) malloc(sizeof(int)*k);

	for(int i=0;i<k;i++){
		scanf("%d",&sizes[i]);
		arrays[i]=(int*) malloc(sizeof(int)*sizes[i]);
		for(int j=0;j<sizes[i];j++) scanf("%d",&arrays[i][j]);
	}
	
	mergeKArrays(arrays,sizes,k);
}