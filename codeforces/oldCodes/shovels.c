#include<stdio.h>
int main(){
	int k,r; scanf("%d %d",&k,&r);
	for(int i=1;;i++){
		int rem=(i*k)%10;
		if((rem%r==0) && (rem>=r && rem/r==1)){
			printf("%d",i);
			break;
		}
		else if(rem==0){
			printf("%d",i);
			break;
		}
	}	
}