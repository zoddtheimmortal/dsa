/** 
 immortalzodd
 17.07.2024 17:05:58
 manyReplacement
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
    ll q; cin>>q;

    string from,to;
    from=to="abcdefghijklmnopqrstuvwxyz";

    while(q--){
    	char c,d; cin>>c>>d;
    	for(char&m:to){
    		if(m==c) m=d;
    	}
    }

    for(char&c:s){
    	fr(i,0,26){
    		if(c==from[i]) cout<<to[i];
    	}
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