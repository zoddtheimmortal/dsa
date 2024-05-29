#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int arr[MAX_N][MAX_N]={0},dist[MAX_N]={0},weight[MAX_N]={0};
int n;

int dfs(int x,int p,int d){
	dist[x]=d;
	int opt=-1;
	for(int y=0;y<n;y++){
		if(arr[x][y]!=0&&y!=p){
			int z=dfs(y,x,d+1);
			if(opt==-1||dist[z]>dist[opt]) opt=z;
		}
	}
	return (opt==-1?x:opt);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&weight[i]);

	for(int i=0;i<n;i++){
		int x=weight[i],y=-1;
		if(i-1>=0&&(i-1)%2==0){
			y=(i-1)/2;
		}
		if(i-2>=0&&(i-2)%2==0){
			y=(i-2)/2;
		}

		if(x==-1||y==-1) continue;
		arr[y][i]=arr[i][y]=1;
	}

	int u=dfs(0,0,0);
	for(int i=0;i<n;i++) dist[i]=0;
	int v=dfs(u,u,0);
	printf("%d\n",dist[v]);
}