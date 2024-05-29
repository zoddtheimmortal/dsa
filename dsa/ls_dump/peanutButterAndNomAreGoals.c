#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int stack[MAX_N],top=-1;

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int great[n],less[n];
	for(int i=n-1;i>=0;i--){
		while(top>=0&&arr[stack[top]]<=arr[i]) top--;
		great[i]=(top>=0?stack[top]-i:0);
		stack[++top]=i;
	}

	top=-1;
	for(int i=n-1;i>=0;i--){
		while(top>=0&&arr[stack[top]]>=arr[i]) top--;
		less[i]=(top>=0?stack[top]-i:0);
		stack[++top]=i;
	}

	for(int i=0;i<n;i++) printf("%d ",great[i]);
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",less[i]);
	printf("\n");
}