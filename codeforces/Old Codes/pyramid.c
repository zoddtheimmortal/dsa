#include<stdio.h>
int main(){
	int n; scanf("%d",&n);
	int sum=0,h=0;
	for(int i=1;;i++){
		if(sum+((i*(i+1)/2))<=n){
			sum+=(i*(i+1))/2;
			h=i;
		}
		else{
			break;
		}
	}
	printf("%d",h);	
}