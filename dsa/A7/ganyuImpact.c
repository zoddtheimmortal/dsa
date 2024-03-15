#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,k,x;

void heapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,large=i;
	if(left<n&&abs((arr[left]-x))>=abs((arr[large]-x))) large=left;
	if(right<n&&abs((arr[right]-x))>=abs((arr[large]-x))) large=right;

	if(large!=i){
		int temp=arr[large];
		arr[large]=arr[i];
		arr[i]=temp;
		heapify(arr,n,large);
	}
}

void buildHeap(int* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

void sort(int* arr,int n){
	buildHeap(arr,n);
	for(int i=n-1;i>=0;i--){
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,i,0);
	}
}

int main(){
	scanf("%d %d %d",&n,&k,&x);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr,n);

	int* heap=(int*) malloc(sizeof(int)*k);
	for(int i=0;i<k;i++) heap[i]=arr[i];
	buildHeap(heap,k);

	for(int i=k;i<n;i++){
		if(abs((arr[i]-x))<abs((heap[0]-x))){
			heap[0]=arr[i];
			heapify(heap,k,0);
		}
	}

	sort(heap,k);

	for(int i=0;i<k;i++) printf("%d ",heap[i]);
	printf("\n");
	free(arr); free(heap);
}