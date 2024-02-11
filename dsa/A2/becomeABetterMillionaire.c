#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* psum=(int*) malloc(sizeof(int)*(n+1));
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		psum[i+1]=psum[i]+x;
	}
	int presum_min=psum[0],max_presum=psum[1];
	for(int i=1;i<n+1;i++){
		if(presum_min>psum[i]) presum_min=psum[i];
		max_presum=max(max_presum,psum[i]-presum_min);
	}
	free(presum_min);
	printf("%d\n",max_presum);
}