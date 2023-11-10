#include<stdio.h>
int gcd(int,int);
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		int max=0;
		for(int i=n;i>0;i--){
			for(int j=i-1;j>0;j--){
				if(gcd(i,j)>max) max=gcd(i,j);
			}
		}
		printf("%d\n",max);
	}	
}

int gcd(int a,int b){
	for(int i=(a>b)?b:a;i>0;i++){
		if(a%i==0 && b%i==0) return i;
	}
}