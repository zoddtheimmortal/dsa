#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int part(int* arr,int si,int ei){
	int pivot=arr[si],i=si,j=ei;

	while(i<j){
		while(i<ei && arr[i]<=pivot) i++;
		while(j>si && arr[j]>pivot) j--;
		if(i<j){
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[si];
	arr[si]=arr[j];
	arr[j]=temp;

	return j;
}

void quickSort(int* arr,int si,int ei){
	if(si>=ei) return;
	int p=part(arr,si,ei);
	quickSort(arr,si,p-1);
	quickSort(arr,p+1,ei);
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	quickSort(arr,0,n-1);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}