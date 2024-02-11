#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int K=7;

int main(){
	int n; scanf("%d",&n);
	n--;
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int si=0,ei=n-1,ans=-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]==K){
			ans=mid;
			break;
		}
		if(arr[si]<arr[mid]){
			if(arr[si]<=K && arr[mid]>K){
				ei=mid-1;
			}else si=mid+1;
		}
		else{
			if(arr[mid]<K && K<=arr[ei]){
				si=mid+1;
			}else ei=mid-1;
		}
	}
	printf("%d\n",ans);
	free(arr);
}