#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)2e3+1)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n; scanf("%d",&n);
	int k=0,arr[MAX_N];
	for(int i=0;i<n;i++){
		int si,ei; scanf("%d %d",&si,&ei);
		arr[si-1]=1;
		arr[ei]=-1;
		k=max(k,ei);
	}

	for(int i=0;i<k;i++){
		arr[i+1]+=arr[i];
	}

	int si=0,ei=0,p=0;
	int start[k+1],end[k+1];

	while(si<k&&ei<k){
		while(si<k&&arr[si]==0) si++;
		ei=si+1;
		while(ei<k&&arr[ei]!=0) ei++;
		ei--;
		start[p]=si,end[p]=ei;
		p++;
		si=ei;
	}

	printf("%d\n",p);
}