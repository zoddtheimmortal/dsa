#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

typedef struct pair{
	int f,s;
} pair;

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	pair stack[MAX_N];
	int top=-1,ans=0;

	for(int i=0;i<n;i++){
		int start=i;
		while(top>=0&&arr[i]<=stack[top].s){
			pair cur=stack[top];
			start=cur.f;
			ans=max(ans,cur.s*(i-cur.f));
			top--;
		}
		stack[++top]=(pair){start,arr[i]};
	}

	while(top>=0){
		pair cur=stack[top];
		ans=max(ans,cur.s*(n-cur.f));
		top--;
	}

	printf("%d\n",ans);
}