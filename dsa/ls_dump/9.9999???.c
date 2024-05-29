#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef long long ll;

ll n,k,l,r,count=0;
char arr[MAX_N];

int combos(int idx,ll sum,ll digit){
	if(idx==n){
		if(sum==k&&l<=digit&&digit<=r){
			return 1;
		}
		return 0;
	}

	if(arr[idx]=='?'){
		int i=0,ans=0;
		if(idx==0) i++;
		for(;i<=9;i++) ans+=combos(idx+1,sum+i,(digit*10)+i);
		return ans;
	}
	else return combos(idx+1,sum+(arr[idx]-'0'),
		(digit*10)+(arr[idx]-'0'));
}

int main(){
	scanf("%lld %lld %lld %lld",&n,&k,&l,&r);
	scanf("%s",arr);
	int ans=combos(0,0LL,0LL);
	printf("%d\n",ans);
}