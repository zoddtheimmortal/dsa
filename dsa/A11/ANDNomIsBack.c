#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int si,ei; scanf("%d %d",&si,&ei);
	int ans=INT_MAX,temp=0;
	for(int mask=1;mask<(1<<30);mask*=2){
		temp=0;
		for(int i=si;i<=ei;i++){
			if((mask&i)==0) temp++;
		}
		ans=min(ans,temp);
	}
	printf("%d\n",ans);
}