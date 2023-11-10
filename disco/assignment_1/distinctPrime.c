#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define ll long long
#define N 1000000

int primes[N]={0};
void Sieve(ll n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    int k=0;
    for(int p=2;p<=n;p++){
        if(prime[p]){
            primes[k++]=p;
        }
    }
}

int main(){
    Sieve(N);
    int n; scanf("%d",&n);
    ll ans=1;
    for(int i=0;primes[i]<=n;i++){
        if(n%(primes[i])==0) ans*=primes[i];
    }
    printf("%lld",ans);
}