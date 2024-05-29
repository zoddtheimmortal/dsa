#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n; scanf("%d",&n);
	int arr[n],a[n],b[n];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int stack[MAX_N],top=-1;
	for(int i=n-1;i>=0;i--){
		while(top>=0&&arr[i]<=arr[stack[top]]) top--;
		b[i]=((top<0)?0:(stack[top]-i));
		stack[++top]=i;
	}

	top=-1;
	for(int i=n-1;i>=0;i--){
		while(top>=0&&arr[i]>=arr[stack[top]]) top--;
		a[i]=((top<0)?0:(stack[top]-i));
		stack[++top]=i;
	}

	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");

	for(int i=0;i<n;i++) printf("%d ",b[i]);
	printf("\n");
}