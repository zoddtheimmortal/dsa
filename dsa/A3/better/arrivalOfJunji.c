#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int

ll MOD=1e9+7;

int prime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	ll ans=1;
	for(int i=0;i<n;i++){
		if(prime(arr[i])==0){
			ans=(ans*arr[i])%MOD;
		};
	}
	printf("%d\n",(ans==1?(-1):ans));
	free(arr);
}