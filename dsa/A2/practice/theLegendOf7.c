#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int K=7;

int thala(int* arr,int n){
	int si=0,ei=n-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]==K) return mid;
		if(arr[si]<arr[mid]){
			if(K>=arr[si] && K<arr[mid]){
				ei=mid-1;
			}
			else si=mid+1;
		}else{
			if(K>arr[mid] && K<=arr[ei]){
				si=mid+1;
			}else ei=mid-1;
		}
	}
	return -1;
}

int main(){
	int n; scanf("%d",&n); --n;
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int ans=thala(arr,n);
	printf("%d\n",ans);
	free(arr);
}