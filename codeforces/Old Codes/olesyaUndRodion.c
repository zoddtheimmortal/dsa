#include<stdio.h>
#include<math.h>
int main(){
	int n,t; scanf("%d %d",&n,&t);
	long long int lp=pow(10,n-1),flag=0;
	for(long long int i=lp+1;;i++){
		if(i%t==0){
			printf("%Ld",i);
			flag=1;
			break;
		}
	}
	if(flag==0) printf("-1");
}