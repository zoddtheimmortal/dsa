#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		if(n>=1900) printf("Division 1\n");
		else if(n>=1600) printf("Division 2\n");
		else if(n>=1400) printf("Division 3\n");
		else printf("Division 4\n");
	}	
}