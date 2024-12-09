/** 
 immortalzodd
 06.06.2024 17:12:43
 frogJumps
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
    vi pos={0};
    fr(i,0,s.size()) if(s[i]=='R') pos.push_back(i+1);
    pos.push_back(s.size()+1);
    int ans=0,n=pos.size();
    fr(i,1,n) ans=max(ans,pos[i]-pos[i-1]);
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