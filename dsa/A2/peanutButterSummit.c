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
		ans=mid;
		if(mid+1<n && arr[mid]<arr[mid+1]){
			si=mid+1;
		}
		else if(mid-1>=0 && arr[mid-1]>arr[mid]){
			ei=mid-1;
		}
		else{
			break;
		}
	}

	printf("%d\n",ans+1);
	
	free(arr);
}