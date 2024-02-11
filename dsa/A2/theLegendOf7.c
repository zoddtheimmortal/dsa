#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int K=7;

int search(int* arr,int n,int key){
	int si=0,ei=n-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]==key) return mid;
		if(arr[si]<arr[mid]){
			//left half sorted
			if(key>=arr[si] && key<arr[mid]){
				ei=mid-1;
			}
			else si=mid+1;
		}
		else{
			if(key>arr[mid] && key<=arr[ei]){
				si=mid+1;
			}
			else ei=mid-1;
		}
	}
	return -1;
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*(n-1));
	for(int i=0;i<n-1;i++){
		scanf("%d",&arr[i]);
	}

	int ans=search(arr,n-1,K);
	printf("%d\n",ans);
	free(arr);
}