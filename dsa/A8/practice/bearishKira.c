#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n,k; scanf("%d %d",&n,&k);
	char arr[n]; scanf("%s",arr);

	int stack[MAX_N],top=-1;
	for(int i=0;i<n;i++){
		while(k>0&&top>=0&&arr[i]<=arr[stack[top]]) top--,k--;
		stack[++top]=i;
	}

	while(k>0&&top>=0) top--,k--;

	long long old=0,new=0,ten=1;
	for(int i=n-1;i>=0;i--){
		old+=(arr[i]-'0')*ten;
		ten*=10;
	}

	ten=1;
	for(int i=top;i>=0;i--){
		new+=(arr[stack[i]]-'0')*ten;
		ten*=10;
	}

	printf("%lld\n",old-new);
}