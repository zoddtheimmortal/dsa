#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int part(int arr[],int l,int r){
	int x=arr[r],i=l;
	for(int j=l;j<r;j++){
		if(arr[j]<x){
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
		}
	}
	int temp=arr[i];
	arr[i]=arr[r];
	arr[r]=temp;
	return i;
}

int quickSelect(int arr[],int si,int ei,int k){
	if(k>0&&k<=(ei-si+1)){
		int p=part(arr,si,ei);
		if(p-si==k-1) return arr[p];
		if(p-si>k-1) return quickSelect(arr,si,p-1,k);

		return quickSelect(arr,p+1,ei,k-(p-si+1));
	}
	return MAX_N;
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int ans=quickSelect(arr,0,n-1,n-k+1);
	printf("%d\n",ans);
}