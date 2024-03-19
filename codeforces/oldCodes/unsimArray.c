#include<stdio.h>
int main(){
	int spy[101]; int t; scanf("%d",&t);
	while(t--){
		int n,flag=0; scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",spy[i]);
			if(i!=0 && spy[i]!=spy[i-1]) flag=i;
		}
	}	
}