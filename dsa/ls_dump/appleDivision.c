#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int arr[MAX_N];

int divide(int idx,int sum1,int sum2){
	if(idx==n) return abs(sum1-sum2);
	return min(divide(idx+1,sum1+arr[idx],sum2),
		divide(idx+1,sum1,sum2+arr[idx]));
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int ans=divide(0,0,0);
	printf("%d\n",ans);
}