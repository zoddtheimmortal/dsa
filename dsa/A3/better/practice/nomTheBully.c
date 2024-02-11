#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	int ans=1;
	for(int i=0;i<n;i++){
		int si=i,ei=i+1;
		while(si>=0 && ei<n){
			if(arr[si]!=arr[ei]) break;
			ans=max(ans,ei-si+1);
			si--; ei++;
		}

		si=i-1,ei=i+1;
		while(si>=0 && ei<n){
			if(arr[si]!=arr[ei]) break;
			ans=max(ans,ei-si+1);
			si--; ei++;
		}
	}

	printf("%d\n",ans);

	free(arr);
}