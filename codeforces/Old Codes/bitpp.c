#include<stdio.h>
#include<string.h>
int main(){
	int t; scanf("%d",&t);
	int x=0;char op[4]; 
	while(t--){
		scanf("%s",&op);
		if(strcmp(op,"x++")==0 || strcmp(op,"++x")==0) x++;
		else if(strcmp(op,"x--")==0 || strcmp(op,"--x")==0) x--;	
	}
	printf("%d",x);
}