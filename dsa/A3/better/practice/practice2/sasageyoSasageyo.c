#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	int si=0,ei=0,ans=0;
	int visited[256]; for(int i=0;i<256;i++) visited[i]=0;
	while(si<n && ei<n){
		while(visited[arr[ei]]){
			visited[arr[si]]=0;
			si++;
		}

		ans=max(ans,ei-si+1);
		visited[arr[ei++]]=1;
	}

	printf("%d\n",ans);

	free(arr);
}