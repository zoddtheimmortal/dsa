#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int arr[MAX_N];

int partition(int si,int ei){
	int pivot=arr[si];
	int i=si,j=ei;

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

void quickSort(int si,int ei){
	if(si>ei) return;

	int p=partition(si,ei);
	quickSort(si,p-1);
	quickSort(p+1,ei);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	quickSort(0,n-1);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}