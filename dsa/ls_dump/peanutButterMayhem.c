#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,k;
int arr[MAX_N];

int combos(int idx,int sum){
	if(sum>k) return 0;
	if(sum==k) return 1;

	int ans=0;
	for(int i=idx;i<n;i++){
		ans+=combos(i,sum+arr[i]);
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int ans=combos(0,0);
	printf("%d\n",ans);
}