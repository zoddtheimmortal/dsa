#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* psum=(int*) malloc(sizeof(int)*(n+1));
	psum[0]=0;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		psum[i+1]=x+psum[i];
	}

	int min_profit=psum[0],max_sum=psum[1];
	for(int i=0;i<n+1;i++){
		if(psum[i]<min_profit) min_profit=psum[i];
		max_sum=max(max_sum,psum[i]-min_profit);
	}
	printf("%d\n",max_sum);
}