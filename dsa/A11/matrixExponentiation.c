#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)

int n=0,p=0;
const unsigned int MOD=1e9+7;

int** mult(int** a,int** b){
	int** ans=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++) ans[i]=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans[i][j]=0;
			for(int k=0;k<n;k++){
				ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j]))%MOD;
			}
		}
	}
	return ans;
}

int** recur(int** mat,int p){
	printf("%d\n",p);
	if(p==1) return mat;
	int** half=recur(mat,p/2);
	int** ans=mult(half,half);
	if(p%2==0) return ans;
	return mult(ans,half);
}

int main(){
	scanf("%d %d",&n,&p);
	int** mat=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++) mat[i]=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) scanf("%d",&mat[i][j]);
	}
	mat=recur(mat,p);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf("%d ",mat[i][j]);
		printf("\n");
	}
}