#include<stdio.h>
int main(){
	int n,m,a,b; scanf("%d %d %d %d",&n,&m,&a,&b);
	int sum1=((n/m)*b)+((n%m)*a),sum2=n*a,sum3=(((n/m)*b)+b);
	int rubles= (sum1>sum2)?(sum3>sum2?(sum2):(sum3)):(sum3>sum1?sum1:sum3);
	printf("%d",rubles);
}