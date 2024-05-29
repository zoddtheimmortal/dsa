#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n,q; scanf("%d %d",&n,&q);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int prefix[n+1]; prefix[0]=0;
	for(int i=0;i<n;i++) prefix[i+1]=arr[i]+prefix[i];

	int si,ei;
	while(q--){
		scanf("%d %d",&si,&ei);
		printf("%d\n",prefix[ei]-prefix[si-1]);
	}
}