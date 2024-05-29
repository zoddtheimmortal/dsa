/** 
 immortalzodd
 25.05.2024 20:01:22
 dzyLovesStrings
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
    string s; cin>>s;
    ll n; cin>>n;
    vi weights(26,0); for(int&x:weights) cin>>x;
    ll ans=0;
    fr(i,0,s.size()){
    	ans+=((i+1)*weights[s[i]-'a']);
    }
    sort(all(weights)); ll p=weights[25];
    fr(i,s.size(),s.size()+n) ans+=((i+1)*p);
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