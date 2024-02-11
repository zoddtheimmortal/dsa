#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 9
int arr[N][N];

int check(int r,int c,int k){
	for(int i=0;i<=8;i++){
		if(arr[i][c]==k) return 0;
	}

	for(int i=0;i<=8;i++){
		if(arr[r][i]==k) return 0;
	}

	int sr=r-(r%3),sc=c-(c%3);

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i+sr][j+sc]==k) return 0;
		}
	}
	return 1;
}

int solve_sudoku(int r,int c){
	if(r==N-1 && c==N) return 1;

	if(c==N) r++,c=0;

	if(arr[r][c]!=-1) return solve_sudoku(r,c+1);

	for(int i=1;i<=N;i++){
		if(check(r,c,i)==1){
			arr[r][c]=i;
			if(solve_sudoku(r,c+1)==1) return 1;
		}
		arr[r][c]=-1;
	}
	return 0;
}

int main(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) scanf("%d",&arr[i][j]);
	}

	int k=solve_sudoku(0,0);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) printf("%d ",arr[i][j]);
		printf("\n");
	}
}