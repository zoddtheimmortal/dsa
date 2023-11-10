#include<stdio.h>
#define ll long long
#define max(a,b) (a)>(b)?(a):(b)

int main(){
    int n; scanf("%d",&n);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    int k; scanf("%d",&k);
    ll ans=0,tempMax=0,sum=0,flag=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i]<=k){
            sum+=arr[i];
            tempMax++;
        }
        else{
            sum=0;
            tempMax=0;
        }
        ans=max(tempMax,ans);
    }
    printf("%d\n",ans);
}