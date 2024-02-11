/**
 immortalZodd
 20.01.2024 16:50:33
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
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    ll n,k,b; cin>>n>>k>>b;
    vi dmg(n+1,0),arr(n,0);
    fr(i,0,b){
    	ll x; cin>>x;
    	arr[x-1]=1;
    }
    fr(i,0,n){
    	dmg[i+1]=dmg[i]+arr[i];
    }
    int ans=INT_MAX;
    fr(i,0,n){
    	if(i+k-1<n){
    		ans=min(ans,dmg[i+k]-dmg[i+1]);
    	}
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}