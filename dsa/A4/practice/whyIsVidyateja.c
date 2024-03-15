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
			char x; scanf("%c",&x);
			if(x!='\n') arr[i][j]=x;
			else j--;
		}
	}

	for(int j=0;j<m;j++){
		int dot=n-1,cross=n-1;
		while(dot>=0 && cross>=0){
			while(dot>=0 && arr[dot][j]!='.') dot--;
			while(cross>=0 && arr[cross][j]!='*'){
				if(arr[cross][j]=='o') dot=cross;
				cross--;
			}

			if(cross<dot && arr[cross][j]=='*' && arr[dot][j]=='.'){
				arr[cross][j]='.';
				arr[dot][j]='*';
				dot--; cross--;
			}else if(cross>=dot) cross--;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) printf("%c",arr[i][j]);
		printf("\n");
	}
}