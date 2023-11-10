#include<stdio.h>
int main(){
	int x; scanf("%d",&x);
	int bact1=0,bact2=0,flag=0;	
	for(int i=2;i>0;i++){
		if(x%i==0){
			for(int j=1;;j*=i){
				if(j==)
			}
		}
	}
	int min=x-1;
	for(int i=1;i<=x;i*=2){
		if((x-i)<min) min=x-i;
	}
	bact2=min+1;
	if(flag==0) {
		bact1= bact2+1;
	}
	min=(bact1>bact2)?bact2:bact1;
	printf("%d",min);
}