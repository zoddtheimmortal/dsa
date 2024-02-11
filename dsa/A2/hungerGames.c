#include <stdio.h>

int search(int arr[],int n,int key){
	int si=0,ei=n-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]==key) return mid+1;
		else if(arr[mid]<key) si=mid+1;
		else ei=mid-1;
	}
	return -1;
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int ans=search(arr,n,k);
	printf("%d\n",ans);
}