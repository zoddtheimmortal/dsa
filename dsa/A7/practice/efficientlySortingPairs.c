#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Pair{
	int f,s;
} Pair;

void countingSort(int* arr,int n,int k){
	int count[n+1];
	for(int i=0;i<n+1;i++) count[i]=0;
	for(int i=0;i<k;i++) count[arr[i]]++;
	for(int i=1;i<n+1;i++) count[i]+=count[i-1];

	int output[k];
	for(int i=k-1;i>=0;i--){
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}

	for(int i=0;i<k;i++) arr[i]=output[i];
}

void sortPairs(Pair* arr,int n){
	int count[n+1];
	for(int i=0;i<=n;i++) count[i]=0;
	for(int i=0;i<n;i++) count[arr[i].f]++;
	for(int i=1;i<=n;i++) count[i]+=count[i-1];

	int outputF[n],outputS[n];
	for(int i=n-1;i>=0;i--){
		outputF[count[arr[i].f]-1]=arr[i].f;
		outputS[count[arr[i].f]-1]=arr[i].s;
		count[arr[i].f]--;
	}

	int i=0;
	while(i<n){
		countingSort(outputS+count[i],n,count[i+1]-count[i]);
		i++;
	}

	for(int i=0;i<n;i++) printf("%d ",outputF[i]);
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",outputS[i]);
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	Pair* arr=(Pair*) malloc(sizeof(Pair)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].f);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].s);

	sortPairs(arr,n);
}