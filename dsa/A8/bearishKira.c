#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int stack[MAX_N],top=-1;

int main(){
	int n,k; scanf("%d %d",&n,&k);
	char arr[n]; scanf("%s",arr);

	for(int i=0;i<n;i++){
		while(k>0&&top>=0&&arr[stack[top]]>=arr[i]) k--,top--;
		stack[++top]=i;
	}

	while(k&&top>=0){
		top--; k--;
	}

	long long ten=1,price=0,cost=0;
	for(int i=top;i>=0;i--){
		price+=((arr[stack[i]]-'0')*ten);
		ten*=10;
	};

	ten=1;
	for(int i=n-1;i>=0;i--){
		cost+=((arr[i]-'0')*ten);
		ten*=10;
	};

	printf("%lld\n",cost-price);
}