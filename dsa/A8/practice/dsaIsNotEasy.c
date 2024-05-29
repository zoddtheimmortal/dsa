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
	int arr[n],left[n],right[n]; 
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	for(int i=0;i<n;i++){
		while(top>=0&&arr[i]<=arr[stack[top]]) top--;
		left[i]=((top<0)?-1:stack[top]);
		stack[++top]=i;
	}

	top=-1;
	for(int i=n-1;i>=0;i--){
		while(top>=0&&arr[i]<=arr[stack[top]]) top--;
		right[i]=((top<0)?n:stack[top]);
		stack[++top]=i;
	}

	long long sum=0;
	for(int i=0;i<n;i++){
		sum=(sum+(arr[i]*(i-left[i])*(right[i]-i)))%MOD;
	}
	printf("%lld\n",sum);
}