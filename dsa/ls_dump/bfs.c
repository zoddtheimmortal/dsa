#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

#define S 0

int n,m;
int arr[MAX_N][MAX_N]={0},visited[MAX_N]={0};

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int f,s; scanf("%d %d",&f,&s);
		arr[--f][--s]=1;
		arr[s][f]=1;
	}

	int queue[MAX_N],tail=-1,head=0;
	queue[++tail]=S; visited[S]=1;

	while(tail>=head){
		int v=queue[head++];
		printf("%d ",v);
		for(int i=0;i<n;i++){
			if(!visited[i]&&arr[v][i]!=0){
				queue[++tail]=i;
				visited[i]=1;
			}
		}
	}
	printf("\n");
}