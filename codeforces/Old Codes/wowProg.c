#include<stdio.h>
int main(){
	int t;scanf("%d",&t);
	int a=0,min=10001,max=0,count=-2;
	while(t--){
		scanf("%d",&a);
		if(a>max){
			max=a; count++;
		}
		if(a<min){
			min=a; count++;
		}
	}
	printf("%d",count);	
}