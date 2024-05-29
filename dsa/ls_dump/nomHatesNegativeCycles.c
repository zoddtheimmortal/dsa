#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)5001)
#define MOD ((unsigned int)1e9+7)

typedef struct edge{
	int from,to,w;
} edge;

int n,m;
edge arr[MAX_N];
int parent[MAX_N]={0},dist[MAX_N]={0};

void bellmanford(int src){
	for(int i=0;i<n+2;i++) dist[i]=INT_MAX;
	dist[src]=0;
	int last_node=-1;
	for(int i=0;i<n;i++){
		last_node=-1;
		for(int j=0;j<m;j++){
			edge e=arr[j];
			if(dist[e.from]!=INT_MAX&&dist[e.to]>dist[e.from]+e.w){
				dist[e.to]=dist[e.from]+e.w;
				parent[e.to]=e.from;
				last_node=e.to;
			}
		}
	}

	if(last_node==-1) printf("NO\n");
	else{
		int cycle[n+1],k=0;
		for(int i=0;i<n-1;i++){
			last_node=parent[last_node];
		}
		for(int x=last_node;;x=parent[x]){
			cycle[k++]=x;
			if(x==last_node&&k>1) break;
		}

		printf("YES\n");
		for(int i=k-1;i>=0;i--) printf("%d ",cycle[i]);
		printf("\n");
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int f,s,w; scanf("%d %d %d",&f,&s,&w);
		arr[i]=(edge){f,s,w};
	}

	bellmanford(1);
	for(int i=0;i<n;i++) printf("%d ",dist[i+1]);
	printf("\n");
}