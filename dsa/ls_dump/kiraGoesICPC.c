#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n,m;
int arr[MAX_N][MAX_N]={0},visited[MAX_N]={0};

typedef struct edge{
	int w;
	int to;
} edge;

int prim(int n){
	int weight=0;
	edge* minedge=(edge*)malloc(sizeof(edge)*n);
	for(int i=0;i<n;i++){
		minedge[i].w=INT_MAX;
		minedge[i].to=-1;
	}
	minedge[0].w=0;

	for(int i=0;i<n-1;i++){
		int v=-1;

		for(int u=0;u<n;u++){
			if(!visited[u]&&(v==-1||minedge[u].w<minedge[v].w)) v=u;
		}
		if(minedge[v].w==INT_MAX) return -1;

		visited[v]=1;
		weight+=minedge[v].w;

		for(int u=0;u<n;u++){
			if(arr[v][u]<minedge[u].w){
				minedge[u]=(edge){arr[v][u],v};
			}
		}
	}

	return weight;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) arr[i][j]=INT_MAX;
	}

	for(int i=0;i<n;i++){
		int f,s,w; scanf("%d %d %d",&f,&s,&w);
		arr[--f][--s]=w;
		arr[s][f]=w;
	}

	int ans=prim(n-1);
	printf("%d\n",ans);
}