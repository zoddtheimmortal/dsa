#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int

ll n,k,l,r,count=0;

void recur_combos(char* arr,int idx,ll sum,ll num){
	if(idx==n){
		if(sum==k && l<=num && num<=r){
			printf("%lld\n",num);
			count++;
		}
		return;
	}

	ll sn=0;
	if(idx==0) sn++;

	if(arr[idx]=='?'){
		for(int i=sn;i<=9;i++) recur_combos(arr,idx+1,sum+i,(num*10)+i);
	}
	else recur_combos(arr,idx+1,sum,(num*10)+(arr[idx]-'0'));
}

int main(){
	freopen("9999.in","r",stdin);
	freopen("9999.out","w",stdout);
	scanf("%lld %lld %lld %lld",&n,&k,&l,&r);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	ll sum=0;
	for(int i=0;i<n;i++){
		if(arr[i]!='?') sum+=(arr[i]-'0');
	}

	recur_combos(arr,0,sum,0LL);
	printf("%lld\n",count);
	free(arr);
}