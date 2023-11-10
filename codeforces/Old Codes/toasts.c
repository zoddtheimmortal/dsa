#include<stdio.h>
int main(){
	int n,k,l,c,d,p,nl,np; scanf("%d %d %d %d %d %d %d %d",&n,&k,&l,&c,&d,&p,&nl,&np);	
	int vol=l*k,lime=c*d,salt=p;
	vol/=(n*nl);lime/=n;salt/=(n*np);
	int toast=(vol>lime)?((salt>lime)?lime:salt):((salt>vol)?vol:salt);
	printf("%d",toast);
}