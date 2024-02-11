#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int search(int* arr,int n,int k){
	int si=0,ei=n-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]==k) return mid+1;
		else if(arr[mid]>k) ei=mid-1;
		else si=mid+1;
	}
	return -1;
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int ans=search(arr,n,k);
	printf("%d\n",ans);
	free(arr);
}