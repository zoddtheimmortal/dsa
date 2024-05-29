#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

#define S 0

typedef struct edge{
	int a,b,w;
} edge;

int n,m;
edge arr[MAX_N];
int dist[MAX_N]={0},parent[MAX_N]={0};

void bellman(int src){
	for(int i=0;i<n;i++) dist[i]=INT_MAX;
	dist[src]=0;
	int last_node=-1;

	for(int i=0;i<n;i++){
		last_node=-1;
		for(int j=0;j<m;j++){
			edge e=arr[j];
			if(dist[e.a]!=INT_MAX&&dist[e.a]+e.w<dist[e.b]){
				dist[e.b]=dist[e.a]+e.w;
				parent[e.b]=e.a;
				last_node=e.b;
			}
		}
	}
	if(last_node==-1) printf("NO\n");
	else{
		int cycle[m+1],k=0;
		for(int i=0;i<n-1;i++) last_node=parent[last_node];
		for(int x=last_node;;x=parent[x]){
			cycle[k++]=x;
			if(x==last_node&&k>1) break;
		}

		printf("YES\n");
		for(int i=k-1;i>=0;i--) printf("%d ",cycle[i]+1);
		printf("\n");
	}
}

int main(){
	scanf("%d %d",&n,&m);
	m*=2;
	for(int i=0;i<m;i++){
		int f,s,w; scanf("%d %d %d",&f,&s,&w);
		arr[i]=(edge){--f,--s,w};
		arr[i++]=(edge){s,f,w};
	}

	bellman(S);
	for(int i=0;i<n;i++) printf("%d ",dist[i]);
	printf("\n");
}