#include<stdio.h>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int odd=n-n/2, even=n/2;
	int num=(k<=odd)?((2*k)-1):(2+2*(k-1-odd));
	printf("%d",num);	
}