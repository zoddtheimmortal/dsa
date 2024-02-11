#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,k,x; scanf("%d %d %d",&n,&k,&x);
	int arr[n+1];
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		arr[i+1]=arr[i]+x;
	}

	int ans=0,si=1,ei=k;
	while(si<=n && ei<=n){
		int sum=arr[ei]-arr[si-1];
		if(sum/k>=x) ans++;
		si++; ei++;
	}

	printf("%d\n",ans);
}