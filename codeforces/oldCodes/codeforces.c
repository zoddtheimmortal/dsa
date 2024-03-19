#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	char code[11]="codeforces";
	while(t--){
		char c; scanf("%c",&c);
		int flag=0;
		for(int i=0;i<10;i++){
			if(c==code[i]){
				flag=1;
				break;
			}
		}
		(flag==0)?(printf("NO\n")):printf("YES\n");
	}	
}