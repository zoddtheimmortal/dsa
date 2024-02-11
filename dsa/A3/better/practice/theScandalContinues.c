#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int
#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n,k; scanf("%d %d",&n,&k);
	ll* arr=(ll*) malloc(sizeof(ll)*n);
	for(int i=0;i<n;i++) scanf("%lld",&arr[i]);

	int si=0,ei=k-1; ll ans=0;
	while(si<n && ei<n){
		ll cur_sat=0,bit_count=0;
		for(int i=si;i<=ei;i++){
			cur_sat|=arr[i];
		}

		for(int i=0;i<60;i++){
			if(cur_sat&(1LL<<i)) bit_count++;
		}

		ans=max(ans,bit_count);
		si++; ei++;
	}

	printf("%d\n",ans);
	free(arr);
}