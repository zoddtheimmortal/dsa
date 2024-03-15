#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,k,x;

int cmp(int a,int b){
	if(abs(a-x)==abs(b-x)){
		return a<b;
	}
	return abs((a-x))<abs((b-x));
}

void heapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,p=i;
	if(left<n&&cmp(arr[p],arr[left])) p=left;
	if(right<n&&cmp(arr[p],arr[right])) p=right;

	if(p!=i){
		int temp=arr[p];
		arr[p]=arr[i];
		arr[i]=temp;
		heapify(arr,n,p);
	}
}

void buildHeap(int* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

int main(){
	scanf("%d %d %d",&n,&k,&x);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int* heap=(int*) malloc(sizeof(int)*k);
	for(int i=0;i<k;i++) heap[i]=arr[i];

	buildHeap(heap,k);

	for(int i=k;i<n;i++){
		if(abs((arr[i]-x))<abs((heap[0]-x))){
			heap[0]=arr[i];
			heapify(heap,k,0);
		}
	}

	for(int i=k-1;i>=0;i--){
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		heapify(heap,i,0);
	}

	for(int i=0;i<k;i++) printf("%d ",heap[i]);
	printf("\n");
}