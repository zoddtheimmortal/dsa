#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void countingSort(int* arr,int n,int* output,int* index){
	int count[n+1];

	for(int i=0;i<=n;i++) count[i]=0;

	for(int i=0;i<n;i++) count[arr[i]]++;

	for(int i=1;i<=n;i++) count[i]+=count[i-1];

	for(int i=n-1;i>=0;i--){
		output[count[arr[i]]-1]=arr[i];
		index[count[arr[i]]-1]=i+1;
		count[arr[i]]--;
	}
}

int main(){
	int n; scanf("%d",&n);
	int arr[n],output[n],index[n];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	countingSort(arr,n,output,index);
	
	for(int i=0;i<n;i++) printf("%d ",output[i]);
	printf("\n");

	for(int i=0;i<n;i++) printf("%d ",index[i]);
	printf("\n");
}