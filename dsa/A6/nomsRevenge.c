#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int ll;

void maxHeapify(int arr[],int n,int i){
	int left=2*i+1,right=2*i+2,largest=i;

	if(left<n && arr[left]>arr[largest]) largest=left;
	if(right<n && arr[right]>arr[largest]) largest=right;

	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxHeapify(arr,n,largest);
	}
}

void buildHeap(int arr[],int n){
	for(int i=(n/2-1);i>=0;i--) maxHeapify(arr,n,i);
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int heap[k]; for(int i=0;i<k;i++) heap[i]=arr[i];
	buildHeap(heap,k);

	for(int i=k;i<n;i++){
		if(arr[i]<heap[0]){
			heap[0]=arr[i];
			maxHeapify(heap,k,0);
		}
	}

	ll sum=0;
	for(int i=0;i<k;i++) sum+=heap[i];
	printf("%lld\n",sum);
}