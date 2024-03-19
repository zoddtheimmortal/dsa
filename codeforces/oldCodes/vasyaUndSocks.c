#include<stdio.h>
int main(){
	int n,m; scanf("%d %d",&n,&m);
	for(int i=1;;i++){
		n--;
		if(i%m==0) n++;
		if(n==0){
			printf("%d",i);
			break;
		}
	}	
}