#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,m; scanf("%d %d",&n,&m);
	char arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char x; scanf("%c",&x);
			if(x!='\n') arr[i][j]=x;
			else j--;
		}
	}

	for(int j=0;j<m;j++){
		int dot=n-1,ex=n-1;
		while(dot>=0 && ex>=0){
			while(dot>=0 && arr[dot][j]!='.') dot--;
			while(ex>=0 && arr[ex][j]!='*'){
				if(arr[ex][j]=='o') dot=ex;
				ex--;
			}

			if(dot>ex && arr[dot][j]=='.' && arr[ex][j]=='*'){
				arr[dot][j]='*';
				arr[ex][j]='.';
				dot--; ex--;
			}else if(dot<=ex) ex--;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) printf("%c",arr[i][j]);
		printf("\n");
	}
}