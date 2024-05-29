#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,k;
int cost[MAX_N],time[MAX_N];

int combos(int idx,int sum,int mins){
	if(idx==n){
		if(mins<=k) return sum;
		return 0;
	}
	return max(combos(idx+1,sum,mins),
		combos(idx+1,sum+cost[idx],mins+time[idx]));
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&cost[i]);
	for(int i=0;i<n;i++) scanf("%d",&time[i]);

	int ans=combos(0,0,0);
	printf("%d\n",ans);
}