#include<stdio.h>
int main(){
	int n; scanf("%d",&n);
	int sum=0;	
	for(int i=5;i>=1;i--){
		if(n==0){
			break;
		}
		else{
			sum+=n/i;
			n=n%i;
		}
	}
	printf("%d",sum);
}