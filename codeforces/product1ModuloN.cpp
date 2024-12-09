/** 
 immortalzodd
 25.08.2024 22:04:49
 product1ModuloN
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
    ll n; cin>>n;

    vl coprimes;
    fr(i,1,n){
    	if(gcd(n,i)==1) coprimes.push_back(i);
    }

    int csize=coprimes.size();
    vl prefix_mod(csize);
    prefix_mod[0]=1;

    fr(i,1,csize){
    	prefix_mod[i]=(prefix_mod[i-1]*coprimes[i])%n;
    }

    ll mlen=1;
    fr(i,0,csize){
    	if(prefix_mod[i]==1) mlen=i+1;
    }

    cout<<mlen<<nL;
    fr(i,0,mlen){
    	cout<<coprimes[i]<<" ";
    }
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}