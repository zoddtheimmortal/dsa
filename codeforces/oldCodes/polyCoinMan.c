#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int a,b,c,n; scanf("%d %d %d %d",&a,&b,&c,&n);
		if((n+a+b+c)%3==0 && n+a+b+c>=3) printf("YES\n"); 
		else printf("NO\n");
	}	
}