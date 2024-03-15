#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void heapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,largest=i;
	if(left<n&&arr[left]>arr[largest]) largest=left;
	if(right<n&&arr[right]>arr[largest]) largest=right;

	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr,n,largest);
	}
}

void buildHeap(int* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

int main(){
	freopen("revenge.in","r",stdin);
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int heap[k]; for(int i=0;i<k;i++) heap[i]=arr[i];
	buildHeap(heap,k);

	for(int i=k;i<n;i++){
		if(arr[i]<heap[0]){
			heap[0]=arr[i];
			heapify(heap,k,0);
		}
	}

	int sum=0;
	for(int i=0;i<k;i++) sum+=heap[i];
	printf("%d\n",sum);
}