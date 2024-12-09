/** 
 immortalzodd
 25.08.2024 18:10:47
 divGame
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

void solve(){
    ll n; cin>>n;
    ll ans=0;

    for(ll p=2;p*p<=n;p++){
    	ll exp=0;
    	while(n%p==0){
    		n/=p;
    		exp++;
    	}

    	for(ll i=1;exp-i>=0;i++){
    		ans++;
    		exp-=i;
    	}
    }
    if(n>1) ans+=1;
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}