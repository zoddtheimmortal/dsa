#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int

int M=1e9+7;

int prime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	int n; scanf("%d",&n);
	ll* arr=(ll*) malloc(sizeof(ll)*n);
	for(int i=0;i<n;i++) scanf("%lld",&arr[i]);

	ll ans=1;
	for(int i=0;i<n;i++){
		if(!prime(arr[i])){
			ans=(ans*arr[i])%M;
		}
	}

	printf("%lld\n",(ans==1?-1:ans));

	free(arr);
}