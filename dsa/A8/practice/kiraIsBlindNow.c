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

	int deq[MAX_N],head=0,tail=-1,i=0;

	for(;i<k;i++){
		while(tail>=head&&arr[deq[tail]]<=arr[i]) tail--;
		deq[++tail]=i;
	}

	for(;i<n;i++){
		printf("%d ",arr[deq[head]]);
		while(tail>=head&&deq[head]<=i-k) head++;
		while(tail>=head&&arr[deq[tail]]<=arr[i]) tail--;
		deq[++tail]=i;
	}
	printf("%d \n",arr[deq[head]]);
}