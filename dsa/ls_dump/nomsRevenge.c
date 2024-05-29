#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

void heapify(int arr[],int n,int i){
	int left=2*i+1,right=2*i+2,x=i;
	if(left<n&&arr[x]<arr[left]) x=left;
	if(right<n&&arr[x]<arr[right]) x=right;

	if(x!=i){
		int temp=arr[i];
		arr[i]=arr[x];
		arr[x]=temp;
		heapify(arr,n,x);
	}
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int heap[k]; for(int i=0;i<k;i++) heap[i]=arr[i];

	for(int i=k/2-1;i>=0;i--) heapify(heap,k,i);

	for(int i=k;i<n;i++){
		if(arr[i]<heap[0]){
			heap[0]=arr[i];
			heapify(heap,k,0);
		}
	}

	int ans=0;
	for(int i=0;i<k;i++) ans+=heap[i],ans%=MOD;
	printf("%d\n",ans);
}