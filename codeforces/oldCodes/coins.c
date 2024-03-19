#include<stdio.h>
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		int c1=n/3,c2=n/3;
		for(int i=0;;i++){
			if((c1+i)+(2*c2)==n){
				c1+=i;
				printf("%d %d\n",c1,c2);
				break;
			}
			else if(c1+2*(c2+i)==n){
				c2+=i;
				printf("%d %d\n",c1,c2);
				break;
			}
		}
	}	
}