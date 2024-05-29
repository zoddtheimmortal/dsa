#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int summit(int* arr,int n){
	int si=0,ei=n-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]) return mid+1;
		else if(arr[mid]<arr[mid+1]) si=mid+1;
		else ei=mid-1;
	}
	return -1;
}

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int ans=summit(arr,n);
	printf("%d\n",ans);
}