#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int si=0,ei=n-1,ans=-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
			ans=mid+1;
			break;
		}
		else if(arr[mid-1]<arr[mid]) si=mid+1;
		else ei=mid-1;
	}

	printf("%d\n",ans);
}