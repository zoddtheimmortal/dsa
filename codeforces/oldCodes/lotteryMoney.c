#include<stdio.h>
int main(){
	int n;scanf("%d",&n);
	int sum=0; int billarr[5]={100,20,10,5,1};
	while(n){
		for(int i=0;i<5;i++){
			sum+=n/billarr[i];
			n=n%billarr[i];
		}
	}
	printf("%d",sum);

}