#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		// int way= (n>2)?((n%2==0)?((n/2)-1):(n/2)):0;
		int way=0;
		if(n>2){
			if(n%2==0) way=(n/2)-1;
			else way=n/2;
		}
		printf("%d\n",way);
	}	
}