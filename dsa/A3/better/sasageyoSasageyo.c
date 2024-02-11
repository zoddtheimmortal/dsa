#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	int visited[256]; for(int i=0;i<n;i++) visited[i]=0;

	int si=0,ei=0,ans=0,check=0;
	while(si<n && ei<n){
		if(visited[arr[ei]]==1){
			while(visited[arr[ei]]==1){
				visited[arr[si]]=0;
				si++;
			}
		}

		visited[arr[ei]]=1;
		ans=max(ans,(ei-si+1));
		ei++;
	}

	printf("%d\n",ans);
	free(arr);
}