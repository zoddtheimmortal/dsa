/** 
 immortalzodd
 25.05.2024 20:27:42
 lecture
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
    ll n,m; cin>>n>>m;
    map<string,string> mp;
    fr(i,0,m){
    	string a,b,c; cin>>a>>b;
    	if(a.size()<=b.size()) c=a;
    	else c=b;
    	mp[a]=c; mp[b]=c;
    }
    vector<string> arr(n,""); for(string&s:arr) cin>>s;
    for(string&s:arr) cout<<mp[s]<<" ";
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