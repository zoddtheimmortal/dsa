#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int prefix[n+1]; prefix[0]=0;
	for(int i=0;i<n;i++) prefix[i+1]=arr[i]+prefix[i];

	int ans=prefix[0],minsum=prefix[1];
	for(int i=0;i<n+1;i++){
		minsum=min(minsum,prefix[i]);
		ans=max(ans,prefix[i]-minsum);
	}

	printf("%d\n",ans);
}