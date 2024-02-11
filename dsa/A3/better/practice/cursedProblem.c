#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,k,x; scanf("%d %d %d",&n,&k,&x);
	int arr[n+1]; arr[0]=0;
	for(int i=0;i<n;i++){
		int j; scanf("%d",&j);
		arr[i+1]=j+arr[i];
	}

	int si=1,ei=k,ans=0;
	while(si<=n && ei<=n){
		int sum=arr[ei]-arr[si-1];
		if(sum/k>=x) ans++;
		si++; ei++;
	}

	printf("%d\n",ans);
}