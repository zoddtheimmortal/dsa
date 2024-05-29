#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_N (unsigned int)1e6
#define max(a,b) ((a>b)?a:b)

typedef struct pair{
	int f,s;
} pair;

int main(){
	int n; scanf("%d",&n);
	int arr[n],top=-1;
	pair stack[MAX_N];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int ans=0;
	for(int i=0;i<n;i++){
		int start=i;
		while(top>=0&&arr[i]<stack[top].s){
			pair cur=stack[top];
			start=cur.f;
			ans=max(ans,(i-cur.f)*cur.s);
			top--;
		}	
		stack[++top]=(pair){start,arr[i]};
	}
	while(top>=0){
		pair cur=stack[top];
		ans=max(ans,(n-cur.f)*cur.s);
		top--;
	}

	printf("%d\n",ans);
}