#include<stdio.h>
#include <stdlib.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		int t1=a-1,t2=abs(b-c)+(c-1);
		if(t2>t1) printf("1\n");
		else if(t1>t2) printf("2\n");
		else printf("3\n");
	}	
}