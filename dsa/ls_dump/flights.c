#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,m;
int arr[MAX_N][MAX_N]={0},dist[MAX_N]={0},visited[MAX_N]={0};

void djikstra(int src){
	for(int i=0;i<n;i++) dist[i]=INT_MAX;
	dist[src]=0;
	for(int i=0;i<n;i++){
		int v=-1;
		for(int u=0;u<n;u++){
			if(!visited[u]&&(v==-1||dist[u]<dist[v])) v=u;
		}
		if(dist[v]==INT_MAX) break;

		visited[v]=1;
		for(int u=0;u<n;u++){
			if(arr[v][u]!=INT_MAX&&dist[u]>dist[v]+arr[v][u]){
				dist[u]=dist[v]+arr[v][u];
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) arr[i][j]=INT_MAX;
	}

	for(int i=0;i<m;i++){
		int f,s,w; scanf("%d %d %d",&f,&s,&w);
		--f,--s;
		if(arr[f][s]>w) arr[f][s]=w;
	}

	djikstra(0);

	for(int i=0;i<n;i++) printf("%d ",dist[i]);
	printf("\n");
}