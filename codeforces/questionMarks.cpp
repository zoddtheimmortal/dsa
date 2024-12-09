/** 
 immortalzodd
 07.08.2024 21:40:11
 questionMarks
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
    string s; cin>>s;

    unordered_map<char,int> mp;
    for(char&c:s){
    	if(c=='?') continue;
    	mp[c]++;
    }

    ll ans=0;	
    for(auto[c,val]:mp) ans+=min<ll>(n,val);
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}