#include<stdio.h>
#include<stdlib.h>
#include<math.h>
	
#define ll long long int

int M=1e9+7;

ll fast_pow(ll a,ll b){
	if(b==0) return 1LL;
	ll half=fast_pow(a,b/2);
	if(b%2==0){
		return (half*half)%M;
	}
	else return (((half*half)%M)*a)%M;
}

int main(){
	int n; scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int j=0;j<n;j++) scanf("%d",&b[j]);

	ll ans=1;
	for(int i=0;i<n;i++){
		ans=(ans*fast_pow(a[i],b[i]))%M;
	}

	printf("%lld\n",ans);
}