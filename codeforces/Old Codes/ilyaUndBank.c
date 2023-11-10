#include<stdio.h>
int main(){
	int n; scanf("%d",&n);
	if(n>=0) printf("%d",n);
	else{
		n*=-1; int ten=10;
		int l=n,k=n/10,m=(n/100)*10+(n%10);
		int min=(k>l)?((m>l)?l:m):((m>k)?k:m);
		printf("%d",min*-1);
	}
}