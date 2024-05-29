#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,k,x;

int cmp(int a,int b){
	if(abs(a-x)==abs(b-x)) return a<b;
	return abs(a-x)<abs(b-x);
}

void heapify(int arr[],int n,int i){
	int left=2*i+1,right=2*i+2,x=i;
	if(left<n&&cmp(arr[i],arr[left])) x=left;
	if(right<n&&cmp(arr[i],arr[right])) x=right;

	if(x!=i){
		int temp=arr[x];
		arr[x]=arr[i];
		arr[i]=temp;
		heapify(arr,n,x);
	}
}

int main(){
	scanf("%d %d %d",&n,&k,&x);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int heap[k]; 
	for(int i=0;i<k;i++) heap[i]=arr[i];

	for(int i=k/2-1;i>=0;i--) heapify(heap,k,i);

	for(int i=k;i<n;i++){
		if(abs(arr[i]-x)<abs(heap[0]-x)){
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