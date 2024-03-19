/** 
 immortalZodd
 18.02.2024 23:22:05
 divisiblePairs
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
    ll n,x,y; cin>>n>>x>>y;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    map<pair<ll,ll>,ll> mp;

    ll ans=0;
    for(auto &i:arr){
    	ll mod_x=i%x,mod_y=i%y;
    	ans+=(mp[make_pair(((x-mod_x)%x),mod_y)]);
    	mp[make_pair(mod_x,mod_y)]++;
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}