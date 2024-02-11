#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d",&n);
	int arr[n][n];
	int top=0,btm=n-1,left=0,right=n-1,k=1,flag=1;

	while(k<=n*n){
		if(flag==1){
			for(int i=left;i<=right;i++){
				arr[top][i]=k++;
			}
			top++; flag=2;
		}
		if(flag==2){
			for(int i=top;i<=btm;i++){
				arr[i][right]=k++;
			}
			right--; flag=3;
		}
		if(flag==3){
			for(int i=right;i>=left;i--){
				arr[btm][i]=k++;
			}
			btm--; flag=4;
		}
		if(flag==4){
			for(int i=btm;i>=top;i--){
				arr[i][left]=k++;
			}
			left++; flag=1;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf("%d ",arr[i][j]);
		printf("\n");
	}
}