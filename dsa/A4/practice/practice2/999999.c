#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int

ll n,k,l,r,count=0;

void recur_sal(char* arr,int idx,int sum,ll num){
	if(idx==n){
		if(sum==k && num>=l && num<=r){
			count++;
		}
		return;
	}

	int sn=0;
	if(idx==0) sn++;

	if(arr[idx]=='?'){
		for(int i=sn;i<10;i++){
			recur_sal(arr,idx+1,sum+i,(num*10)+i);
		}
	}
	else recur_sal(arr,idx+1,sum,(num*10)+(arr[idx]-'0'));
}

int main(){
	scanf("%lld %lld %lld %lld",&n,&k,&l,&r);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	int sum=0;
	for(int i=0;i<n;i++){
		if(arr[i]!='?') sum+=(arr[i]-'0');
	}

	recur_sal(arr,0,sum,0LL);
	printf("%d\n",count);

	free(arr);
}