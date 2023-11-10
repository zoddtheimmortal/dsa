#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int k; scanf("%d",&k);
		int count=0,i=1;
		while(i){
			if(i>=3){
				if(i%3!=0 && i%10!=3){
					count++;
					if(count==k){
						printf("%d\n",i);
						break;
					}
				}
			}
			else{
				count++;
				if(count==k){
					printf("%d\n",i);
					break;
				}
			}
			i++;
		}
	}	
}