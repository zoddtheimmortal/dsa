#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,k,x; scanf("%d %d %d",&n,&k,&x);
	int* arr=(int*) malloc(sizeof(int)*(n+1));
	arr[0]=0;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		arr[i+1]=arr[i]+x;
	}

	int si=1,ei=k,ans=0;
	while(si<=n && ei<=n){
		if((arr[ei]-arr[si-1])/k>=x) ans++;
		si++; ei++;
	}
	printf("%d\n",ans);

	free(arr);
}