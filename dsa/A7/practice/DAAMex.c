#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int* count=(int*) malloc(sizeof(int)*(n+1));
	for(int i=0;i<=n;i++) count[i]=0;

	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		count[x]++;
	}

	int arr[n],m=0;
	for(int i=1;i<=n;i++) if(count[i]==0) arr[m++]=i;

	int si=0,ei=m-1,ans=0;
	while(si<ei){
		if(arr[si]+arr[ei]==k){
			ans=1;
			break;
		}
		if(arr[si]+arr[ei]<k) si++;
		if(arr[si]+arr[ei]>k) ei--;
	}

	printf("%s\n",(ans?"yes":"no"));
}