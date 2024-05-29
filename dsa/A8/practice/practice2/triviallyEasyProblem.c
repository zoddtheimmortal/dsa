#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n],qmax[MAX_N],qmin[MAX_N];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int tail1=-1,head1=0,tail2=-1,head2=0,j=0;
	
	long long ans=0;
	for(int i=0;i<n;i++){
		while(tail1>=head1&&arr[i]>arr[qmax[tail1]]) tail1--;
		while(tail2>=head2&&arr[i]<arr[qmin[tail2]]) tail2--;
		qmax[++tail1]=i;
		qmin[++tail2]=i;

		while(arr[qmax[head1]]-arr[qmin[head2]]>k){
			j++;
			if(qmax[head1]<j) head1++;
			if(qmin[head2]<j) head2++;
		}

		ans+=(i-j+1);
	}
	printf("%lld\n",ans);
}