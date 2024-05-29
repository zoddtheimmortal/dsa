#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,k;
int minute[MAX_N],cost[MAX_N];

int rating(int idx,int time,int sum){
	if(idx==n){
		if(time<=k) return sum;
		return 0;
	}

	return max(rating(idx+1,time+minute[idx],sum+cost[idx]),
		rating(idx+1,time,sum));
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&cost[i]);
	for(int i=0;i<n;i++) scanf("%d",&minute[i]);

	int ans=rating(0,0,0);
	printf("%d\n",ans);
}