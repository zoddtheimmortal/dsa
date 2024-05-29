#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e5)
#define MOD ((unsigned int)1e9+7)
	
int n,m;
int arr[MAX_N][MAX_N]={0},visited[MAX_N]={0};

void dfs(int x){
	visited[x]=1;
	for(int y=0;y<n;y++){
		if(arr[x][y]!=0&&!visited[y]) dfs(y);
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int f,s; scanf("%d %d",&f,&s);
		arr[--f][--s]=1;
		arr[s][f]=1;
	}

	int ans=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}

	printf("%d\n",ans);
}