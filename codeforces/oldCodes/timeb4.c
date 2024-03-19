#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int h,m; scanf("%d %d",&h,&m);
		if(h==0 && m==0) printf("0\n");
		else printf("%d\n",((24-h)*60)-m);
	}	
}