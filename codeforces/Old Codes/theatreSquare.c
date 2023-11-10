#include<stdio.h>
int main(){
	int n,m,a; scanf("%d %d %d",&n,&m,&a);
	int sum=1;
	sum*=(n%a==0)?(n/a):(n/a+1);
	sum*=(m%a==0)?(m/a):(m/a+1);
	printf("%d",sum);	
}