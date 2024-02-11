#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int

int M=1e9+7;

int prime(ll a){
	for(int i=2;i*i<=a;i++){
		if(a%i==0) return 0;
	}
	return 1;
}

int main(){
	int n; scanf("%d",&n);
	ll arr[n]; for(int i=0;i<n;i++) scanf("%lld",&arr[i]);

	ll ans=1;
	for(int i=0;i<n;i++){
		if(!prime(arr[i])) ans=(ans*arr[i])%M;
	}

	if(ans==1) ans=-1;

	printf("%lld\n",ans);
}