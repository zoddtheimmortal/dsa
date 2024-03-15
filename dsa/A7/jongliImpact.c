#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void heapify(int* arr,int* comp,int n,int i){
	int left=2*i+1,right=2*i+2,large=i;
	if(left<n&&comp[left]>comp[large]) large=left;
	if(right<n&&comp[right]>comp[large]) large=right;

	if(large!=i){
		int temp=arr[i];
		arr[i]=arr[large];
		arr[large]=temp;
		heapify(arr,comp,n,large);
	}	
}

void sort(int* arr,int* comp,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,comp,n,i);
	for(int i=n-1;i>=0;i--){
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,comp,i,0);
	}
}

int main(){
	int n,x; scanf("%d %d",&n,&x);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int k=0;
	for(int i=0;i<n;i++) if(arr[i]<x) k++;
	
	int j=0;
	int heap[k]; for(int i=0;i<n;i++) if(arr[i]<x) heap[j++]=i;

	sort(heap,arr,k);

	printf("%d\n",k);
	for(int i=0;i<k;i++) printf("%d ",heap[i]+1);
	printf("\n");
}