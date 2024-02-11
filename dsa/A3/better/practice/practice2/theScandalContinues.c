#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int
#define max(a,b) ((a>b)?(a):(b))

int count_bits(ll cur_sat){
	int bit_count=0;
	for(int i=0;i<60;i++){
		if(cur_sat&(1LL<<i)) bit_count++;
	}
	return bit_count;
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	ll arr[n]; for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);

	int si=0,ei=k-1,ans=0;
	while(si<n && ei<n){
		int cur_sat=0;
		for(int i=si;i<=ei;i++) cur_sat|=arr[i];
		ans=max(ans,count_bits(cur_sat));
		si++,ei++;
	}

	printf("%d\n",ans);
}