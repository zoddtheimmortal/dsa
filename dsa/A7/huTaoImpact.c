#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int ll;

void heapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,small=i;
	if(left<n&&arr[left]<arr[small]) small=left;
	if(right<n&&arr[right]<arr[small]) small=right;

	if(small!=i){
		int temp=arr[small];
		arr[small]=arr[i];
		arr[i]=temp;
		heapify(arr,n,small);
	}
}

void buildHeap(int* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		arr[i]+=x;
	}

	int* heap=(int*) malloc(sizeof(int)*k);
	for(int i=0;i<k;i++) heap[i]=arr[i];
	buildHeap(heap,k);

	for(int i=k;i<n;i++){
		if(arr[i]>heap[0]){
			heap[0]=arr[i];
			heapify(heap,k,0);
		}
	}

	ll ans=0;
	for(int i=0;i<k;i++) ans+=(heap[i]>=0?heap[i]:0);
	printf("%lld\n",ans);
	
	free(arr); free(heap);
}