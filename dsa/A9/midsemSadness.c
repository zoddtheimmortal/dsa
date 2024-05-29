#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int n;
int arr[MAX_N][MAX_N],visited[MAX_N],weight[MAX_N];

int dfs(int x){
	visited[x]=1;
	int wt=weight[x],left=0,right=0;
	for(int i=0;i<n;i++){
		if(arr[x][i]!=0&&!visited[i]){
			int step=dfs(i);
			left=max(left,step);
			break;
		};
	}
	for(int i=0;i<n;i++){
		if(arr[x][i]!=0&&!visited[i]){
			int step=dfs(i);
			right=max(right,step);
			break;
		};
	}
	if(x==0) return wt+left+right;
	return wt+max(left,right);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) arr[i][j]=0;
	}
	for(int i=0;i<n;i++){
		int x,y=-1; scanf("%d",&x);
		weight[i]=x;
		if(i-1>=0&&(i-1)%2==0){
			y=(i-1)/2;
		}
		if(i-2>=0&&(i-2)%2==0){
			y=(i-2)/2;
		}
		if(x==-1||y==-1) continue;
		arr[y][i]=1;
	}

	for(int i=0;i<n;i++) visited[i]=0;
	int ans=dfs(0);

	printf("%d\n",ans);
}