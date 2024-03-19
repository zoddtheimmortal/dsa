#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n,x; scanf("%d %d",&n,&x);
		for(int i=1;;i++){
			if(((i-1)*x)+2>=n){
				printf("%d\n",i);
				break;
			}
		}
	}	
}