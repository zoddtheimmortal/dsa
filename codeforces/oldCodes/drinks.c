#include<stdio.h>
int main(){
	int n; scanf("%d",&n);
	int k=n; long double sum=0;
	while(k--){
		int p; scanf("%d",&p);
		sum+=p;
	}
	printf("%Lf",sum/n);
}