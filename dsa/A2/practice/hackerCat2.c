#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	freopen("hackerCat2.out","w",stdout);
	int n; scanf("%d",&n);
	int arr[n][n];
	int top=0,bottom=n-1,left=0,right=n-1,k=1;
	int flag=1;
	while(k<=n*n){
		if(flag==1){
			for(int j=left;j<=right;j++){
				arr[top][j]=k++;
			}
			top++;
			flag=2;
		}
		if(flag==2){
			for(int i=top;i<=bottom;i++){
				arr[i][right]=k++;
			}
			right--;
			flag=3;
		}
		if(flag==3){
			for(int j=right;j>=left;j--){
				arr[bottom][j]=k++;
			}
			bottom--;
			flag=4;
		}
		if(flag==4){
			for(int i=bottom;i>=top;i--){
				arr[i][left]=k++;
			}
			left++;
			flag=1;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}