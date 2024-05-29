/** 
 immortalzodd
 12.04.2024 15:27:52
 rangeXorQueries
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

void solve(){
    ll n,q; cin>>n>>q;
    vi prefix(n+1,0),arr(n);
    for(auto&x:arr) cin>>x;
    fr(i,0,n){
    	prefix[i+1]=prefix[i]^arr[i];
    }

    while(q--){
    	ll f,s; cin>>f>>s;
    	cout<<(prefix[s]^prefix[f-1])<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}