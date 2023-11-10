#include<stdio.h>

int gcd(int a,int b){
    if(b==0) return a;
    gcd(b,a%b);
}

int main(){
    int n; scanf("%d",&n);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int ans=arr[0];

    for(int i=1;i<n;i++){
        ans=(ans*arr[i])/gcd(ans,arr[i]);
    }

    printf("%d\n",ans);
}