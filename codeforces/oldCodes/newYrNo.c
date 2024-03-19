#include<stdio.h>
int main(){
	int t; scanf("%d",&t);	
	while(t--){
		int n; scanf("%d",&n);
		int flag=0;
		for(int i=0;(n-2020*i)>=0;i++){
			if((n-2020*i)%2021==0){
				printf("YES\n");
				flag=1;
				break;
			}
		}
		if(flag==0) printf("NO\n");
	}
}