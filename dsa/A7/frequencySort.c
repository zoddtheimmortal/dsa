#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Pair{
	int val,freq,fi;
} Pair;

Pair* countSort(Pair* arr,int n){
	int count[n+1]; for(int i=0;i<=n;i++) count[i]=0;
	for(int i=0;i<n;i++) count[arr[i].freq]++;

	for(int i=1;i<=n;i++) count[i]+=count[i-1];

	Pair* output=(Pair*) malloc(sizeof(Pair)*n);
	for(int i=n-1;i>=0;i--){
		output[count[arr[i].freq]-1].freq=arr[i].freq;
		output[count[arr[i].freq]-1].val=arr[i].val;
		output[count[arr[i].freq]-1].fi=arr[i].fi;
		count[arr[i].freq]--;
	}
	return output;
}

void sort(int* arr,int n){
	Pair* count=(Pair*) malloc(sizeof(Pair)*(n+1));
	for(int i=0;i<=n;i++) count[i].freq=0,count[i].val=i;

	for(int i=0;i<n;i++){
		count[arr[i]].freq++;
		if(count[arr[i]].freq==1) count[arr[i]].fi=i;
	}

	count=countSort(count,n+1);
	
	int* output=(int*) malloc(sizeof(int)*n);
	int i=0,k=0;
	while(count[i].freq==0) i++;
	while(i<=n){
		int m=count[i].freq;
		for(int j=0;j<m;j++) output[k++]=count[i].val;
		i++;
	}

	for(int i=0;i<n;i++) arr[i]=output[i];
}

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	sort(arr,n);

	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}