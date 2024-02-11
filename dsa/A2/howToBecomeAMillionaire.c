#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	freopen("becomeMillionaire.out","w",stdout);
	int n,q; scanf("%d %d",&n,&q);
	int* psum=(int*) malloc(sizeof(int)*(n+1));
	psum[0]=0;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		psum[i+1]=psum[i]+x;
	}
	while(q--){
		int l,r; scanf("%d %d",&l,&r);
		printf("%d\n",psum[r]-psum[l-1]);
	}
}