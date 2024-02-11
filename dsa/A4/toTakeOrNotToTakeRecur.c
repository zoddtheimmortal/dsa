#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int n,k;

int recur_cost(int* arr,int* cost,int idx,int c,int diff){
	if(idx==n){
		if(c<=k) return diff;
		else return 0;
	}

	return max(recur_cost(arr,cost,idx+1,c+cost[idx],diff+arr[idx]),
		recur_cost(arr,cost,idx+1,c,diff));
}

int main(){
	scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	int* cost=(int*) malloc(sizeof(int)*n);

	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++) scanf("%d",&cost[i]);

	int ans=recur_cost(arr,cost,0,0,0);
	printf("%d\n",ans);

	free(arr); free(cost);
}