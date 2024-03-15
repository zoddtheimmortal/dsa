#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int* arr,int si,int mid,int ei){
	int i=si,j=mid+1,k=0;
	int temp[ei-si+1];

	while(i<=mid&&j<=ei){
		if(arr[i]<arr[j]) temp[k++]=arr[i++];
		else temp[k++]=arr[j++];
	}

	while(i<=mid) temp[k++]=arr[i++];
	while(j<=ei) temp[k++]=arr[j++];

	i=si,k=0;
	while(i<=ei) arr[i++]=temp[k++];
}

void mergeSort(int* arr,int si,int ei){
	if(si>=ei) return;
	int mid=si+(ei-si)/2;
	mergeSort(arr,si,mid);
	mergeSort(arr,mid+1,ei);
	merge(arr,si,mid,ei);
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");

	free(arr);
} 