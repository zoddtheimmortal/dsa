#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	freopen("vidya.in","r",stdin);
	freopen("vidya.out","w",stdout);
	int n,m; scanf("%d %d",&n,&m);
	char arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c; scanf("%c",&c);
			if(c!='\n') arr[i][j]=c;
			else j--;
		}
	}

	for(int j=0;j<m;j++){
		int i=n-1,ld=-1;
		while(i>=0){
			if(arr[i][j]=='o') ld=-1;
			if(arr[i][j]=='.' && ld==-1) ld=i;

			if(ld!=-1 && arr[i][j]=='*'){
				arr[i][j]='.';
				arr[ld][j]='*';
				i=ld; ld=-1;
			}
			i--;
		}
	}

	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}