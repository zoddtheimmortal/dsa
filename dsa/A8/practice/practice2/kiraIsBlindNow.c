#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int deq[MAX_N],tail=-1,head=0;

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	for(int i=0;i<k;i++){
		while(tail>=head&&arr[i]>=arr[deq[tail]]) tail--;
		deq[++tail]=i;
	}

	for(int i=k;i<n;i++){
		printf("%d ",arr[deq[head]]);
		while(tail>=head&&deq[head]<=i-k) head++;
		while(tail>=head&&arr[i]>=arr[deq[tail]]) tail--;
		deq[++tail]=i;
	}

	printf("%d\n",arr[deq[head]]);
}