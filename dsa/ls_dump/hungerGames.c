#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int si=0,ei=n-1,ans=-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]==k){
			ans=mid;
			break;
		}
		if(arr[mid]<k) si=mid+1;
		if(arr[mid]>k) ei=mid-1;
	}

	printf("%d\n",ans);
}