#include<stdio.h>
int main(){
	int a,b; scanf("%d %d",&a,&b);
	int three=3,two=2;
	for(int i=1;;i++){
		if(three*a>two*b){printf("%d",i); break;}
		three*=3;two*=2;
	}	
}