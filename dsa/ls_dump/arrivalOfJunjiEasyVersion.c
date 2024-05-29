#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int arr[MAX_N];

int prime(int x){
	int num=arr[x];
	for(int i=2;i*i<=num;i++){
		if(num%i==0) return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	long long ans=1;
	for(int i=0;i<n;i++){
		if(prime(i)==0){
			ans*=arr[i];
			ans%=MOD;
		}
	}

	printf("%lld\n",(ans==1?-1:ans));
}