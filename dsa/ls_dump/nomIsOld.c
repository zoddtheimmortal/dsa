#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)
	
int n;
int arr[MAX_N][MAX_N]={0},dist[MAX_N]={0};

int dfs(int x,int p,int d){
	dist[x]=d;
	int opt=-1;
	for(int y=0;y<n;y++){
		if(y!=p&&arr[x][y]==1){
			int z=dfs(y,x,d+1);
			if(opt==-1||dist[z]>dist[opt]) opt=z;
		}
	}

	return (opt==-1?x:opt);
}

int main(){
	scanf("%d",&n);
	n++;
	for(int i=0;i<n-1;i++){
		int f,s; scanf("%d %d",&f,&s);
		arr[f][s]=1;
		arr[s][f]=1;
	}

	int u=dfs(0,0,0);
	int v=dfs(u,u,0);

	printf("%d\n",dist[v]+1);
}