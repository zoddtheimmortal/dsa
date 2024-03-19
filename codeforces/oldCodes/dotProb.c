#include<stdio.h>
int gcd(int a,int b);
int main(){
	int y,w; scanf("%d %d",&y,&w);
	int prob=(y>w)?y:w;
	prob=(7-prob);
	if(prob==7) printf("1/1");
	else{
		int div=gcd(prob,6);
		printf("%d/%d",(prob/div),(6/div));
	}
}

int gcd(int a,int b){
	for(int i=a;i>0;i--){
		if(a%i==0 && b%i==0) return i;
	}
}