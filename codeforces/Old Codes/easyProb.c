#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	int sum=0;
	while(t--){
		int op; scanf("%d",&op);
		sum+=op;
	}
	(sum==0)?(printf("EASY")):(printf("HARD"));
}