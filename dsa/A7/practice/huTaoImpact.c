#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(int a,int b){
	return a>b;
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
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		arr[i]+=x;
	}

	int heap[k]; for(int i=0;i<k;i++) heap[i]=arr[i];
	buildHeap(heap,k);

	for(int i=k;i<n;i++){
		if(arr[i]>heap[0]){
			heap[0]=arr[i];
			heapify(heap,k,0);
		}
	}

	int ans=0;
	for(int i=0;i<k;i++) ans+=((heap[i]>0)?heap[i]:0);
	printf("%d\n",ans);
}