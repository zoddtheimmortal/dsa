#include<stdio.h>
#define ll long long
#define N 1000000

int prime[N+1];
void sieve(int n){
    for(int i=0;i<=N;i++) prime[i]=1;
    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=0;
            }
        }
    }
}

int main(){
    int n; scanf("%d",&n);
    sieve(n);
    int ans=1;
    for(int i=2;i<=n;i++){
        if(prime[i]&&n%i==0){
            ans*=i;
        }
    }
    printf("%d\n",ans);
}