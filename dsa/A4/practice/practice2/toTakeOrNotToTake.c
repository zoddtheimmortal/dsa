#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int n,k;

int recur_rate(int* arr,int* time,int idx,int cost,int rate){
	if(idx==n){
		if(cost<=k) return rate;
		return 0;
	}

	return max(recur_rate(arr,time,idx+1,cost+time[idx],rate+arr[idx]),
		recur_rate(arr,time,idx+1,cost,rate));
}

int main(){
	scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	int* time=(int*) malloc(sizeof(int)*n);

	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++) scanf("%d",&time[i]);

	int ans=recur_rate(arr,time,0,0,0);
	printf("%d\n",ans);

	free(arr); free(time);
}