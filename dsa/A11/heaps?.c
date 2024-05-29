#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;

void heapify(int* arr,int i){
	int left=2*i+1,right=2*i+2,x=i;
	if(left<n&&arr[left]>arr[x]) x=left;
	if(right<n&&arr[right]>arr[x]) x=right;

	if(x!=i){
		int temp=arr[x];
		arr[x]=arr[i];
		arr[i]=temp;
		heapify(arr,x);
	}
}

int main(){
	scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	for(int i=n/2-1;i>=0;i--) heapify(arr,i);

	int ans=0;
	for(int i=0;i<n-1;i++){
		ans=arr[0]+(2*ans);
		arr[0]=INT_MIN;
		heapify(arr,0);
	}
	ans+=arr[0];
	printf("%d\n",ans);
}