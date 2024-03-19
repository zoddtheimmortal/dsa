#include<stdio.h>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int odd=n-n/2, even=n/2;	
	if(k>odd){
		int count=1;
		for(int i=2;i<=n;i+=2){
			if(count+odd==k){
				printf("%d",i);
				break;
			}
			count++;
		}
	}
	else{
		int count=1;
		for(int i=1;i<=n;i+=2){
			if(count==k){
				printf("%d",i);
				break;
			}
			count++;
		}
	}
}