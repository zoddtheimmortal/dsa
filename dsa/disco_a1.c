#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e5)
#define MOD ((unsigned int)1e9+7)

int n,m;
int arr[MAX_N][MAX_N]={0},indeg[MAX_N]={0};
int tail=-1,head=0,queue[MAX_N];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int f,s; scanf("%d %d",&f,&s);
		arr[f-1][s-1]=1;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) indeg[j]+=(arr[i][j]==1);
	}
	
	for(int i=0;i<n;i++){
		if(indeg[i]==0) queue[++tail]=i;
	}

	int rounds=0;
	while(tail>=head){
		int sz=tail-head+1;
		rounds++;
		for(int i=0;i<sz;i++){
			int v=queue[head++];
			printf("%d ",v+1);
			for(int i=0;i<n;i++){
				if(arr[v][i]!=0){
					indeg[i]--;
					if(indeg[i]==0) queue[++tail]=i;
				}
			}
		}
		printf("| ");
	}

	printf("Rounds: %d\n",rounds);
}