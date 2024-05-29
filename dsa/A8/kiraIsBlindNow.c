#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_N (unsigned int)1e6

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n],deq[MAX_N],head=0,tail=-1,i=0;
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	for(i=0;i<k;i++){
		while(tail>=head && arr[i]>=arr[deq[tail]]) tail--;
		deq[++tail]=i;
	}

	for(;i<n;i++){
		printf("%d ",arr[deq[head]]);
		while(tail>=head && deq[head]<=i-k) head++;
		while(tail>=head && arr[i]>=arr[deq[tail]]) tail--;
		deq[++tail]=i;
	}
	printf("%d \n",arr[deq[head]]);
}