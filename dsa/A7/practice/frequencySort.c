#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
	int val,freq,fi;
} Node;

void countSortInd(Node* arr,int n,int k){
	int count[n+1];
	for(int i=0;i<=n;i++) count[i]=0;
	for(int i=0;i<k;i++) count[arr[i].fi]++;
	for(int i=1;i<=n;i++) count[i]+=count[i-1];

	Node* output=(Node*) malloc(sizeof(Node)*k);
	for(int i=k-1;i>=0;i--){
		output[count[arr[i].fi]-1].val=arr[i].val;
		output[count[arr[i].fi]-1].freq=arr[i].freq;
		output[count[arr[i].fi]-1].fi=arr[i].fi;
		count[arr[i].fi]--;
	}

	for(int i=0;i<k;i++) arr[i]=output[i];
}

void countSortFreq(Node* arr,int n){
	int count[n+1];
	for(int i=0;i<=n;i++) count[i]=0;
	for(int i=0;i<n;i++) count[arr[i].freq]++;
	for(int i=1;i<=n;i++) count[i]+=count[i-1];

	Node* output=(Node*) malloc(sizeof(Node)*n);
	for(int i=n-1;i>=0;i--){
		output[count[arr[i].freq]-1].val=arr[i].val;
		output[count[arr[i].freq]-1].freq=arr[i].freq;
		output[count[arr[i].freq]-1].fi=arr[i].fi;
		count[arr[i].freq]--;
	}

	int i=0;
	while(i<n){
		countSortInd(output+count[i],n,count[i+1]-count[i]);
		i++;
	}

	i=0;
	while(output[i].freq==0) i++;
	while(i<n){
		int m=output[i].freq;
		for(int j=0;j<m;j++) printf("%d ",output[i].val);
		i++;
	}
	printf("\n");
}

void freqSort(int* arr,int n){
	Node* count=(Node*) malloc(sizeof(Node)*(n+1));
	for(int i=0;i<=n;i++) count[i].val=i,count[i].freq=0;
	for(int i=0;i<n;i++){
		count[arr[i]].freq++;
		if(count[arr[i]].freq==1) count[arr[i]].fi=i;
	}

	countSortFreq(count,n+1);
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	freqSort(arr,n);
	free(arr);
}