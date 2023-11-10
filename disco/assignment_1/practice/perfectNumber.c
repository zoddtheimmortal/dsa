#include<stdio.h>
#define ll long long
int main(){
    ll n; scanf("%lld",&n);
    ll sum=0;
    for(int i=1;i<n+1;i++){
        sum=0;
        for(int j=1;j<i;j++){
            if(i%j==0) sum+=j;
        }
        if(sum==i) printf("%d ",i);
    }
    printf("\n");
}