#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n,k,x; scanf("%d %d %d",&n,&k,&x);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	double sum=0;
	int si=0,ei=k-1,ans=0;
	for(int i=si;i<=ei;i++) sum+=arr[i];

	while(si<n&&ei<n){
		if((sum*1.0/k)>=x) ans++;
		sum-=arr[si];
		si++; ei++;
		if(ei<n) sum+=arr[ei];
	}

	printf("%d\n",ans);
}