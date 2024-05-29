#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int arr[MAX_N][MAX_N],weight[MAX_N],visited[MAX_N];
int n,k;

int dfs(int x,int depth){
	visited[x]=1;
	int ans=0,flag=0;
	for(int i=0;i<n;i++){
		if(arr[x][i]!=0&&!visited[i]){
			int temp=dfs(i,depth+1);
			ans=max(ans,temp);
			flag=1;
		}
	}
	if(flag==0) return depth;
	return ans;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&weight[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) arr[i][j]=0;
	}

	for(int i=0;i<n;i++){
		int x=weight[i],y=-1;
		if(i-1>=0&&(i-1)%2==0){
			y=(i-1)/2;
		}
		if(i-2>=0&&(i-2)%2==0){
			y=(i-2)/2;
		}
		if(x<0||y<0) continue;
		arr[y][i]=1;
	}
	int rm=-1;
	for(int i=0;i<n;i++){
		if(weight[i]==k){
			rm=i; break;
		}
	}
	for(int i=0;i<n;i++) visited[i]=0;

	dfs(rm,0);
	int ans=dfs(0,0);
	printf("%d\n",ans+1);
}