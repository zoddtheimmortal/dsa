#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,k,count=0;

void recur_sum(int* arr,int sum,int idx){
	if(sum>k) return;
	if(sum==k){
		count++;
		return;
	}

	for(int i=idx;i<n;i++){
		recur_sum(arr,sum+arr[i],i);
	}
}

int main(){
	scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	recur_sum(arr,0,0);
	printf("%d\n",count);

	free(arr);
}