#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int x,y,n; scanf("%d %d %d",&x,&y,&n);
		for(int i=n;;i--){
			if(i%x==y){
				printf("%d\n",i);
				break;
			}
		}
	}	
}