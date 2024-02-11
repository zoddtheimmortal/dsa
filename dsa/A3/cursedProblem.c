#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,k,x; scanf("%d %d %d",&n,&k,&x);
	int psum[n+1]; psum[0]=0;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		psum[i+1]=psum[i]+x;
	}
	int ans=0,si=1,ei=si+k-1;
	while(si<=n && ei<=n){
		if((psum[ei]-psum[si-1])/k>=x) ans++;
		si++; ei++;
	}
	printf("%d\n",ans);
}