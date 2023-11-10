#include<stdio.h>
int main(){
	int n,m; scanf("%d %d",&n,&m);
	int flag=-1;
	for(int i=1;i<=n;i++){
		if(i%2==0) flag*=-1;
		for(int j=1;j<=m;j++){
			if(flag==1 && i%2==0){
				if(j==m) printf("#");
				else printf(".");
			}
			else if(flag==-1 && i%2==0){
				if(j==1) printf("#");
				else printf(".");
			}
			else printf("#");
		}
		printf("\n");
	}	
}