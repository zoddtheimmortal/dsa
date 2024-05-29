#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n; scanf("%d",&n);
	char arr[n]; scanf("%s",arr);

	int ans=0,si=0,ei=0;
	for(int i=0;i<n;i++){
		si=i-1,ei=i+1;
		while(si>=0&&ei<n&&arr[si]==arr[ei]){
			ans=max(ans,ei-si+1);
			si--,ei++;
		}

		si=i,ei=i+1;
		while(si>=0&&ei<n&&arr[si]==arr[ei]){
			ans=max(ans,ei-si+1);
			si--; ei++;
		}
	}

	printf("%d\n",ans);
}