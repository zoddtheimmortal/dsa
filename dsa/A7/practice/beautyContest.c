#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,k;

int recurBeauty(int* arr,int x,int* parts){
	if(x==n){
		int max_beauty=INT_MIN;
		for(int i=0;i<k;i++) max_beauty=max(max_beauty,parts[i]);
		return max_beauty;
	}

	int min_beauty=INT_MAX;
	for(int i=0;i<k;i++){
		parts[i]+=arr[x];
		int temp=recurBeauty(arr,x+1,parts);
		parts[i]-=arr[x];
		min_beauty=min(min_beauty,temp);
	}
	return min_beauty;
}

int main(){
	scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int parts[k]; for(int i=0;i<k;i++) parts[i]=0;

	int ans=recurBeauty(arr,0,parts);
	printf("%d\n",ans);
}