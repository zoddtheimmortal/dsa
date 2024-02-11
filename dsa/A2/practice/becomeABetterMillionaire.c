#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* psum=(int*) malloc(sizeof(int)*(n+1));
	psum[0]=0;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		psum[i+1]=psum[i]+x;
	}

	int max_psum=psum[1],min_psum=psum[0];
	for(int i=0;i<n+1;i++){
		max_psum=max(max_psum,psum[i]-min_psum);
		if(min_psum>psum[i]) min_psum=psum[i];
	}
	printf("%d\n",max_psum);
}