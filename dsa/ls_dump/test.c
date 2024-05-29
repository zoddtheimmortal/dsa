#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,m;
int arr[MAX_N][MAX_N]={0},visited[MAX_N][MAX_N]={0};

void flood_fill(int r,int c){
	if(r<0||r>=n||c<0||c>=n||visited[r][c]==1||arr[r][c]!=1) return;

	visited[r][c]=1;
	flood_fill(r-1,c);
	flood_fill(r,c-1);
	flood_fill(r+1,c);
	flood_fill(r,c+1);
}


int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]&&arr[i][j]==1){
				flood_fill(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}