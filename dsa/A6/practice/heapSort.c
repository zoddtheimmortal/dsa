#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void heapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,largest=i;
	if(left<n&&arr[left]>arr[largest]) largest=left;
	if(right<n&&arr[right]>arr[largest]) largest=right;

	if(largest!=i){
		int temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		heapify(arr,n,largest);
	}
}

void heapSort(int* arr,int n){
	for(int i=(n/2)-1;i>=0;i--) heapify(arr,n,i);
	for(int i=n-1;i>=0;i--){
		int temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		heapify(arr,i,0);
	}
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	heapSort(arr,n);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");

	free(arr);
}