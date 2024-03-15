#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int* arr,int si,int mid,int ei){
	int i=si,j=mid+1,k=0;
	int* temp=(int*) malloc(sizeof(int)*(ei-si+1));

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

void quickSort(int* arr,int si,int ei,int depth){
	if(si>=ei) return;
	int p=part(arr,si,ei);

	if(depth==0) mergeSort(arr,si,ei);
	else{
		quickSort(arr,si,p-1,depth-1);
		quickSort(arr,p+1,ei,depth-1);
	}
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	quickSort(arr,0,n-1,2*log2(n));
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}