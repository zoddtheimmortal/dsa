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

	int minbuy=INT_MAX,profit=0;
	for(int i=0;i<n;i++){
		minbuy=min(minbuy,arr[i]);
		profit=max(profit,arr[i]-minbuy);
	}

	printf("%d\n",profit);
}