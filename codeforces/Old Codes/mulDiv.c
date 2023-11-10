#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		if(n==1) printf("%d\n",0);
		else if(n%3==0){
			for(int i=1;;i++){
				if(n%3!=0){printf("%d\n",-1); break;}
				else{
					if(n>=6 && n%6==0) n/=6;
					else n*=2;
					if(n==1){
						printf("%d\n",i);
						break;
					}
				}
			}
		}
		else{
			printf("%d\n",-1);
		}
	}	
}