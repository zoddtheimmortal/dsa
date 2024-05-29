#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_N (unsigned int)1e6
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MOD ((unsigned int)1e9+7)

int main(){
    int n; scanf("%d",&n);
    int arr[n],stack[MAX_N],top=-1;
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int left[n],right[n];
    for(int i=0;i<n;i++){
        while(top>=0&&arr[i]<arr[stack[top]]) top--;
        left[i]=(top==-1?-1:stack[top]);

        stack[++top]=i;
    }
    top=-1;

    for(int i=n-1;i>=0;i--){
        while(top>=0&&arr[i]<=arr[stack[top]]) top--;
        right[i]=(top==-1?n:stack[top]);

        stack[++top]=i;
    }

    long long sum=0;
    for(int i=0;i<n;i++) sum=(sum+arr[i]*(right[i]-i)*(i-left[i]))%MOD;
    printf("%lld\n",sum);
}