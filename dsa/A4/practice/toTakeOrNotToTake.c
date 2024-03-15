#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,k;

#define max(a,b) ((a>b)?(a):(b))

int recur_cost(int* arr,int* time,int idx,int cost,int rate){
	if(idx==n){
		if(cost>k) return 0;
		else return rate;
	}

	return max(recur_cost(arr,time,idx+1,cost+time[idx],rate+arr[idx]),
		recur_cost(arr,time,idx+1,cost,rate));
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