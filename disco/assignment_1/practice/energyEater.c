#include<stdio.h>
#define ll long long
#define max(a,b) ((a)>(b))?(a):(b)

int main(){
    int n; scanf("%d",&n);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int k; scanf("%d",&k);

    int si=0,ei=0;
    int sum=0,len=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ei+=1;
        while(sum>k){
            sum-=arr[si++];
        }
        len=max(len,ei-si);
    }
    printf("%d\n",len);
}