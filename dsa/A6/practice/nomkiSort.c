#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int partition(int* arr,int si,int ei){
	int pivot=arr[si],i=si,j=ei;
	while(i<j){
		while(i<ei&&arr[i]<=pivot) i++;
		while(j>si&&arr[j]>pivot) j--;
		if(i<j){
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[j];
	arr[j]=arr[si];
	arr[si]=temp;
	return j;
}

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

void sort(int* arr,int si,int ei,int depth){
	if(si>=ei) return;
	int p=partition(arr,si,ei);
	if(depth==0){
		mergeSort(arr,si,ei);
	}else{
		sort(arr,si,p-1,depth-1);
		sort(arr,p+1,ei,depth-1);
	}
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	sort(arr,0,n-1,log2(n));
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");

	free(arr);
}