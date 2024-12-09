/** 
 immortalzodd
 03.06.2024 19:57:40
 A
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
    string s; cin>>s;
    map<char,int> mp;
    for(char&c:s) mp[c]++;
    ll ans=0;
	string k="ABCDEFG";
	for(char&c:k) ans+=max(0LL,m-mp[c]);
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