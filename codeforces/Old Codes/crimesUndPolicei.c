#include<stdio.h>
int main(){
	int t,crimes=0,police=0; scanf("%d",&t);
	int tally=0;
	while(t--){
		int n; scanf("%d",&n);
		if(n<0){
			crimes+=n;
			if(police>0){
				crimes++; police--;
			}
		}
		else{
			police+=n;
		}
		if(crimes<0){
			tally+=crimes*(-1);
			crimes=0;
		}
	}
	printf("%d",tally);
}