#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

void heapify(int arr[],int n,int i){
	int left=2*i+1,right=2*i+2,x=i;
	if(left<n&&arr[left]>arr[x]) x=left;
	if(right<n&&arr[right]>arr[x]) x=right;

	if(x!=i){
		int temp=arr[x];
		arr[x]=arr[i];
		arr[i]=temp;
		heapify(arr,n,x);
	}
}

void heapSort(int* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);

	for(int i=n-1;i>=0;i--){
		int temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		heapify(arr,i,0);
	}
}

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	heapSort(arr,n);

	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}