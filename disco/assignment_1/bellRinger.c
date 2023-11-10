#include<stdio.h>
#define ll long long

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int n; scanf("%d", &n);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    ll ans=arr[0];
    for(int i=1;i<n;i++){
        ans=((arr[i]*ans)/gcd(arr[i],ans));
    }

    printf("%lld",ans);
}