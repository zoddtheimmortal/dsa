#include<stdio.h>
#define max(a,b) ((a)>(b))?(a):(b)

int main(){
    int n; scanf("%d",&n);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int k; scanf("%d",&k);

    int si=0,ei=0,len=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ei++;
        while(sum>k){
            sum-=arr[si++];
        }
        len=max(len,ei-si);
    }
    printf("%d\n",len);
}