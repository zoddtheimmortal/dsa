/** 
 immortalzodd
 29.05.2024 22:23:22
 fedorAndNewGame
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
    ll n,m,k; cin>>n>>m>>k;
    vi soldiers(m,0); for(int&x:soldiers) cin>>x;
    int fedor; cin>>fedor;
    int ans=0;
    fr(i,0,m){
    	int mask=(fedor^soldiers[i]),hits=0;
    	fr(p,0,n){
    		if(mask&(1<<p)) hits++;
    	}
    	if(hits<=k) ans++;
    }
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