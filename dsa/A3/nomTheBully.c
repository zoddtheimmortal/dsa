#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%s",arr);

	int ans=0;
	for(int i=0;i<n;i++){
		int si=i,ei=n-1;
		while(arr[ei]!=arr[si]) ei--;
		int temp=ei-si+1;
		while(si<ei){
			if(arr[si]==arr[ei]){
				si++; ei--;
			}
			else{
				ei--;
				temp=ei-si+1;
			}
		}
		ans=max(ans,temp);
	}

	free(arr);
	printf("%d\n",ans);
}