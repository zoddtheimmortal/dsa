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
		arr[--f][--s]=1;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) indeg[j]+=(arr[i][j]==1);
	}
	
	for(int i=0;i<n;i++){
		if(indeg[i]==0) queue[++tail]=i;
	}

	int topsort[n],k=0;
	while(tail>=head){
		int v=queue[head++];
		topsort[k++]=v;
		for(int i=0;i<n;i++){
			if(arr[v][i]!=0){
				indeg[i]--;
				if(indeg[i]==0) queue[++tail]=i;
			}
		}
	}

	if(k<n) printf("IMPOSSIBLE\n");
	else{
		for(int i=0;i<k;i++) printf("%d ",topsort[i]+1);
		printf("\n");
	}
}