#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int a,b; scanf("%d %d",&a,&b);
		int val= (a>b)?((a%b==0)?0:(b-(a%b))):(b-a);
		printf("%d\n",val);
	}	
}