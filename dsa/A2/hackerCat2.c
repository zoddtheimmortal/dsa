#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d",&n);
	int arr[n][n];

	int r=0,c=0,i=0,flag=0,k=n;

	while(i<n*n){
		if(i%(k)==0){
			flag=(flag+1)%4;
			if(flag==3) k-=2;
		}
		if(flag==0){
			arr[r][c++]=(i+1);
		}
		if(flag==1){
			arr[r++][c]=(i+1);
		}
		if(flag==2){
			arr[r][c--]=(i+1);
		}
		if(flag==3){
			arr[r--][c]=(i+1);
		}
		i++;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}