#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n,q; scanf("%d %d",&n,&q);
	int arr[n+1][n+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) scanf("%d",&arr[i+1][j+1]);
	}
	
	int prefix[n+1][n+1];
	for(int i=0;i<n+1;i++) prefix[i][0]=0;
	for(int i=0;i<n+1;i++) prefix[0][i]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			prefix[i][j]=arr[i][j]+prefix[i-1][j]+
			prefix[i][j-1]-prefix[i-1][j-1];
		}
	}

	while(q--){
		int a,b,A,B; 
		scanf("%d %d %d %d",&a,&b,&A,&B);
		int ans=prefix[A][B]-prefix[a-1][B]-prefix[A][b-1]+prefix[a-1][b-1];
		printf("%d\n",ans);
	}
}