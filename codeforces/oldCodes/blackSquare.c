#include<stdio.h>
int main(){
	int a1,a2,a3,a4; scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
	int gm; scanf("%d",&gm);
	int cal=0;
	while(gm){
		if(gm%10==1) cal+=a1;
		else if(gm%10==2) cal+=a2;
		else if(gm%10==3) cal+=a3;
		else if(gm%10==4) cal+=a4;
		gm/=10;
	}
	printf("%d",cal);
}