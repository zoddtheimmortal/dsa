#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		int shalf=0,half=0;
		int k=n%1000; n/=1000;
		while(k){
			half+=k%10; k/=10;
		}
		while(n){
			shalf+=n%10; n/=10;
		}
		(half==shalf)?printf("YES\n"):printf("NO\n");
	}	
}